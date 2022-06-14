/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lyaiche <lyaiche@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/23 12:34:30 by mbucci            #+#    #+#             */
/*   Updated: 2022/06/14 15:48:37 by lyaiche          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

char	*skip_spaces(char const *str, char const *target)
{
	char	*tmp;
	char	*tmp2;

	tmp = (char *)str;
	while (tmp && *tmp && ft_isspace(*tmp))
		tmp++;
	tmp2 = ft_strnstr(tmp, target, ft_strlen(target));
	if (!tmp2)
		return (NULL);
	if (ft_strlen(target) > 1)
	{
		tmp += 2;
		while (*tmp && ft_isspace(*tmp))
			tmp++;
		tmp = ft_strnstr(tmp, "./", 2);
		if (tmp && *(tmp + 3) && !ft_isspace(*(tmp + 3)) && *(tmp + 3) != '\n')
			return (tmp2);
		else
			return (NULL);
	}
	return (tmp);
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
