/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_map.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbucci <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/19 17:56:17 by mbucci            #+#    #+#             */
/*   Updated: 2022/05/30 17:32:32 by mbucci           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	check_line(char const *str, int c)
{
	int	i;

	if (!str)
		return (0);
	i = -1;
	if (!ft_isspace(c))
	{
		while (str[++i] && ft_isspace(str[i]))
			;
		if (!str[i])
			return (0);
		--i;
	}
	while (str[++i])
		if (str[i] != c && str[i] != '\n')
			return (0);
	if (i == ft_strlen(str))
		return (1);
	return (0);
}

void	check_valid_line(char const *str, char const *target, t_main *data)
{
	int		i;
	char	*tmp;

	tmp = skip_spaces(str, target);
	if (tmp)
		i = 1;
	else
		return ;
	if (!ft_isspace(tmp[i + 1]))
		close_program(NO_SPACE_PATH_ERROR, data);
	while (tmp[++i] && tmp[i] != '.')
		if (!ft_isspace(tmp[i]))
			close_program(IDENTIFIER_PATH_ERROR, data);
	while (tmp[i] && !ft_isspace(tmp[i]))
		i++;
	while (tmp[++i])
		if (!ft_isspace(tmp[i]) && tmp[i] != '\n')
			close_program(AFTER_PATH_ERROR, data);
	tmp = NULL;
	return ;
}

void	deep_check_info(char **tab, t_main *data)
{
	char const	*targets[6] = {"NO", "SO", "WE", "EA", "F", "C"};
	int			i;
	int			j;
	int			x;

	i = -1;
	while (!check_line(tab[++i], '1'))
	{
		x = -1;
		while (++x < 6)
			if (skip_spaces(tab[i], targets[x]))
				break ;
		if (x < 4)
			check_valid_line(tab[i], targets[x], data);
		if (x == 6 && *tab[i] != '\n' && !check_line(tab[i], 32))
			close_program(INVALID_DATA_ERROR, data);
		j = i;
		while (tab[++j] && x != 6)
			if (skip_spaces(tab[j], targets[x]))
				close_program(DUPLICATED_ENTRY_ERROR, data);
	}
	return ;
}

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
