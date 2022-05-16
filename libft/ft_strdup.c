/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbucci <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/13 14:00:25 by mbucci            #+#    #+#             */
/*   Updated: 2022/05/13 15:35:04 by mbucci           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(char const *str)
{
	char	*new;
	int		i;

	if (!str)
		return (NULL);
	new = (char *)malloc(ft_strlen(str) + 1);
	if (!new)
		return (NULL);
	i = -1;
	while (str[++i])
		new[i] = str[i];
	new[i] = 0;
	return (new);
}
