/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbucci <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/12 13:27:24 by mbucci            #+#    #+#             */
/*   Updated: 2022/05/18 23:40:47 by mbucci           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# define MINLEN_ARG	5

# include "libft.h"
# include <mlx.h>
# include <fcntl.h>
# include <stdio.h>

typedef struct s_map
{
	int		height;
	int		**map;
	char	*no_path;
	char	*so_path;
	char	*we_path;
	char	*ea_path;
	int		floor;
	int		ceiling;
	int		start_posx;
	int		start_posy;
	char	orientation;
}	t_map;

typedef struct s_main
{
	t_map	*map;
	char	**raw_map;
}	t_main;

/** PARSING.C **/
void	basic_check_arg(char const *path, t_main *data);
void	get_map_info(char const *path, t_main *data);
char	*retrieve_info(char **tab, char *target, t_main *data);
void	get_info(t_main *data);

/** FREE.C  **/
void	close_program(char const *msg, t_main *ptr);
void	*free_map(t_map *ptr);

#endif
