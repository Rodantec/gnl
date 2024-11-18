/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rodantec <rodantec@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/04 12:41:27 by rodantec          #+#    #+#             */
/*   Updated: 2024/11/18 12:10:35 by rodantec         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
char *ft_extract(char **stash)
{
	int		i;
	char	*line;
	char *new_stash;
	
	i = 0;
	while ((*stash)[i] && (*stash)[i] != '\n')
		i++;
	line = malloc(sizeof(char) * (i + 1 + ((*stash)[i] == '\n')));
	if (!line)
		return (NULL);
	i = 0;
	while ((*stash)[i] && (*stash)[i] != '\n')
	{
		line[i] = (*stash)[i];
		i++;
	}
	if ((*stash)[i] == '\n')
		line[i++] = '\n';
	line[i] = '\0';
	new_stash = ft_strdup(*stash + i );
    free(*stash);
    *stash = new_stash;
	return (line);
}

char	*get_next_line(int fd)
{
    static char	*stash;
    char *line;
    char *tmp;
    
    if (fd < 0)
		return (NULL);
    if(!stash)
        stash = ft_isnewline(fd);
         
    else
    {
        tmp = ft_strjoin(stash,ft_isnewline(fd));
        free(stash);
        stash = tmp;
    }
    if (!stash || *stash == '\0') // Handle EOF or empty stash
    {
        free(stash);
        stash = NULL;
        return (NULL);
    }
    line = ft_extract(&stash);
    return (line);
  
}


// int main(void)
// {
//     int fd = open("test.txt", O_RDONLY);
//     if (fd == -1)
//     {
//         perror("Failed to open file");
//         return 1;
//     }

//     char *line = get_next_line(fd);
//     char *line2 = get_next_line(fd);
//      char *line3 = get_next_line(fd);
//      char *line4 = get_next_line(fd);
//      char *line5 = get_next_line(fd);
//     // char *line5 = get_next_line(fd);
//     // char *line6 = get_next_line(fd);
//     //  char *line7 = get_next_line(fd);
//     //   char *line8 = get_next_line(fd);
//     //    char *line9 = get_next_line(fd);
//     //     char *line10 = get_next_line(fd);
//         printf( "%s", line);
//        printf("%s", line2);
//          printf("%s", line3);
//         printf("%s", line4);
//         printf("%s", line5);
//         free(line);
//         free(line2);
//         free(line3);
//         free(line4);
//         free(line5);
//         // printf( // "%s", line5);
//         // printf("%s", line6);
//         // printf("%s", line7);
//         // printf("%s", line8);
//         // printf("%s", line9);
//         // printf("%s", line10);
       
//          // N'oubliez pas de libérer la mémoire allouée pour la ligne
//     close(fd);
//     return 0;
// }

