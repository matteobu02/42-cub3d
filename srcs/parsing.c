/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbucci <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/12 13:48:48 by mbucci            #+#    #+#             */
/*   Updated: 2022/05/16 13:25:52 by mbucci           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	basic_check_arg(char const *path)
{
	int	fd;

	if ((ft_strlen(path) < 5) || !ft_strrstr(path, ".cub"))
		close_error("Error\nArgument is not a '. cub' file", NULL);
	fd = open(path, O_RDONLY);
	if (fd < 1 || read(fd, NULL, 0) < 0)
		close_error("Error\nFile can't be opened or does not exist", NULL);
	return (fd);
}

void	get_file_size(int fd, t_main *data)
{
	char	*line;
	int		i;

	i = 0;
	line = get_next_line(fd);
	while (line)
	{
		i++;
		free(line);
		line = get_next_line(fd);
	}
	close(fd);
	if (i < 9)
		close_error("Error\nInvalid map: data missing", data);
	data->map->height = i;
	return ;
}

void	get_data_file(char const *path, t_main *data)
{
	int		fd;
	char	**raw_map;
	char	*line;

	fd = open(path, O_RDONLY);
	raw_map = (char **)malloc(sizeof(char *) * data->map->height);
	if (!raw_map)
		close_error("Error\nMalloc error", data);
	line = get_next_line(fd);
	while (line)
	{
		*raw_map++ = line;
		line = get_next_line(fd);
	}
	close(fd);
	data->map->no_path = ft_strdup(find_in_tab(raw_map, "NO"));
	data->map->so_path = ft_strdup(find_in_tab(raw_map, "SO"));
	data->map->we_path = ft_strdup(find_in_tab(raw_map, "WE"));
	data->map->ea_path = ft_strdup(find_in_tab(raw_map, "EA"));
	if (!data->map->no_path || !data->map->so_path || !data->map->we_path
			|| !data->map->ea_path)
	{
		free(raw_map);
		close_error("Error\nTexture missing", data);
	}
}

char	*find_in_tab(char **tab, char *str)
{
	int		i;
	int		x;
	char	*found;

	i = -1;
	x = 0;
	while (tab[++i])
	{
		found = ft_strnstr(tab[i], str, ft_strlen(tab[i]));
		if (found)
			while (tab[++i])
				if (ft_strnstr(tab[i], str, ft_strlen(tab[i])))
					x++;
	}
	if (x > 1)
	{
		(void)ft_free_tab((void *)tab);
		close_error("Error\nJunk data found in file", NULL);
	}
	while (found && *found && *found != '.')
		found++;
	return (ft_strdup(found));
}
