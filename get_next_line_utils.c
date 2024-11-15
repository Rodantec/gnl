/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rodantec <rodantec@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/04 12:41:38 by rodantec          #+#    #+#             */
/*   Updated: 2024/11/15 13:24:46 by rodantec         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"


char	*ft_strchr(const char *s, int c)
{
	int	i;

	i = 0;
	while (s[i] && s[i] != (char)c)
		i++;
	if (s[i] == (char)c)
		return ((char *)&s[i]);
	return ((char *) NULL);
}

size_t	ft_strlen(const char *s)
{
	size_t	i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*join;
	int		i;
	int		j;

	if (!s1 || !s2)
		return (NULL);
	i = 0;
	j = 0;
	join = malloc(sizeof(char) * (ft_strlen(s1) + ft_strlen(s2) + 1));
	if (!join)
		return (NULL);
	while (s1[i])
	{
		join[i] = s1[i];
		i++;
	}
	while (s2[j])
	{
		join[i] = s2[j];
		i++;
		j++;
	}
	join[i] = '\0';
	return (join);
}

char	*ft_strdup(const char *s1)
{
	char	*dest;
	int		i;
	int		j;

	j = ft_strlen(s1);
	i = 0;
	dest = malloc(sizeof(*s1) * (j + 1));
	if (!dest)
		return (NULL);
	while (s1[i])
	{
		dest[i] = s1[i];
		i++;
	}
	dest[i] = 0;
	return (dest);
}

char *ft_isnewline(int fd)
{
	int bytes_read;
	char buffer[BUFFER_SIZE];
	char *line;
	char *new_line;
	
	line = ft_strdup("");
	while ((bytes_read = read(fd,buffer,BUFFER_SIZE)) > 0)
    {
		buffer[bytes_read] = '\0';
		new_line = ft_strjoin(line, buffer);
		free(line);
		line = new_line;
		if(ft_strchr(buffer, '\n'))
			break;
	}
		return(line);
}
        
