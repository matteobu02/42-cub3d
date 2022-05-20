/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbucci <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/13 16:12:08 by mbucci            #+#    #+#             */
/*   Updated: 2022/05/20 17:27:37 by mbucci           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	*free_map(t_map *ptr)
{
	if (ptr)
	{
		if (ptr->map)
			ptr->map = ft_free_tab((void **)ptr->map);
		if (ptr->no)
			free(ptr->no);
		if (ptr->so)
			free(ptr->so);
		if (ptr->we)
			free(ptr->we);
		if (ptr->ea)
			free(ptr->ea);
		free(ptr);
	}
	return (NULL);
}
