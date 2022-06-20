/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vertline.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucasyaiche <lucasyaiche@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/13 15:54:31 by lyaiche           #+#    #+#             */
/*   Updated: 2022/06/20 03:42:08 by lucasyaiche      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	draw_frame(t_data *data, t_raycast *raycast)
{
	int	i;

	i = -1;
	if (data->draw_start >= 0)
	{
		while (++i < data->draw_start)
			put_pixel(raycast->r, i, data->main->map->c, data);
		i = data->draw_end;
		while (i < H)
			put_pixel(raycast->r, i++, data->main->map->f, data);
	}
	if (raycast->side && cos((raycast->ra + 1.5708)) > 0.0)
		vertline(raycast->r, raycast->side, data, &data->west);
	else if (raycast->side)
		vertline(raycast->r, raycast->side, data, &data->east);
	else if (sin((raycast->ra + 1.5708)) > 0.0)
		vertline(raycast->r, raycast->side, data, &data->south);
	else
		vertline(raycast->r, raycast->side, data, &data->north);
}

void	vertline(int x, int side, t_data *data, t_img *img)
{
	int		color;
	float	y;

	y = data->draw_start;
	if (data->draw_start < 0)
		data->draw_start = 0;
	while (data->draw_start < data->draw_end && data->draw_start < H)
	{	
		if (data->draw_start >= 0 && data->draw_start <= (H - 1))
		{
			if (side == 0)
				color = getpix((data->intery - (int)(data->intery)) * (float)W,
						((float)data->draw_start - y) / (float)(data->draw_end
							- y) * (float)H, img);
			else
				color = getpix((data->interx - (int)(data->interx)) * (float)W,
						((float)data->draw_start
							- y) / (float)(data->draw_end - y) * (float)H, img);
			put_pixel(x, data->draw_start, color, data);
		}
		data->draw_start++;
	}
}
