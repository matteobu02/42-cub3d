/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_map.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbucci <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/18 21:38:12 by mbucci            #+#    #+#             */
/*   Updated: 2022/05/18 23:40:47 by mbucci           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	deep_check_map(char **tab, t_main *data)
{
	char const	*trgts[6] = {"NO", "SO", "WE", "EA", "C", "F"};
	int			i;
	int			j;
	int			x;
	int			count;

	i = -1;
	while (tab[++i])
	{
		x = -1;
		while (++x < 6)
			if (ft_strnstr(tab[i], trgts[x], ft_strlen(trgts[x])))
				break ;
		if (ft_isfull(tab[i], '1'))
			break ;
		if (x == 6 && (!ft_isspace(*tab[i]) || *tab[i] != '\n'))
		
		j = i;
		count = 0;
		while (tab[++j])
			if (ft_strnstr(tab[i], trgts[x], ft_strlen(trgts[x])))
	}
}
