/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbucci <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/16 11:05:15 by mbucci            #+#    #+#             */
/*   Updated: 2022/05/16 13:18:36 by mbucci           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	ft_set_save(char *save, char *text)
{
	if (save)
	{
		free(save);
		save = NULL;
	}
	save = ft_strdup(text);
	if (text)
	{
		free(text);
		text = NULL;
	}
}

static int	save_read_fd(char *save, int fd)
{
	char	buff[BUFFER_SIZE + 1];
	int		bytes_read;
	char	*swap;

	bytes_read = read(fd, buff, BUFFER_SIZE);
	if (bytes_read)
	{
		buff[bytes_read] = '\0';
		swap = ft_strjoin(save, buff);
		ft_set_save(save, swap);
	}
	return (bytes_read);
}

static char	*get_line(char *save, char *nlptr)
{
	char	*tmp;
	char	*line;

	if (!nlptr)
	{
		line = ft_strdup(save);
		if (save)
			free(save);
		save = NULL;
		return (line);
	}
	*nlptr = '\0';
	tmp = ft_strdup(save);
	line = ft_strjoin(tmp, "\n");
	if (tmp)
		free(tmp);
	nlptr = ft_strdup(nlptr + 1);
	ft_set_save(save, nlptr);
	return (line);
}

char	*get_next_line(int fd)
{
	char			testbuff;
	static char		*save;
	int				bytes_saved;
	char			*nlptr;

	if (fd < 0 || (read(fd, &testbuff, 0) < 0 && !ft_strlen(save)))
		return (NULL);
	if (!save)
		save = ft_strdup("");
	nlptr = ft_strchr(save, '\n');
	while (!nlptr)
	{
		bytes_saved = save_read_fd(save, fd);
		if (!bytes_saved)
			break ;
		nlptr = ft_strchr(save, '\n');
	}
	if (ft_strlen(save))
		return (get_line(save, nlptr));
	if (save)
	{
		free(save);
		save = NULL;
	}
	return (NULL);
}
