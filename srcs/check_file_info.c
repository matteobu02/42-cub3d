/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_file_info.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbucci <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/19 17:56:17 by mbucci            #+#    #+#             */
/*   Updated: 2022/06/22 13:51:11 by mbucci           ###   ########.fr       */
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

int	check_line(char const *str, int c)
{
	int	i;

	if (!str)
		return (0);
	i = 0;
	while (str[i] && (ft_isspace(str[i]) || str[i] == '\n' || str[i] == c))
		i++;
	if (i == ft_strlen(str))
	{
		if (!ft_isspace(c) && !ft_strchr(str, c))
			return (0);
		else
			return (1);
	}
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
		close_program(NO_SPACE_ENTRY_ERROR, data);
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
