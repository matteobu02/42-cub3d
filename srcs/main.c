/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbucci <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/10 12:57:52 by mbucci            #+#    #+#             */
/*   Updated: 2022/05/10 14:19:33 by mbucci           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	write_error(char *str)
{
	ft_putendl_fd(str, STDERR_FILENO);
	return (1);
}

int	main(int ac, char **av)
{
	/*** Argument check  ***/
	// Basic check
	if (ac == 1)
		return (write_error("Error: one argument needed"));
	ft_putendl_fd(av[1], 1);
	// Check if file exists and can be opened
	// Check map and infos
	
	/*** Get and render scene  ***/
	// Load walls, floor and cieling textures
	// Play the game
	return (0);
}
