/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkerroum < tkerroum@student.1337.ma>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/16 13:50:04 by tkerroum          #+#    #+#             */
/*   Updated: 2024/01/16 16:59:58 by tkerroum         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	ft_strchr(char *s,char c)
{
	int i;

	i = 0;
	if (!s)
		return (-1);
	while(s[i])
	{
		if(s[i] == c)
			return (i);
		i++;
	}
	return (-1);
}

char	*ft_strjoin(char *s1, char *s2)
{
	int		i;
	int 	j;
	char	*str;

	if (!s1)
		return (ft_strdup(s2));
	if (!s2)
		return (NULL);
	str = (char *)malloc((sizeof(char)) * (ft_strlen(s1) + ft_strlen(s2) + 1));
	if (!str)
		return (NULL);
	i = 0;
	while (s1[i])
	{
		str[i] = s1[i];
		i++;
	}
	j = 0;
	while (s2[j])
	{
		str[i] = s2[j];
		i++;
		j++;
	}
	str[i] = '\0';
	free(s1);
	return (str);
}

char	*ft_strdup(char *s)
{
	char	*str;
	size_t	len;
	int		i;

	len = ft_strlen(s);
	str = (char *)malloc((sizeof(char) * (len + 1)));
	if (!str)
		return (NULL);
	i = 0;
	while (s[i])
	{
		str[i] = s[i];
		i++;
	}
	str[i] = '\0';
	return (str);
}

int	ft_strlen(char *s)
{
	size_t i;
	
	i = 0;
	while (s[i])
		i++;
	return (i);
}