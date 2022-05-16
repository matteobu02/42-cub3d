/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbucci <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/16 12:47:31 by mbucci            #+#    #+#             */
/*   Updated: 2022/05/16 13:15:29 by mbucci           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	c = (char)c;
	if (!s)
		return (NULL);
	if (!c)
		return ((char *)s + ft_strlen(s));
	while (s && *s && *s != c)
		s++;
	if (*s == c)
		return ((char *)s);
	return (NULL);
}
