/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vertline.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lyaiche <lyaiche@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/13 15:54:31 by lyaiche           #+#    #+#             */
/*   Updated: 2022/06/14 17:56:17 by lyaiche          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	vertline(int x, int side, t_data *data, t_img *img)
{
	int		w;
	int		h;
	int		color;
	float	y;

	y = data->draw_start;
	h = H;
	w = W;
	while (data->draw_start < data->draw_end)
	{	
		if (data->draw_start >= 0 && data->draw_start <= (h - 1))
		{
			if (side == 0)
				color = getpix((data->intery - (int)(data->intery)) * (float)w,
						((float)data->draw_start - y) / (float)(data->draw_end
							- y) * (float)h, img);
			else
				color = getpix((data->interx - (int)(data->interx)) * (float)w,
						((float)data->draw_start
							- y) / (float)(data->draw_end - y) * (float)h, img);
			put_pixel(x, data->draw_start, color, data);
		}
		data->draw_start++;
	}
}
