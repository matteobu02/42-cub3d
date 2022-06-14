/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keyhook.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lyaiche <lyaiche@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/13 14:45:20 by lyaiche           #+#    #+#             */
/*   Updated: 2022/06/14 18:35:27 by lyaiche          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	key_hook_release_2(int keycode, t_data *data)
{
	if (keycode == 123)
	{
		data->pa += 0;
	}
	if (keycode == 124)
	{
		data->pa -= 0;
	}
	return (0);
}

int	key_hook_release(int keycode, t_data *data)
{
	if (keycode == 0)
	{
		data->px += 0;
		data->py -= 0;
	}
	if (keycode == 2)
	{
		data->px -= 0;
		data->py += 0;
	}
	if (keycode == 13)
	{
		data->px += 0;
		data->py += 0;
	}
	if (keycode == 1)
	{
		data->px -= 0;
		data->py -= 0;
	}
	return (key_hook_release_2(keycode, data));
}


int	key_hook_3(int keycode, t_data *data)
{
	if (data->map[(int)data->py][(int)data->px] > 0)
	{
		data->px = data->old_x;
		data->py = data->old_y;
	}
	if (keycode == 53)
		end(data);
	mlx_clear_window(data->mlx, data->win);
	launch(data);
	return (0);
}

int	key_hook_2(int keycode, t_data *data)
{
	if (keycode == 123)
	{
		data->pa += 2;
		data->pa = fixang(data->pa);
		data->pdx = cos(degtorad(data->pa));
		data->pdy = -sin(degtorad(data->pa));
	}
	if (keycode == 124)
	{
		data->pa -= 2;
		data->pa = fixang(data->pa);
		data->pdx = cos(degtorad(data->pa));
		data->pdy = -sin(degtorad(data->pa));
	}
	return (key_hook_3(keycode, data));
}

int	key_hook(int keycode, t_data *data)
{
	data->old_x = data->px;
	data->old_y = data->py;
	if (keycode == 0)
	{
		data->px += data->pdy * 0.1;
		data->py -= data->pdx * 0.1;
	}
	if (keycode == 2)
	{
		data->px -= data->pdy * 0.1;
		data->py += data->pdx * 0.1;
	}
	if (keycode == 13)
	{
		data->px += data->pdx * 0.2;
		data->py += data->pdy * 0.2;
	}
	if (keycode == 1)
	{
		data->px -= data->pdx * 0.2;
		data->py -= data->pdy * 0.2;
	}
	return (key_hook_2(keycode, data));
}
