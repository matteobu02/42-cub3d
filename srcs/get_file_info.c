/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_file_info.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbucci <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/12 13:48:48 by mbucci            #+#    #+#             */
/*   Updated: 2022/06/22 13:55:04 by mbucci           ###   ########.fr       */
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

/*
 * n is an array where the first 3 elements are meant to store the rgb
 * values. The 4th is an index (=i).
*/

int	get_rgb(char *s, t_main *data)
{
	int	n[4];

	if (!ft_isspace(*s))
		close_program(NO_SPACE_ENTRY_ERROR, data);
	n[3] = -1;
	while (++n[3] < 3)
	{
		n[n[3]] = ft_atoi(s);
		if (n[n[3]] > 255 || n[n[3]] < 0)
			close_program(INVALID_RGB_ERROR, data);
		s = skip_spaces_nums(s);
		if ((*s && n[3] < 2 && *s != ',') || (!*s && n[3] < 2))
			close_program(INVALID_RGB_ERROR, data);
		else if (*s && n[3] < 2)
			s++;
		while (s && *s && n[3] < 2 && ft_isspace(*s))
			s++;
		if (s && *s && !ft_isdigit(*s))
			close_program(INVALID_RGB_ERROR, data);
	}
	if (*s && *s != '\n')
		close_program(INVALID_RGB_ERROR, data);
	return (combine_rgb(n[0], n[1], n[2]));
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
