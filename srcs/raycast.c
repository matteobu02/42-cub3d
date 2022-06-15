/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycast.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lyaiche <lyaiche@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/13 15:50:31 by lyaiche           #+#    #+#             */
/*   Updated: 2022/06/15 17:36:29 by lyaiche          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	draw3drays(t_data *data)
{
	int	r, found, side, step_x, step_y, i;
	float  raymap_x, raymap_y, ray_step_x, ray_step_y, raystart_x, raystart_y, 
			lenght_x, lenght_y, maxdistance, ra, rpa, dirx, diry, walldist, tick;

	ra = fixang(data->pa + 30.0);
	ra = degtorad(ra);
	rpa = degtorad(data->pa);
	tick = 1.0472 / (double)W;
	for(r = 0; r<W - 1;r++)
	{
		dirx = cos((ra));
		diry = -sin((ra));
		ray_step_x = sqrtf(1.0 + ((diry / dirx) * (diry / dirx)));
		ray_step_y = sqrtf(1.0 + ((dirx / diry) * (dirx / diry)));
		raystart_x = data->px;
		raystart_y = data->py;
		raymap_x = (int)data->px;
		raymap_y = (int)data->py;
		if (dirx < 0)
		{
			step_x = -1;
			lenght_x = (raystart_x - raymap_x) * ray_step_x;
		}
		else
		{
			step_x = 1;
			lenght_x = ((raymap_x + 1.0) - raystart_x) * ray_step_x;
		}
		if (diry < 0)
		{
			step_y = -1;
			lenght_y = (raystart_y - raymap_y) * ray_step_y;
		}
		else
		{
			step_y = 1;
			lenght_y = ((raymap_y + 1.0) - raystart_y) * ray_step_y;
		}
		walldist = 0;
		if (data->width < data->height)
			maxdistance = data->height;
		else
			maxdistance = data->width;
		found = 0;
		while (found == 0 && walldist < maxdistance)
		{
			if (lenght_x < lenght_y)
			{
				raymap_x += step_x;
				walldist = lenght_x;
				lenght_x += ray_step_x;
				side = 0;
			}
			else
			{
				raymap_y += step_y;
				walldist = lenght_y;
				lenght_y += ray_step_y;
				side = 1;
			}
			if (data->map[(int)raymap_y][(int)raymap_x] == 1)
			{
				found = 1;
				data->interx = raystart_x + (dirx * walldist);
				data->intery = raystart_y + (diry * walldist);
			}
		}
		data->draw_start = (float)(H / 2) - ((float)H / (walldist
					* (cos((rpa - ra)))) / 2.0);
		data->draw_end = (float)(H / 2) + ((float)H / (walldist
					* (cos((rpa - ra)))) / 2.0);
		i = -1;
		if (data->draw_start >= 0)
		{
			while (++i < data->draw_start)
				put_pixel(r, i, data->main->map->c, data);
			i = data->draw_end;
			while (i < H)
				put_pixel(r, i++, data->main->map->f, data);
		}
		if (side && cos((ra + 1.5708)) > 0.0)
			vertline(r, side, data, &data->west);
		else if (side)
			vertline(r, side, data, &data->east);
		else if (sin((ra + 1.5708)) > 0.0)
			vertline(r, side, data, &data->south);
		else
			vertline(r, side, data, &data->north);
		ra = ra - tick;
	}
}
