/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_utils2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbucci <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/22 15:45:27 by mbucci            #+#    #+#             */
/*   Updated: 2022/06/22 16:05:55 by mbucci           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

char	*get_path(char *s)
{
	char	*ret;
	int		i;

	ret = (char *)malloc(ft_strlen(s));
	if (!ret)
		return (NULL);
	i = -1;
	while (s[++i] && s[i] != '\n')
		ret[i] = s[i];
	ret[i] = '\0';
	return (ret);
}
