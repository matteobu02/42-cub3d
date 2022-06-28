/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_frame.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lyaiche <lyaiche@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/13 15:54:31 by lyaiche           #+#    #+#             */
/*   Updated: 2022/06/28 17:54:17 by lyaiche          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	inversion(t_data *data)
{
	if (data->interx < 50)
		data->interx = 100 - data->interx;
	else
		data->interx = data->interx - 50;
	if (data->intery < 50)
		data->intery = 100 - data->intery;
	else
		data->intery = data->intery - 50;
}

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
	{
		inversion(data);
		vertline(raycast->r, raycast->side, data, &data->south);
	}
	else if (raycast->side)
		vertline(raycast->r, raycast->side, data, &data->north);
	else if (sin((raycast->ra + 1.5708)) > 0.0)
		vertline(raycast->r, raycast->side, data, &data->east);
	else
	{
		inversion(data);
		vertline(raycast->r, raycast->side, data, &data->west);
	}
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
				color = getpix((float)(data->intery - (int)(data->intery))
						* img->width,
						((float)data->draw_start - y) / (float)(data->draw_end
							- y) * img->height, img);
			else
				color = getpix((float)(data->interx - (int)(data->interx))
						* img->width,
						((float)data->draw_start - y) / (float)(data->draw_end
							- y) * img->height, img);
			put_pixel(x, data->draw_start, color, data);
		}
		data->draw_start++;
	}
}
