/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keyhook.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lyaiche <lyaiche@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/13 14:45:20 by lyaiche           #+#    #+#             */
/*   Updated: 2022/06/15 17:24:01 by lyaiche          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	key_hook_release(int keycode, t_data *data)
{
	if (keycode == 13)
		data->d = 0;
	if (keycode == 1)
		data->a = 0;
	if (keycode == 0)
		data->w = 0;
	if (keycode == 2)
		data->s = 0;
	if (keycode == 123)
		data->l = 0;
	if (keycode == 124)
		data->r = 0;
	return (0);
}

int	key_hook_press(int keycode, t_data *data)
{
	if (keycode == 53)
		end(data);
	if (keycode == 13)
		data->d = 1;
	if (keycode == 1)
		data->a = 1;
	if (keycode == 0)
		data->w = 1;
	if (keycode == 2)
		data->s = 1;
	if (keycode == 123)
		data->l = 1;
	if (keycode == 124)
		data->r = 1;
	return (0);
}

int	key_hook(t_data *data)
{
	if (data->w == 1)
		go_forward(data);
	if (data->s == 1)
		go_backward(data);
	if (data->a == 1)
		go_left(data);
	if (data->d == 1)
		go_right(data);
	if (data->l == 1)
	{
		data->rot = 2;
		rotate(data);
	}
	if (data->r == 1)
	{
		data->rot = -2;
		rotate(data);
	}
	launch(data);
	return (0);
}
