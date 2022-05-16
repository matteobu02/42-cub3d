/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbucci <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/12 13:27:24 by mbucci            #+#    #+#             */
/*   Updated: 2022/05/16 12:43:46 by mbucci           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include "libft.h"
# include <mlx.h>
# include <fcntl.h>

typedef struct s_map
{
	int		height;
	int		**map;
	char	*no_path;
	char	*so_path;
	char	*we_path;
	char	*ea_path;
}	t_map;

typedef struct s_main
{
	t_map	*map;
}	t_main;

/** PARSING.C **/
int		basic_check_arg(char const *path);
void	get_file_size(int fd, t_main *data);
char	*find_in_tab(char **tab, char *str);
void	get_data_file(char const *path, t_main *data);

/** FREE.C  **/
void	close_error(char const *msg, t_main *ptr);
void	*free_map(t_map *ptr);

#endif
