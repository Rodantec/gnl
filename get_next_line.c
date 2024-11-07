/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rodantec <rodantec@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/04 12:41:27 by rodantec          #+#    #+#             */
/*   Updated: 2024/11/07 13:23:33 by rodantec         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_next_line(int fd)
{
    if (fd < 0)
		return (NULL);
    char *buffer;
	static char	*stash;
    char *line ;
    int bytes_read;
    int i;

    i = 0;
    bytes_read = 0;
	buffer = malloc(sizeof(char) * BUFFER_SIZE + 1);
    if (!stash)
        return (NULL);
    bytes_read = read(fd,buffer,BUFFER_SIZE); // a voir comment remplir le stash
    stash = ft_isnewline(buffer);
    return (stash);
}


int main(void)
{
    int fd = open("test.txt", O_RDONLY);
    if (fd == -1)
    {
        perror("Failed to open file");
        return 1;
    }

    char *line;
    while ((line = get_next_line(fd)) != NULL)
    {
        printf("Line: %s", line);
        free(line);  // N'oubliez pas de libérer la mémoire allouée pour la ligne
    }
    close(fd);
    return 0;
}

