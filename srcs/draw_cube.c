/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_cube.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lyaiche <lyaiche@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/13 15:58:12 by lyaiche           #+#    #+#             */
/*   Updated: 2022/06/13 15:58:36 by lyaiche          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	draw_cube(float current_x, float current_y,
		int size, t_data *data, int color)
{
	int	x;
	int	y;

	y = -1;
	while (++y < size)
	{
		x = -1;
		while (++x < size)
			put_pixel(current_x + x, current_y + y, color, data);
	}
}
