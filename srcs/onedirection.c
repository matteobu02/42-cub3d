/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   onedirection.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lyaiche <lyaiche@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/20 16:49:55 by lyaiche           #+#    #+#             */
/*   Updated: 2022/06/20 17:22:31 by lyaiche          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	onedirection(t_data *data, t_main *main)
{
	if (main->map->orientation == 'N')
		data->pa = 90.0;
	else if (main->map->orientation == 'S')
		data->pa = 270.0;
	else if (main->map->orientation == 'W')
		data->pa = 180.0;
	else if (main->map->orientation == 'E')
		data->pa = 0.0;
}
