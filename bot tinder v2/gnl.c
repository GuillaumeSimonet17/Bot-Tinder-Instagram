#include <unistd.h>
#include <stdlib.h>
#include "read.h"

#ifndef BUFFER_SIZE
# define BUFFER_SIZE 1
#endif

int    ft_strlen(char *str)
{
    int    i;

    i = 0;
    while (str[i])
        i++;
    return (i);
}

char    *ft_strjoin(char *s1, char *s2)
{
    int        i;
    int        j;
    int        joinlen;
    char    *join;

    if (!s1)
    {
        s1 = malloc(1);
        *s1 = 0;
    }
    joinlen = ft_strlen(s1) + ft_strlen(s2);
    join = malloc(joinlen + 1);
    i = -1;
    while (s1[++i])
        join[i] = s1[i];
    j = 0;
    while (s2[j])
        join[i++] = s2[j++];
    join[i] = 0;
    free(s1);
    return (join);
}

char *get_next_line(int fd)
{
    char    buffer[BUFFER_SIZE + 1];
    char    *line;
    int        readlen;

    if (fd < 0 || BUFFER_SIZE <= 0)
        return (0);
    line = 0;
    while (1)
    {
        readlen = read(fd, buffer, BUFFER_SIZE);
        if (readlen == -1)
            return (0);
        if (readlen == 0)
            return (line);
        buffer[BUFFER_SIZE] = 0;
        line = ft_strjoin(line, buffer);
        if (buffer[0] == '\n')
            return (line);
    }
}