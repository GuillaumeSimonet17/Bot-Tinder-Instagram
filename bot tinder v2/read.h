#ifndef READ_H
#define READ_H

#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
# include <sys/wait.h>


// GNL:
int    ft_strlen(char *str);
char    *ft_strjoin(char *s1, char *s2);
char *get_next_line(int fd);

// SPLIT:
char	**ft_split(char const *s, char c);

#endif