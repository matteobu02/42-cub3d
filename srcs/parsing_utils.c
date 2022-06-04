/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbucci <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/23 12:34:30 by mbucci            #+#    #+#             */
/*   Updated: 2022/06/05 01:01:55 by mbucci           ###   ########.fr       */
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
		if (tmp)
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
		if (tmp > ret)
			ret = tmp;
	}
	return (ret);
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
