/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_file_info.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbucci <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/13 15:28:01 by mbucci            #+#    #+#             */
/*   Updated: 2022/06/13 15:41:33 by mbucci           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	basic_check_arg(char const *path, t_main *data)
{
	int		fd;
	int		i;
	char	*line;

	if ((ft_strlen(path) < MINLEN_ARG) || !ft_strrstr(path, ".cub"))
		close_program(INVALID_ARG_ERROR, data);
	fd = open(path, O_RDONLY);
	if (fd < 1 || read(fd, NULL, 0) < 0)
		close_program(FILE_ERROR, data);
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

char	*retrieve_info(char **t, char const *trgt, t_main *data)
{
	int		i;
	char	*tmp;

	i = -1;
	while (t[++i] && !check_line(t[i], '1'))
	{
		if (skip_spaces(t[i], trgt) && !check_line(t[i] + ft_strlen(trgt), 32))
		{
			if (!ft_strcmp(trgt, "F") || !ft_strcmp(trgt, "C"))
			{
				tmp = t[i];
				while (tmp && !ft_isdigit(*tmp))
				{
					if (!ft_isspace(*tmp) && !ft_isdigit(*tmp) && *tmp != *trgt)
						close_program(INVALID_DATA_ERROR, data);
					tmp++;
				}
				return (--tmp);
			}
			return (ft_strdup(ft_strchr(t[i], '.')));
		}
	}
	close_program(MISSING_DATA_ERROR, data);
	return (NULL);
}

int	get_rgb(char const *s, t_main *data)
{
	int	nums[5];

	if (!ft_isspace(*s))
		close_program(NO_SPACE_ENTRY_ERROR, data);
	nums[3] = -1;
	while (++nums[3] < 3)
	{
		nums[nums[3]] = ft_atoi(s);
		if (nums[nums[3]] < 0 || nums[nums[3]] > 255)
			close_program(INVALID_RGB_ERROR, data);
		while (s && *s && (ft_isdigit(*s) || ft_isspace(*s)))
			s++;
		if ((*s && *s != ',' && *s != '\n') || (!*s && nums[3] < 2))
			close_program(INVALID_RGB_ERROR, data);
		else if (*s)
			s++;
		while (*s && ft_isspace(*s))
			s++;
		if (*s && !ft_isdigit(*s))
			close_program(INVALID_RGB_ERROR, data);
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
		close_program(MALLOC_ERROR, data);
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
		close_program(MALLOC_ERROR, data);
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
	if (!*data->raw_map)
		close_program(FILE_EMPTY_ERROR, data);
	get_info(data);
	return ;
}
