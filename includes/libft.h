/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbucci <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/10 14:11:14 by mbucci            #+#    #+#             */
/*   Updated: 2022/05/12 14:29:46 by mbucci           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include <unistd.h>
# include <stdlib.h>

void	ft_putendl_fd(char const *str, int const fd);
int		ft_strcmp(char const *s1, char const *s2);
char	*ft_strrstr(char const *haystack, char const *needle);
int		ft_strlen(char const *str);

#endif
