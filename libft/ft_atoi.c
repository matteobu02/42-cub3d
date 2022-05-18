/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbucci <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/17 16:19:41 by mbucci            #+#    #+#             */
/*   Updated: 2022/05/18 16:38:58 by mbucci           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_atoi(const char *str)
{
	int					i;
	int					s;
	unsigned long int	n;

	i = 0;
	while (ft_isspace(str[i]))
		i++;
	s = 1;
	if (str[i] == '+' || str[i] == '-')
		if (str[i++] == '-')
			s = -1;
	n = 0;
	while (ft_isdigit(str[i]))
	{
		n = n * 10 + (str[i] - 48);
		if (n > 2147483647 && s == 1)
			return (-1);
		if (n > 2147483648 && s == -1)
			return (0);
		i++;
	}
	return (n * s);
}
