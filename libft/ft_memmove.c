/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbucci <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/16 11:27:55 by mbucci            #+#    #+#             */
/*   Updated: 2022/05/16 11:43:15 by mbucci           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	char	*dst_ptr;
	char	*src_ptr;

	if (!dst || !src || len < 1 || dst == src)
		return (dst);
	dst_ptr = (char *)dst;
	src_ptr = (char *)src;
	if (dst > src)
		while (len-- > 0)
			*(dst_ptr + len) = *(src_ptr + len);
	else
		while (len-- > 0)
			*dst_ptr++ = *src_ptr++;
	return (dst);
}
