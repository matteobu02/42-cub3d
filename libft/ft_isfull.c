/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isfull.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbucci <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/18 23:27:28 by mbucci            #+#    #+#             */
/*   Updated: 2022/05/18 23:30:13 by mbucci           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_isfull(char const *str, int c)
{
	int	count;

	if (!str)
		return (0);
	count = -1;
	while (str[++count])
		if (str[count] != c)
			return (0);
	return (1);
}
