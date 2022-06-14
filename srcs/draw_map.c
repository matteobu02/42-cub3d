/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lyaiche <lyaiche@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/13 15:55:00 by lyaiche           #+#    #+#             */
/*   Updated: 2022/06/14 15:55:19 by lyaiche          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	draw_map(t_data *data)
{
	t_minimap	*minimap;
	int			x;
	int			y;
	float		current_x;
	float		current_y;

	minimap = &data->minimap;
	y = -1;
	while (++y < minimap->height)
	{
		x = -1;
		while (++x < minimap->width)
		{
			put_pixel(x, y, 0x000000, data);
		}
	}
	current_x = 0;
	current_y = 0;
	y = -1;
	while (++y < data->height)
	{
		x = -1;
		while (++x < data->width)
		{
			if (data->map[y][x] == 1)
			{
				draw_cube(current_x, current_y, minimap->tile_size,
					data, 0xffffff);
			}
			current_x += minimap->tile_size;
		}
		current_x = 0;
		current_y += minimap->tile_size;
	}
	draw_cube(data->px * minimap->tile_size, data->py * minimap->tile_size,
		minimap->p_size, data, 0xfcba03);
}
