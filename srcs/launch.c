/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   launch.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lyaiche <lyaiche@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/13 14:36:38 by lyaiche           #+#    #+#             */
/*   Updated: 2022/06/15 14:27:30 by lyaiche          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	launch(t_data *data)
{
	t_minimap	*minimap;

	minimap = &data->minimap;
	draw3drays(data);
	minimap->height = 400;
	minimap->width = 400;
	if (data->width < data->height)
		minimap->tile_size = minimap->height / data->height;
	else
		minimap->tile_size = minimap->height / data->width;
	minimap->p_size = minimap->tile_size / 10;
	draw_map(data);
	mlx_clear_window(data->mlx, data->win);
	mlx_put_image_to_window(data->mlx, data->win, data->img, 0, 0);
	return (0);
}
