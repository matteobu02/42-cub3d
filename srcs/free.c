/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbucci <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/13 16:12:08 by mbucci            #+#    #+#             */
/*   Updated: 2022/05/31 16:33:15 by mbucci           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	*free_map(t_map *ptr)
{
	if (ptr)
	{
		if (ptr->map)
			ptr->map = ft_free_tab((void **)ptr->map);
		if (ptr->no)
			free(ptr->no);
		if (ptr->so)
			free(ptr->so);
		if (ptr->we)
			free(ptr->we);
		if (ptr->ea)
			free(ptr->ea);
		free(ptr);
	}
	return (NULL);
}

void	close_program(char const *msg, t_main *ptr)
{
	if (ptr)
	{
		if (ptr->raw_map)
			ptr->raw_map = ft_free_tab((void **)ptr->raw_map);
		if (ptr->map)
			ptr->map = free_map(ptr->map);
	}
	//system("leaks cub3D");
	if (msg)
	{
		ft_putendl_fd(msg, STDERR_FILENO);
		if (ft_strnstr(msg, "Error\n", 6))
			exit(EXIT_FAILURE);
	}
	return ;
}
