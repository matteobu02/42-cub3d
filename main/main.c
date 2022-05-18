/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbucci <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/11 18:31:24 by mbucci            #+#    #+#             */
/*   Updated: 2022/05/18 17:07:19 by mbucci           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	close_program(char const *msg, t_main *ptr)
{
	if (ptr)
	{
		if (ptr->raw_map)
			ptr->raw_map = ft_free_tab((void **)ptr->raw_map);
		if (ptr->map)
			ptr->map = free_map(ptr->map);
	}
	if (msg)
	{
		ft_putendl_fd(msg, STDERR_FILENO);
		//system("leaks cub3d");
		exit(EXIT_FAILURE);
	}
	return ;
}

t_map	*init_map_struct(void)
{
	t_map	*ret;

	ret = (t_map *)malloc(sizeof(t_map));
	if (!ret)
		close_program("Error\nMalloc failed", NULL);
	ret->map = NULL;
	ret->no_path = NULL;
	ret->so_path = NULL;
	ret->we_path = NULL;
	ret->ea_path = NULL;
	return (ret);
}

int	main(int ac, char **av)
{
	t_main	data;

	// Check number of arguments
	if (ac != 2)
		close_program("Error\nNeed exactly one '.cub' parameter", NULL);
	data.map = init_map_struct();
	// Check file name and accessibility + get file size
	basic_check_arg(av[1], &data);
	get_map_info(av[1], &data);
	// Check infos and map
	// Build main struct
	close_program(NULL, &data);
	//system("leaks cub3d");
	return (0);
}
