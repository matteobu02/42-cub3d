/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lyaiche <lyaiche@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/15 12:33:15 by lyaiche           #+#    #+#             */
/*   Updated: 2022/06/15 15:03:38 by lyaiche          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	go_forward(t_data *data)
{
	float	oldx;
	float	oldy;

	oldx = data->px;
	oldy = data->py;
	data->px += data->pdy * 0.1;
	data->py -= data->pdx * 0.1;
	if (data->map[(int)data->py][(int)data->px] > 0)
	{
		data->px = oldx;
		data->py = oldy;
	}
}

void	go_backward(t_data *data)
{
	float	oldx;
	float	oldy;

	oldx = data->px;
	oldy = data->py;
	data->px -= data->pdy * 0.1;
	data->py += data->pdx * 0.1;
	if (data->map[(int)data->py][(int)data->px] > 0)
	{
		data->px = oldx;
		data->py = oldy;
	}
}

void	go_right(t_data *data)
{
	float	oldx;
	float	oldy;

	oldx = data->px;
	oldy = data->py;
	data->px += data->pdx * 0.2;
	data->py += data->pdy * 0.2;
	if (data->map[(int)data->py][(int)data->px] > 0)
	{
		data->px = oldx;
		data->py = oldy;
	}
}

void	go_left(t_data *data)
{
	float	oldx;
	float	oldy;

	oldx = data->px;
	oldy = data->py;
	data->px -= data->pdx * 0.2;
	data->py -= data->pdy * 0.2;
	if (data->map[(int)data->py][(int)data->px] > 0)
	{
		data->px = oldx;
		data->py = oldy;
	}
}

void	rotate(t_data *data)
{
	data->pa += data->rot;
	data->pa = fixang(data->pa);
	data->pdx = cos(degtorad(data->pa));
	data->pdy = -sin(degtorad(data->pa));
}
