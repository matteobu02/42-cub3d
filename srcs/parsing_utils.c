/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbucci <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/23 12:34:30 by mbucci            #+#    #+#             */
/*   Updated: 2022/05/24 14:40:51 by mbucci           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

char	*skip_spaces(char const *str, char const *target)
{
	char	*tmp;

	tmp = (char *)str;
	while (*tmp && ft_isspace(*tmp))
		tmp++;
	return (ft_strnstr(tmp, target, ft_strlen(target)));
}

/*int	get_map_width(char **tab, int start)
{
	int	ret;
	int	i;

	i = start - 1;
	while (tab[++i])

}*/
