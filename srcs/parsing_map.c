/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_map.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbucci <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/31 14:01:41 by mbucci            #+#    #+#             */
/*   Updated: 2022/05/31 14:08:03 by mbucci           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	find_map(t_main *data)
{
	char	**tmp;
	int		i;
	int		j;

	i = 0;
	while (!check_line(data->raw_map[i], '1'))
		i++;
	tmp = (char **)malloc(sizeof(char *) * (data->map->height - i + 1));
	if (!tmp)
		close_program(MALLOC_ERROR, data);
	data->map->height -= i;
	j = -1;
	while (data->raw_map[i])
	{
		tmp[++j] = ft_strdup(data->raw_map[i++]);
		if (!tmp[j])
		{
			tmp = ft_free_tab((void **)tmp);
			close_program(MALLOC_ERROR, data);
		}
	}
	tmp[++j] = NULL;
	data->raw_map = ft_free_tab((void **)data->raw_map);
	data->raw_map = tmp;
}

void	check_map(t_main *data, char **tab)
{
	int			i;
	int			j;
	int			x;
	char const	poss[7] = {'1', '0', ' ', 'N', 'S', 'E', 'W'};

	i = -1;
	while (tab[++i])
	{
		j = -1;
		while (tab[i][++j] && tab[i][j] != '\n')
		{
			x = 0;
			while (x < 7 && poss[x] != tab[i][j])
				x++;
			if (x == 7)
				close_program(INVALID_MAP_ERROR, data);
			if (x > 2)
			{
				if (data->map->start_posx != -1)
					close_program(MULTIPLE_SPAWN_ERROR, data);
				data->map->start_posx = j;
				data->map->start_posy = i;
			}
		}
	}
}
