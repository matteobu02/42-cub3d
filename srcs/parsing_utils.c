/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lyaiche <lyaiche@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/23 12:34:30 by mbucci            #+#    #+#             */
/*   Updated: 2022/06/22 13:54:47 by mbucci           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

char	*skip_spaces_nums(char *s)
{
	while (s && *s && ft_isspace(*s))
		s++;
	while (s && *s && ft_isdigit(*s))
		s++;
	while (s && *s && ft_isspace(*s))
		s++;
	return (s);
}

int	combine_rgb(int r, int g, int b)
{
	int	ret;

	ret = r;
	ret = (ret << 8) + g;
	ret = (ret << 8) + b;
	return (ret);
}

int	get_map_width(char **tab)
{
	int	ret;
	int	tmp;
	int	i;

	i = -1;
	ret = 0;
	while (tab[++i])
	{
		tmp = ft_strlen(tab[i]);
		if (tab[i][tmp - 1] == '\n')
			tmp--;
		while (tmp > -1 && ft_isspace(tab[i][tmp]))
			tmp--;
		if (tmp > ret)
			ret = tmp;
	}
	return (ret + 1);
}

void	fill_with_space(int *tab, int size)
{
	int	i;

	i = -1;
	while (++i < size)
		tab[i] = 32;
}

void	skip_empty_lines(t_main *data, int *i)
{
	while (data->raw_map[*i] && check_line(data->raw_map[*i], '\n'))
		*i += 1;
	if (data->raw_map[*i] && !check_line(data->raw_map[*i], '1'))
		close_program(INVALID_MAP_ERROR, data);
}
