/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbucci <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/16 11:05:15 by mbucci            #+#    #+#             */
/*   Updated: 2022/05/18 13:58:31 by mbucci           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	find_nl(char *s)
{
	int	count;

	if (!s)
		return (-1);
	count = 0;
	while (*s)
	{
		if (*s++ == '\n')
			return (count);
		count++;
	}
	return (-1);
}

static char	*get_final_buffer(char *s)
{
	char	*str;
	size_t	i;
	size_t	j;

	i = 0;
	j = 0;
	while (s && s[i] && s[i] != '\n')
		i++;
	if (!s[i])
	{
		free(s);
		return (NULL);
	}
	str = (char *)malloc(ft_strlen(s) - (i - 1));
	if (!str)
		return (ft_free_str(s));
	i++;
	while (s[i])
		str[j++] = s[i++];
	str[j] = '\0';
	free(s);
	return (str);
}

char	*get_next_line(int fd)
{
	static char	*text;
	char		buff[BUFFER_SIZE + 1];
	char		*line;
	int			read_val;
	int			len_line;

	if (fd < 0 || fd > FOPEN_MAX || (read(fd, NULL, 0) < 0) || BUFFER_SIZE < 1)
		return (NULL);
	read_val = 1;
	while (read_val > 0 && find_nl(text) == -1)
	{
		read_val = read(fd, buff, BUFFER_SIZE);
		buff[read_val] = '\0';
		text = ft_strjoin(text, buff);
		if (!text)
			return (NULL);
	}
	len_line = find_nl(text) + 1;
	if (!len_line)
		len_line = ft_strlen(text);
	line = ft_substr(text, 0, len_line);
	text = get_final_buffer(text);
	return (line);
}
