/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbucci <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/16 11:17:53 by mbucci            #+#    #+#             */
/*   Updated: 2022/05/16 11:27:36 by mbucci           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*ret;
	size_t	len1;
	size_t	len2;

	if (!s1 && !s2)
		return (ft_strdup(""));
	if (!s1 && s2)
		return (ft_strdup(s2));
	if (s1 && !s2)
		return (ft_strdup(s1));
	len1 = ft_strlen(s1);
	len2 = ft_strlen(s2);
	ret = (char *)malloc(len1 + len2 + 1);
	if (!ret)
		return (NULL);
	ft_memmove(ret, s1, len1);
	ft_memmove(ret, s2, len2);
	ret[len1 + len2] = 0;
	return (ret);
}
