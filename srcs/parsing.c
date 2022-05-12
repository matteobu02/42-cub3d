/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbucci <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/12 13:48:48 by mbucci            #+#    #+#             */
/*   Updated: 2022/05/12 14:58:37 by mbucci           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	check_arg(char *path)
{
	int	fd;

	if ((ft_strlen(path) < 5) || !ft_strrstr(path, ".cub"))
		close_error("Error\nargument is not a '. cub' file");
	fd = open(path, O_RDONLY);
	if (fd < 1 || read(fd, NULL, 0) < 0)
		close_error("Error\nfile can't be opened");
	return (fd);
}
