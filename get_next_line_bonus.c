/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkerroum < tkerroum@student.1337.ma>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/18 11:46:44 by tkerroum          #+#    #+#             */
/*   Updated: 2024/01/18 19:01:01 by tkerroum         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

static char	*ft_free(char *buffer)
{
	free (buffer);
	return (NULL);
}

static char	*read_fd(int fd, char *line)
{
	char	*buffer;
	ssize_t	read_return;

	buffer = malloc((size_t)BUFFER_SIZE + 1);
	if (!buffer)
		return (NULL);
	read_return = 1;
	while (read_return && ft_strchr(line, '\n') == -1)
	{
		read_return = read(fd, buffer, BUFFER_SIZE);
		if (read_return == -1)
		{
			free(line);
			ft_free(buffer);
		}
		buffer[read_return] = '\0';
		line = ft_strjoin(line, buffer);
		if (!line)
		{
			ft_free(buffer);
		}
	}
	free (buffer);
	return (line);
}

static char	*set_the_line(char *str)
{
	int		len;
	int		i;
	char	*line;

	if (!*str)
		return (NULL);
	i = 0;
	len = ft_strchr(str, '\n') + 1;
	if (!len)
		return (ft_strdup(str));
	line = (char *)malloc((size_t)len + 1);
	if (!line)
		return (NULL);
	while (i < len)
	{
		line[i] = str[i];
		i++;
	}
	line[i] = '\0';
	return (line);
}

static char	*rest_of_the_line(char	*static_line)
{
	size_t	len;
	char	*saved_line;

	len = ft_strchr(static_line, '\n') + 1;
	if (!len)
	{
		free (static_line);
		return (NULL);
	}
	saved_line = ft_strdup(static_line + len);
	free (static_line);
	return (saved_line);
}

char	*get_next_line(int fd)
{
	static char	*static_line[1024];
	char		*new_line;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	static_line[fd] = read_fd(fd, static_line[fd]);
	if (!static_line[fd])
		return (NULL);
	new_line = set_the_line(static_line[fd]);
	static_line[fd] = rest_of_the_line(static_line[fd]);
	return (new_line);
}