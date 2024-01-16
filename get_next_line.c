/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkerroum < tkerroum@student.1337.ma>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/16 13:38:58 by tkerroum          #+#    #+#             */
/*   Updated: 2024/01/16 18:03:24 by tkerroum         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char *read_fd(int fd,char *line)
{
	char 	*buffer;
	ssize_t	read_return;
	
	read_return = 1;
	buffer = malloc((size_t)BUFFER_SIZE + 1);
	if(!buffer)
		return (NULL);
	while (read_return && ft_strchr(line,'\n') == -1)
	{
		read_return = read(fd, buffer, BUFFER_SIZE);
		if (read_return == -1)
		{
			free(line);
			free(buffer);
			return (NULL);
		}
		buffer[read_return] = '\0';
		line = ft_strjoin(line, buffer);
		if(!line)
			return (NULL);
	}
	free(buffer);
	return (line);
}

char	*set_the_line(char *str)
{
	int	len;
	int	i;
	char	*line;

	if(!str)
		return (NULL);
	i = 0;
	len = ft_strchr(str,'\n') + 1;
	if(!len)
		return (ft_strdup(str));
	line = (char *)malloc(len + 1);
	if(!line)
		return (NULL);
	while(i < len)
	{
		line[i] = str[i];
		i++;
	}
	line[i] = '\0';
	return (line);	
}

char	*rest_of_the_line(char *static_line)
{
	size_t	len;
	char	*saved_line;

	len = ft_strchr(static_line,'\n') + 1;
	if (!len)
	{
		free(static_line);
		return (NULL);
	}
	saved_line = ft_strdup(static_line + len);
	free(static_line);
	return (saved_line);	
}

char *get_next_line(int fd)
{
	static char *static_line;
	char 		*new_line;
	
	if(fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	static_line = read_fd(fd,static_line);
	if(!static_line)
		return (free(static_line),NULL);
	new_line = set_the_line(static_line);
	static_line = rest_of_the_line(static_line);
	return (new_line);
}

