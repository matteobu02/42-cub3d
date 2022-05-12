/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbucci <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/12 13:54:20 by mbucci            #+#    #+#             */
/*   Updated: 2022/05/12 14:16:08 by mbucci           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrstr(char const *haystack, char const *needle)
{
	char	*tmp;
	int		i;
	int		back_indx;

	if (!haystack || !needle)
		return (NULL);
	tmp = (char *)haystack;
	i = -1;
	back_indx = ft_strlen(haystack) - ft_strlen(needle);
	while (ft_strcmp(tmp + back_indx - ++i, needle))
		if (i == back_indx)
			return (NULL);
	return (tmp + back_indx - i);
}
