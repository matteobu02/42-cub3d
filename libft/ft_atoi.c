/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbucci <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/17 16:19:41 by mbucci            #+#    #+#             */
/*   Updated: 2022/05/17 16:34:46 by mbucci           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_atoi(char const *str)
{
	long	n;
	int		s;
	int		i;

	if (!str)
		return (0);
	i = 0;
	while (str[i] >= 9 && str[i] <= 13)
		i++;
	s = 1;
	if (str[i] == '-' || str[i] == '+')
		if (str[i++] == '-')
			s = -1;
	n = 0;
	while (str[i] > 47 && str[i] < 58)
		n = (n * 10) + str[i++] - 48;
	if (n > INT_MAX && s == 1)
		return (-1);
	if (n > INT_MIN && s == -1)
		return (0);
	return (n * s);
}
