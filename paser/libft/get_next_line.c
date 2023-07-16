/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkaiyawo <kkaiyawo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/06 17:56:06 by kkaiyawo          #+#    #+#             */
/*   Updated: 2023/04/05 09:48:20 by kkaiyawo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*gnl_fnr(char **s1)
{
	if (*s1)
	{
		free(*s1);
		*s1 = NULL;
	}
	return (NULL);
}

char	*gnl_split(char **buf)
{
	char	*line;
	char	*tmp;
	char	*ptr;

	if (ft_strlen(*buf) == 0)
		return (gnl_fnr(buf));
	tmp = ft_strchr(*buf, 10);
	if (tmp == NULL)
	{
		line = *buf;
		*buf = 0;
		return (line);
	}
	line = *buf;
	ptr = *buf;
	if (line[tmp + 1 - ptr] != 0)
		*buf = ft_strdup(tmp + 1);
	else
		*buf = NULL;
	line[tmp + 1 - ptr] = 0;
	return (line);
}

char	*get_next_line(int fd)
{
	static char	*buf[OPEN_MAX];
	char		*tmp;
	ssize_t		read_len;
	size_t		len;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	while (ft_strchr(buf[fd], '\n') == NULL)
	{
		len = ft_strlen(buf[fd]);
		tmp = buf[fd];
		buf[fd] = (char *) ft_calloc(len + BUFFER_SIZE + 1, 1);
		if (!buf[fd])
			return (NULL);
		len = ft_strlcpy(buf[fd], tmp, len + 1);
		if (tmp != NULL)
			gnl_fnr(&tmp);
		read_len = read(fd, buf[fd] + len, BUFFER_SIZE);
		if (read_len < 0)
			return (gnl_fnr(&buf[fd]));
		if (read_len == 0)
			break ;
		buf[fd][len + read_len] = 0;
	}
	return (gnl_split(&buf[fd]));
}
