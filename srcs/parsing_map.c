/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_map.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbucci <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/19 17:56:17 by mbucci            #+#    #+#             */
/*   Updated: 2022/05/23 13:12:35 by mbucci           ###   ########.fr       */
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
	while (tmp[++i] && tmp[i] != '.')
	{
		if (!ft_isspace(tmp[i]))
			close_program("Error\nInvalid data between identifier and path",
				data);
	}
	--i;
	while (tmp[++i] && !ft_isspace(tmp[i]))
		;
	if (tmp[i] != '\n' && i != ft_strlen(tmp))
		close_program("Error\nInvalid data after path", data);
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
	while (tab[++i])
	{
		if (check_line(tab[i], '1'))
			break ;
		x = -1;
		while (++x < 6)
			if (skip_spaces(tab[i], targets[x]))
				break ;
		if (x < 4)
			check_valid_line(tab[i], targets[x], data);
		if (x == 6 && *tab[i] != '\n' && !check_line(tab[i], 32))
			close_program("Error\nInvalid data", data);
		j = i;
		while (tab[++j] && x != 6)
			if (skip_spaces(tab[j], targets[x]))
				close_program("Error\n2 entries for same identifier", data);
	}
	return ;
}

/*int		**produce_map(char **tab, int start, t_main *data)
{
	int	**ret;


}

void	get_map(char **tab, t_main *data)
{
	char const	*trgts[6] = {"NO", "SO", "WE", "EA", "F", "C"};
	int			i;
	int			c;
	int			x;

	i = -1;
	c = 0;
	while (tab[++i] && c < 6)
	{
		x = -1;
		while (++x < 6 && !ft_strnstr(tab[i], trgts[x], ft_strlen(trgts[x])))
			;
		if (x == 6)
			continue ;
		else
			c++;
	}
	while (tab[i] && check_line(tab[i], 32))
		i++;
	data->map->map = produce_map(tab, i, data);
}*/
