/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbucci <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/12 13:48:48 by mbucci            #+#    #+#             */
/*   Updated: 2022/05/23 14:23:47 by mbucci           ###   ########.fr       */
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

char	*retrieve_info(char **tab, char const *trgt, t_main *data)
{
	int		i;
	char	*tmp;

	i = -1;
	while (tab[++i])
	{
		if (skip_spaces(tab[i], trgt) && !check_line(tab[i] + 2, 32))
		{
			if (!ft_strcmp(trgt, "F") || !ft_strcmp(trgt, "C"))
			{
				tmp = tab[i];
				while (tmp && !ft_isdigit(*tmp))
				{
					if (!ft_isspace(*tmp) && !ft_isdigit(*tmp) && *tmp != *trgt)
						close_program("Error\nIvalid data", data);
					tmp++;
				}
				return (tmp);
			}
			return (ft_strdup(ft_strchr(tab[i], '.')));
		}
	}
	close_program("Error\nMissing or invalid data in file", data);
	return (NULL);
}

int	get_rgb(char const *str, t_main *data)
{
	int	nums[5];

	if (!str)
		close_program("Error\nInvalid data", data);
	nums[3] = -1;
	while (++nums[3] < 3)
	{
		nums[nums[3]] = ft_atoi(str);
		if (nums[nums[3]] < 0 || nums[nums[3]] > 255)
			close_program("Error\nInvalid RGB data", data);
		while (str && *str && (ft_isdigit(*str) || ft_isspace(*str)))
			str++;
		if (*str && *str != ',' && *str != '\n')
			close_program("Error\nInvalid RGB data", data);
		else if (*str)
			str++;
		while (*str && ft_isspace(*str))
			str++;
		if (*str && !ft_isdigit(*str))
			close_program("Error\nInvalid RGB data", data);
	}
	nums[4] = nums[0];
	nums[4] = (nums[4] << 8) + nums[1];
	nums[4] = (nums[4] << 8) + nums[2];
	return (nums[4]);
}

void	get_info(t_main *data)
{
	data->map->no = retrieve_info(data->raw_map, "NO", data);
	data->map->so = retrieve_info(data->raw_map, "SO", data);
	data->map->we = retrieve_info(data->raw_map, "WE", data);
	data->map->ea = retrieve_info(data->raw_map, "EA", data);
	if (!data->map->no || !data->map->so || !data->map->we || !data->map->ea)
		close_program("Error\nMalloc failed", data);
	data->map->f = get_rgb(retrieve_info(data->raw_map, "F", data), data);
	data->map->c = get_rgb(retrieve_info(data->raw_map, "C", data), data);
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
