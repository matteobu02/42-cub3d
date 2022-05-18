/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbucci <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/12 13:48:48 by mbucci            #+#    #+#             */
/*   Updated: 2022/05/18 17:03:20 by mbucci           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	basic_check_arg(char const *path, t_main *data)
{
	int		fd;
	int		i;
	char	*line;

	if ((ft_strlen(path) < MINLEN_ARG) || !ft_strrstr(path, ".cub"))
		close_program("Error\nArgument is not a '.cub' file", data);
	fd = open(path, O_RDONLY);
	if (fd < 1 || read(fd, NULL, 0) < 0)
		close_program("Error\nFile can't be opened or does not exist", data);
	line = get_next_line(fd);
	i = 0;
	while (line)
	{
		i++;
		free(line);
		line = NULL;
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
		close_program("Error\nMalloc failed", data);
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
	int		i;
	char	*tmp;

	i = -1;
	while (tab[++i])
	{
		if (ft_strnstr(tab[i], target, ft_strlen(target)))
		{
			if (!ft_strcmp(target, "F") || !ft_strcmp(target, "C"))
			{
				tmp = tab[i];
				while (tmp && !ft_isdigit(*tmp))
				{
					if (!ft_isspace(*tmp) && !ft_isdigit(*tmp)
						&& *tmp != *target)
						close_program("Error\nIvalid data", data);
					tmp++;
				}
				return (tmp);
			}
			return (ft_strdup(ft_strchr(tab[i], '.')));
		}
	}
	close_program("Error\nData missing or invalid in file", data);
	return (NULL);
}

int	get_rgb(char *str, t_main *data)
{
	int	ret;
	int	sets;
	int	tmp[3];

	if (!str)
		close_program("Error\nFile data is invalid", data);
	sets = -1;
	while (++sets < 3)
	{
		tmp[sets] = ft_atoi(str);
		while (str && *str && ft_isdigit(*str))
			str++;
		if (*str == ',')
		{
			str++;
			if (!ft_isdigit(*str) && !ft_isspace(*str))
				close_program("Error\nFile data is invalid", data);
		}
	}
	ret = tmp[0];
	ret = (ret << 8) + tmp[1];
	ret = (ret << 8) + tmp[2];
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
		close_program("Error\nMalloc failed", data);
	data->map->floor = get_rgb(retrieve_info(data->raw_map, "F", data), data);
	data->map->ceiling = get_rgb(retrieve_info(data->raw_map, "C", data), data);
	return ;
}
