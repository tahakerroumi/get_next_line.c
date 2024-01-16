/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkerroum < tkerroum@student.1337.ma>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/16 13:43:41 by tkerroum          #+#    #+#             */
/*   Updated: 2024/01/16 16:44:16 by tkerroum         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
#define GET_NEXT_LINE_H

#ifndef BUFFER_SIZE
#define BUFFER_SIZE 25
#endif

# include <fcntl.h>
# include <stddef.h>
# include <stdint.h>
# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <unistd.h>

int ft_strlen(char *s);
int	ft_strchr(char *s,char c);
char	*ft_strjoin(char *s1, char *s2);
char	*ft_strdup(char *s);
int	ft_strlen(char *s);
char *read_fd(int fd,char *line);
char	*set_the_line(char *str);
char	*rest_of_the_line(char *static_line);
char *get_next_line(int fd);


#endif