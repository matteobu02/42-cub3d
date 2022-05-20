/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_map.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbucci <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/19 17:56:17 by mbucci            #+#    #+#             */
/*   Updated: 2022/05/20 13:21:39 by mbucci           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	check_line(char const *str, int c)
{
	int	i;

	if (!str)
		return (0);
	i = -1;
	while (str[++i] && ft_isspace(str[i]))
		;
	if (!str[i])
		return (0);
	--i;
	while (str[++i])
		if (str[i] != c && str[i] != '\n')
			return (0);
	if (i == ft_strlen(str))
		return (1);
	return (0);
}

void	check_valid_line(char *str, t_main *data)
{
	int	i;

	i = 1;
	while (str[++i] && str[i] != '.')
	{
		if (!ft_isspace(str[i]))
			close_program("Error\nInvalid data between identifier and path",
				data);
	}
	return ;
}

void	deep_check_map(char **tab, t_main *data)
{
	char const	*trgts[6] = {"NO", "SO", "WE", "EA", "F", "C"};
	int			i;
	int			j;
	int			x;

	i = -1;
	while (tab[++i])
	{
		if (check_line(tab[i], '1'))
			break ;
		x = -1;
		while (++x < 6)
			if (ft_strnstr(tab[i], trgts[x], ft_strlen(trgts[x])))
				break ;
		if (x < 4)
			check_valid_line(tab[i], data);
		if (x == 6 && *tab[i] != '\n' && !check_line(tab[i]++, 32))
			close_program("Error\nInvalid data", data);
		j = i;
		while (tab[++j] && x != 6)
			if (ft_strnstr(tab[j], trgts[x], ft_strlen(trgts[x])))
				close_program("Error\nMultiple entries for given field", data);
	}
	return ;
}
