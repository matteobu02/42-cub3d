/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbucci <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/11 18:31:24 by mbucci            #+#    #+#             */
/*   Updated: 2022/05/12 17:36:56 by mbucci           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	close_error(char *msg)
{
	ft_putendl_fd(msg, STDERR_FILENO);
	exit(EXIT_FAILURE);
}

int	main(int ac, char **av)
{
	// Check number of arguments
	if (ac != 2)
		close_error("Error\nNeed exactly one '.cub' parameter");
	// Check file name and accessibility
	int fd = check_arg(av[1]);
	// Check infos and map
	// Build main struct
	(void)fd;
	return (0);
}
