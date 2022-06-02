/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbucci <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/11 18:31:24 by mbucci            #+#    #+#             */
/*   Updated: 2022/06/02 17:27:43 by mbucci           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

t_map	*init_map_struct(void)
{
	t_map	*ret;

	ret = (t_map *)malloc(sizeof(t_map));
	if (!ret)
		close_program(MALLOC_ERROR, NULL);
	ret->map = NULL;
	ret->no = NULL;
	ret->so = NULL;
	ret->we = NULL;
	ret->ea = NULL;
	ret->c = -1;
	ret->f = -1;
	ret->start_posx = -1;
	ret->start_posy = -1;
	ret->width = 0;
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
		close_program(ARG_NUM_ERROR, NULL);
	data.map = init_map_struct();
	basic_check_arg(av[1], &data);
	get_map_info(av[1], &data);
	deep_check_info(data.raw_map, &data);
	find_map(&data);
	check_map(&data, data.raw_map);
	convert_map(&data);
	check_map_closed(data.map->map, &data);
	close_program(NULL, &data);
	return (0);
}
