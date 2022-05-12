/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbucci <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/12 13:27:24 by mbucci            #+#    #+#             */
/*   Updated: 2022/05/12 15:47:59 by mbucci           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

#include "libft.h"
#include <mlx.h>
#include <fcntl.h>

typedef struct s_map
{
	int	**map;
	
}	t_map;

/** PARSING.C **/

void	close_error(char *msg);
int		check_arg(char *path);

#endif
