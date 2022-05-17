/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbucci <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/12 13:48:48 by mbucci            #+#    #+#             */
/*   Updated: 2022/05/17 17:00:53 by mbucci           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	basic_check_arg(char const *path, t_main *data)
{
	int		fd;
	int		i;
	char	*line;

	if ((ft_strlen(path) < MINLEN_ARG) || !ft_strrstr(path, ".cub"))
		close_error("Error\nArgument is not a '. cub' file", data);
	fd = open(path, O_RDONLY);
	if (fd < 1 || read(fd, NULL, 0) < 0)
		close_error("Error\nFile can't be opened or does not exist", data);
	line = get_next_line(fd);
	i = 0;
	while (line)
	{
		i++;
		free(line);
		line = get_next_line(fd);
	}
	close(fd);
	data->map->height = i;
	return ;
}

void	get_map_info(char const *path, t_main *data)
{
	int		fd;
	int		i;
	char	*line;

	data->raw_map = (char **)malloc(sizeof(char *) * (data->map->height + 1));
	if (!data->raw_map)
		close_error("Error\nMalloc failed", data);
	fd = open(path, O_RDONLY);
	line = get_next_line(fd);
	i = -1;
	while (line)
	{
		data->raw_map[++i] = line;
		line = get_next_line(fd);
	}
	data->raw_map[++i] = NULL;
	close(fd);
	get_info(data);
	return ;
}

char	*retrieve_info(char **tab, char *target, t_main *data)
{
	int	i;

	i = -1;
	while (tab[++i])
	{
		if (ft_strnstr(tab[i], target, ft_strlen(target)))
		{
			if (!ft_strcmp(target, "F") || !ft_strcmp(target, "C"))
			{
				while (tab[i] && (*tab[i] > 57 || *tab[i] < 48))
					tab[i]++;
				return (tab[i]);
			}
			else
				return (ft_strdup(ft_strchr(tab[i], '.')));
		}
	}
	close_error("Error\nA texture couldn't be found", data);
	return (NULL);
}

int	get_rgb(char *str, t_main *data)
{
	int	ret;
	int	sets;

	if (!str)
		close_error("Error\nWrong file format", data);
	sets = 3;
	while (*str > 47 && *str < 58)
	{
		str++;
		if (*str == ',' && --sets)
		{
			str++;
			continue ;
		}
	}
	ret = 0;
	return (ret);
}

void	get_info(t_main *data)
{
	data->map->no_path = retrieve_info(data->raw_map, "NO", data);
	data->map->so_path = retrieve_info(data->raw_map, "SO", data);
	data->map->we_path = retrieve_info(data->raw_map, "WE", data);
	data->map->ea_path = retrieve_info(data->raw_map, "EA", data);
	if (!data->map->no_path || !data->map->so_path || !data->map->we_path
		|| !data->map->ea_path)
		close_error("Error\nMalloc failed", data);
/*	data->map->floor = get_rgb(retrieve_info(data->raw_map, "F"), data);
	data->map->ceiling = get_rgb(retrieve_info(data->raw_map, "C"), data);
	if (data->map->ceiling == -1 || data->map->floor == -1)
		close_error("Error\nFloor or ceiling color is invalid");*/
	return ;
}
