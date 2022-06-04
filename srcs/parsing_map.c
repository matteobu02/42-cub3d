/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_map.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbucci <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/31 14:01:41 by mbucci            #+#    #+#             */
/*   Updated: 2022/06/05 01:03:22 by mbucci           ###   ########.fr       */
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
	data->map->width = get_map_width(tmp) - 1;
}

void	check_map(t_main *data, char **tab)
{
	int			vars[3];
	char const	set[7] = {'1', '0', ' ', 'N', 'S', 'E', 'W'};

	vars[0] = -1;
	while (tab[++vars[0]])
	{
		vars[1] = -1;
		while (tab[vars[0]][++vars[1]] && tab[vars[0]][vars[1]] != '\n')
		{
			vars[2] = 0;
			while (vars[2] < 7 && set[vars[2]] != tab[vars[0]][vars[1]])
				vars[2]++;
			if (vars[2] == 7)
				close_program(INVALID_MAP_ERROR, data);
			if (vars[2] > 2)
			{
				if (data->map->start_posx != -1)
					close_program(MULTIPLE_SPAWN_ERROR, data);
				data->map->start_posx = vars[1];
				data->map->start_posy = vars[0];
			}
		}
	}
	if (data->map->start_posx == -1)
		close_program(NO_SPAWN_ERROR, data);
}

int	**get_new_map(t_main *data)
{
	int	**ret;
	int	i;

	i = -1;
	data->map->height = 0;
	while (data->raw_map[++i])
		if (!check_line(data->raw_map[i], '\n'))
			data->map->height++;
	ret = (int **)malloc(sizeof(int *) * (data->map->height + 1));
	if (!ret)
		close_program(MALLOC_ERROR, data);
	i = -1;
	while (++i < data->map->height)
	{
		ret[i] = (int *)malloc(sizeof(int) * data->map->width);
		if (!ret[i])
		{
			ret = ft_free_tab((void **)ret);
			close_program(MALLOC_ERROR, data);
		}
		fill_with_space(ret[i], data->map->width);
	}
	ret[i] = NULL;
	return (ret);
}

void	convert_map(t_main *data)
{
	int	i;
	int	j;
	int	x;

	data->map->map = get_new_map(data);
	i = -1;
	x = 0;
	while (data->raw_map[++i])
	{
		if (check_line(data->raw_map[i], '\n'))
			skip_empty_lines(data, &i);
		if (!data->raw_map[i])
			break ;
		j = -1;
		while (++j < ft_strlen(data->raw_map[i]))
		{
			if (ft_isspace(data->raw_map[i][j]))
				continue ;
			else if (ft_isdigit(data->raw_map[i][j]))
				data->map->map[x][j] = data->raw_map[i][j] - 48;
			else
				data->map->map[x][j] = 0;
		}
		x++;
	}
}

void	check_map_closed(int **tab, t_main *data)
{
	int	i;
	int	j;

	data->raw_map = ft_free_tab((void **)data->raw_map);
	i = -1;
	while (tab[++i])
	{
		j = -1;
		while (++j < data->map->width - 1)
		{
			if (tab[i][j] == 32 || !j)
			{
				while (j < data->map->width && tab[i][j] == 32)
					j++;
				if (j == data->map->width)
					continue ;
				if (tab[i][j] != 1)
					close_program(MAP_OPEN_ERROR, data);
			}
			if (!tab[i][j] && (tab[i][j + 1] == 32
				|| tab[i + 1][j] == 32 || tab[i - 1][j] == 32))
				close_program(MAP_OPEN_ERROR, data);
		}
	}
	return ;
}
