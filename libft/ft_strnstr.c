/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbucci <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/13 12:22:09 by mbucci            #+#    #+#             */
/*   Updated: 2022/05/13 16:03:36 by mbucci           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(char const *haystack, char const *needle, size_t len)
{
	size_t	i;
	size_t	j;
	size_t	needle_len;

	if (!*needle)
		return ((char *)haystack);
	if (!haystack || len < 1)
		return (NULL);
	i = -1;
	needle_len = ft_strlen(needle);
	while (haystack[++i] && i < len)
	{
		j = 0;
		if (haystack[i] != needle[j])
			continue ;
		while (haystack[i + j] == needle[j] && haystack[i + j] && i + j < len)
			if (j++ == needle_len - 1)
				return ((char *)&haystack[i]);
	}
	return (NULL);
}
/*
#include <stdio.h>
int	main(int ac, char **av)
{
	if (ac > 1)
		printf("%s\n", find_in_tab(av, "NO"));
	return (0);
}*/
