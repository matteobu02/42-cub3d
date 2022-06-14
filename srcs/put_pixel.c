/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_pixel.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lyaiche <lyaiche@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/13 15:53:23 by lyaiche           #+#    #+#             */
/*   Updated: 2022/06/13 15:53:35 by lyaiche          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	put_pixel(int x, int y, int color, t_data *data)
{
	char	*pxl;

	pxl = data->addr + (x * data->bits_per_pixel / 8) + (y * data->line_bytes);
	*(unsigned int *)pxl = color;
}
