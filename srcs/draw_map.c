/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lyaiche <lyaiche@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/13 15:55:00 by lyaiche           #+#    #+#             */
/*   Updated: 2022/06/14 20:54:24 by lyaiche          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	draw_map_5(int *x, float *current_x)
{
	*x = -1;
	*current_x = 0;
}

void	draw_map_4(t_data *data)
{
	data->minimap.color = 0xfcba03;
	draw_cube(data->px * data->minimap.tile_size,
		data->py * data->minimap.tile_size, data->minimap.p_size, data);
}

void	draw_map_3(float current_x, float current_y, t_data *data)
{
	data->minimap.color = 0x000000;
	draw_cube(current_x, current_y, data->minimap.tile_size,
		data);
}

void	draw_map_2(float current_x, float current_y, t_data *data)
{
	data->minimap.color = 0xffffff;
	draw_cube(current_x, current_y, data->minimap.tile_size,
		data);
}

void	draw_map(t_data *data)
{
	int			x;
	int			y;
	float		current_x;
	float		current_y;

	current_y = 0.0;
	y = 0;
	while (++y < data->height)
	{
		draw_map_5(&x, &current_x);
		while (++x < data->width)
		{
			if (data->map[y][x] == 1)
				draw_map_2(current_x, current_y, data);
			else
				draw_map_3(current_x, current_y, data);
			current_x += data->minimap.tile_size;
		}
		current_y += data->minimap.tile_size;
	}
	draw_map_4(data);
}
