/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbucci <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/11 18:31:24 by mbucci            #+#    #+#             */
/*   Updated: 2022/05/30 14:45:59 by mbucci           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

t_map	*init_map_struct(void)
{
	t_map	*ret;

	ret = (t_map *)malloc(sizeof(t_map));
	if (!ret)
		close_program("Error\nMalloc failed", NULL);
	ret->map = NULL;
	ret->no = NULL;
	ret->so = NULL;
	ret->we = NULL;
	ret->ea = NULL;
	ret->c = -1;
	ret->f = -1;
	return (ret);
}

/*void	print_info(t_main *data)
{
	ft_print_tab(data->raw_map);
	printf("%s", data->map->no);
	printf("%s", data->map->so);
	printf("%s", data->map->we);
	printf("%s", data->map->ea);
	printf("%d\n", data->map->f);
	printf("%d\n", data->map->c);
}*/

int	main(int ac, char **av)
{
	t_main	data;

	if (ac != 2)
		close_program("Error\nNeed exactly one '.cub' parameter", NULL);
	data.map = init_map_struct();
	basic_check_arg(av[1], &data);
	get_map_info(av[1], &data);
	deep_check_info(data.raw_map, &data);
	// Check map
	//get_map(data.raw_map, &data);
	close_program(NULL, &data);
	return (0);
}
