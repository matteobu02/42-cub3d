/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbucci <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/11 18:31:24 by mbucci            #+#    #+#             */
/*   Updated: 2022/05/17 16:57:47 by mbucci           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	close_error(char const *msg, t_main *ptr)
{
	if (ptr)
	{
		if (ptr->raw_map)
			ptr->raw_map = ft_free_tab((void **)ptr->raw_map);
		if (ptr->map)
			ptr->map = free_map(ptr->map);
	}
	ft_putendl_fd(msg, STDERR_FILENO);
	exit(EXIT_FAILURE);
}

int	main(int ac, char **av)
{
	t_main	data;

	// Check number of arguments
	if (ac != 2)
		close_error("Error\nNeed exactly one '.cub' parameter", NULL);
	data.map = (t_map *)malloc(sizeof(t_map));
	if (!data.map)
		close_error("Error\nMalloc failed", NULL);
	// Check file name and accessibility + get file size
	basic_check_arg(av[1], &data);
	get_map_info(av[1], &data);
	// Check infos and map
	// Build main struct
	return (0);
}
