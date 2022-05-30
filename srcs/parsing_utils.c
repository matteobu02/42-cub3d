/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbucci <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/23 12:34:30 by mbucci            #+#    #+#             */
/*   Updated: 2022/05/30 17:35:06 by mbucci           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

char	*skip_spaces(char const *str, char const *target)
{
	char	*tmp;
	char	*tmp2;

	tmp = (char *)str;
	while (*tmp && ft_isspace(*tmp))
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

int	get_map_width(char const **tab)
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
