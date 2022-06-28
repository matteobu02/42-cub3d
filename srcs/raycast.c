/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycast.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lyaiche <lyaiche@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/13 15:50:31 by lyaiche           #+#    #+#             */
/*   Updated: 2022/06/28 17:17:54 by lyaiche          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	init_values(t_data *data, t_raycast *raycast)
{
	raycast->dirx = cos((raycast->ra));
	raycast->diry = -sin((raycast->ra));
	raycast->ray_step_x = sqrtf(1.0 + ((raycast->diry
					/ raycast->dirx) * (raycast->diry / raycast->dirx)));
	raycast->ray_step_y = sqrtf(1.0 + ((raycast->dirx
					/ raycast->diry) * (raycast->dirx / raycast->diry)));
	raycast->raystart_x = data->px;
	raycast->raystart_y = data->py;
	raycast->raymap_x = (int)data->px;
	raycast->raymap_y = (int)data->py;
	raycast->walldist = 0;
	if (data->width < data->height)
			raycast->maxdistance = data->height;
	else
			raycast->maxdistance = data->width;
	raycast->found = 0;
}

void	start_raycast(t_raycast *raycast)
{
	if (raycast->dirx < 0)
	{
		raycast->step_x = -1;
		raycast->lenght_x = (raycast->raystart_x - raycast->raymap_x)
			* raycast->ray_step_x;
	}
	else
	{
		raycast->step_x = 1;
		raycast->lenght_x = ((raycast->raymap_x + 1.0) - raycast->raystart_x)
			* raycast->ray_step_x;
	}
	if (raycast->diry < 0)
	{
		raycast->step_y = -1;
		raycast->lenght_y = (raycast->raystart_y - raycast->raymap_y)
			* raycast->ray_step_y;
	}
	else
	{
		raycast->step_y = 1;
		raycast->lenght_y = ((raycast->raymap_y + 1.0) - raycast->raystart_y)
			* raycast->ray_step_y;
	}
}

void	find_wall(t_data *data, t_raycast *raycast)
{
	while (raycast->found == 0 && raycast->walldist
		< raycast->maxdistance)
	{
		if (raycast->lenght_x < raycast->lenght_y)
		{
			raycast->raymap_x += raycast->step_x;
			raycast->walldist = raycast->lenght_x;
			raycast->lenght_x += raycast->ray_step_x;
			raycast->side = 0;
		}
		else
		{
			raycast->raymap_y += raycast->step_y;
			raycast->walldist = raycast->lenght_y;
			raycast->lenght_y += raycast->ray_step_y;
			raycast->side = 1;
		}
		if (data->map[(int)raycast->raymap_y][(int)raycast->raymap_x] == 1)
		{
			raycast->found = 1;
		}
	}
}

void	init_3d(t_data *data, t_raycast *raycast)
{
	data->interx = raycast->raystart_x + (raycast->dirx
			* raycast->walldist);
	data->intery = raycast->raystart_y + (raycast->diry
			* raycast->walldist);
	data->draw_start = (float)(H / 2) - ((float)H / (raycast->walldist
				* (cos((raycast->rpa - raycast->ra)))) / 2.0);
	data->draw_end = (float)(H / 2) + ((float)H / (raycast->walldist
				* (cos((raycast->rpa - raycast->ra)))) / 2.0);
}

void	raycast(t_data *data)
{
	t_raycast	raycast;

	raycast.r = -1;
	raycast.ra = fixang(data->pa + 30.0);
	raycast.ra = degtorad(raycast.ra);
	raycast.rpa = degtorad(data->pa);
	raycast.tick = 1.0472 / (double)W;
	while (++raycast.r < W -1)
	{
		init_values(data, &raycast);
		start_raycast(&raycast);
		find_wall(data, &raycast);
		init_3d(data, &raycast);
		draw_frame(data, &raycast);
		raycast.ra = raycast.ra - raycast.tick;
	}
}
