#include "read.h"

int	ft_strncmp(const char *s1, const char *s2, size_t length)
{
	size_t	i;

	i = 0;
	while (((unsigned char)s1[i] || (unsigned char)s2[i]) && i < length)
	{
		if ((unsigned char)s1[i] < (unsigned char)s2[i])
			return (1);
		if ((unsigned char)s1[i] > (unsigned char)s2[i])
			return (1);
		else
			i++;
	}
	return (0);
}

int ft_strnstr(const char *big, const char *little, size_t len)
{
	size_t	i;
	size_t	j;

	i = 0;
	if ((big == NULL || little == NULL) && len == 0)
		return (0);
	if (((unsigned char *)little)[0] == '\0')
		return (1);
	while (big[i] && i < len)
	{
		j = 0;
		while (big[i + j] == little[j] && i + j < len)
		{
			if (ft_strncmp((char *)&big, (char *)little, ft_strlen \
			((char *)little))
				&& little[j + 1] == '\0')
				return (1);
			j++;
		}
		i++;
	}
	return (0);
}

int     verify_if_ig(char *s)
{
    if (ft_strnstr(s, "insta", ft_strlen(s)))
        return 1;
    if (ft_strnstr(s, "instagram", ft_strlen(s)))
        return 1;
    if (ft_strnstr(s, "Instagram", ft_strlen(s)))
        return 1;
    if (ft_strnstr(s, "Insta", ft_strlen(s)))
        return 1;
    if (ft_strnstr(s, "ig", ft_strlen(s)))
        return 1;
    if (ft_strnstr(s, "Ig", ft_strlen(s)))
        return 1;
    if (ft_strnstr(s, "IG", ft_strlen(s)))
        return 1;
    if (ft_strnstr(s, "@", ft_strlen(s)))
        return 1;
    return 0;
}

void    ft_putchar(char c, int fd_out)
{
    write(fd_out, &c, 1);
}

int	ft_cmp(const char *s1, const char *s2, size_t length)
{
	size_t	i;

	i = 0;
	while (((unsigned char)s1[i] || (unsigned char)s2[i]) && i < length)
	{
		if ((unsigned char)s1[i] < (unsigned char)s2[i])
			return (0);
		if ((unsigned char)s1[i] > (unsigned char)s2[i])
			return (0);
		else
			i++;
	}
	return (1);
}

int     ft_no_need_to_write(char *s)
{
    if (ft_cmp(s, ":", ft_strlen((char *)s)))
        return 1;
    if (ft_cmp(s, "insta", ft_strlen((char *)s)))
        return 1;
    if (ft_cmp(s, "\"insta", ft_strlen((char *)s)))
        return 1;
    if (ft_cmp(s, "insta:", ft_strlen((char *)s)))
        return 1;
    if (ft_cmp(s, "\"insta:", ft_strlen((char *)s)))
        return 1;
    if (ft_cmp(s, "Insta:", ft_strlen((char *)s)))
        return 1;
    if (ft_cmp(s, "\"Insta:", ft_strlen((char *)s)))
        return 1;
    if (ft_cmp(s, "Insta", ft_strlen((char *)s)))
        return 1;
    if (ft_cmp(s, "\"Insta", ft_strlen((char *)s)))
        return 1;
    if (ft_cmp(s, "\"ig", ft_strlen((char *)s)))
        return 1;
    if (ft_cmp(s, "\"ig ", ft_strlen((char *)s)))
        return 1;
    if (ft_cmp(s, "ig", ft_strlen((char *)s)))
        return 1;
    if (ft_cmp(s, "ig:", ft_strlen((char *)s)))
        return 1;
    if (ft_cmp(s, "ig: ", ft_strlen((char *)s)))
        return 1;
    if (ft_cmp(s, "\"ig:", ft_strlen((char *)s)))
        return 1;
    if (ft_cmp(s, "\"ig: ", ft_strlen((char *)s)))
        return 1;
    if (ft_cmp(s, "Ig:", ft_strlen((char *)s)))
        return 1;
    if (ft_cmp(s, "\"Ig:", ft_strlen((char *)s)))
        return 1;
    if (ft_cmp(s, "\"IG:", ft_strlen((char *)s)))
        return 1;
    if (ft_cmp(s, "IG:", ft_strlen((char *)s)))
        return 1;
    if (ft_cmp(s, "IG", ft_strlen((char *)s)))
        return 1;
    if (ft_cmp(s, "Instagram", ft_strlen((char *)s)))
        return 1;
    if (ft_cmp(s, "\"Instagram", ft_strlen((char *)s)))
        return 1;
    if (ft_cmp(s, "Instagram:", ft_strlen((char *)s)))
        return 1;
    if (ft_cmp(s, "\"Instagram:", ft_strlen((char *)s)))
        return 1;
    if (ft_cmp(s, "intelligente", ft_strlen((char *)s)))
        return 1;
    if (ft_cmp(s, "intelligent", ft_strlen((char *)s)))
        return 1;
    if (ft_cmp(s, "Intelligente", ft_strlen((char *)s)))
        return 1;
    if (ft_cmp(s, "Intelligent", ft_strlen((char *)s)))
        return 1;
    if (ft_cmp(s, "original", ft_strlen((char *)s)))
        return 1;
    if (ft_cmp(s, "origine", ft_strlen((char *)s)))
        return 1;
    if (ft_cmp(s, "origines", ft_strlen((char *)s)))
        return 1;
    if (ft_cmp(s, "d'origine", ft_strlen((char *)s)))
        return 1;
    if (ft_cmp(s, "rigole", ft_strlen((char *)s)))
        return 1;
    if (ft_cmp(s, "rigoler", ft_strlen((char *)s)))
        return 1;
    if (ft_cmp(s, "rigolot", ft_strlen((char *)s)))
        return 1;
    if (ft_cmp(s, "rigolote", ft_strlen((char *)s)))
        return 1;
    if (ft_cmp(s, "lignes", ft_strlen((char *)s)))
        return 1;
    if (ft_cmp(s, "ligne", ft_strlen((char *)s)))
        return 1;
    if (ft_cmp(s, "signe", ft_strlen((char *)s)))
        return 1;
    if (ft_cmp(s, "signes", ft_strlen((char *)s)))
        return 1;
    if (ft_cmp(s, "design", ft_strlen((char *)s)))
        return 1;
    if (ft_cmp(s, "Designe", ft_strlen((char *)s)))
        return 1;
    if (ft_cmp(s, "designer", ft_strlen((char *)s)))
        return 1;
    if (ft_cmp(s, "Designer", ft_strlen((char *)s)))
        return 1;
    if (ft_cmp(s, "le", ft_strlen((char *)s)))
        return 1;
    if (ft_cmp(s, "Le", ft_strlen((char *)s)))
        return 1;
    if (ft_cmp(s, "je", ft_strlen((char *)s)))
        return 1;
    if (ft_cmp(s, "Je", ft_strlen((char *)s)))
        return 1;
    if (ft_cmp(s, "moi", ft_strlen((char *)s)))
        return 1;
    if (ft_cmp(s, "oui", ft_strlen((char *)s)))
        return 1;
    if (ft_cmp(s, "tu", ft_strlen((char *)s)))
        return 1;
    if (ft_cmp(s, "suis", ft_strlen((char *)s)))
        return 1;
    if (ft_cmp(s, "sur", ft_strlen((char *)s)))
        return 1;
    if (ft_cmp(s, "et", ft_strlen((char *)s)))
        return 1;
    if (ft_cmp(s, "'", ft_strlen((char *)s)))
        return 1;
    return 0;
}

void    ft_putstr(const char *s, int fd_out)
{
    int i;
    
    i = 0;
    if (ft_no_need_to_write((char *)s))
        return ;
    if (s[i] == '"')
        i++;
    if (s[i] == '@')
        i++;
    if (s[i] == ':')
        i++;
    while(s[i] && s[i] != '"')
        ft_putchar(s[i++], fd_out);
    ft_putchar('\n', fd_out);
}

void    ft_split_and_write(char *s, int fd_out)
{    
    char **tab = NULL;
    int i = 0;

    tab = ft_split(s, ' ');
    while (tab[i])    
        ft_putstr(tab[i++], fd_out);
}

void    ft_read(int fd_in, int fd_out)
{
    char *line = NULL;
    line = get_next_line(fd_in);
    if (verify_if_ig(line))
        ft_split_and_write(line, fd_out);
    while (line)
    {
        line = get_next_line(fd_in);
        if (!line)
            return ;
        if (verify_if_ig(line))
            ft_split_and_write(line, fd_out);
    }
}

int main()
{
    int fd_in = open("tinder_data.txt", O_RDONLY);
    int fd_out = open("new_tinder_data.txt", O_RDWR | O_APPEND, 0644);
    if (fd_in > -1 && fd_out > -1)
        ft_read(fd_in, fd_out);
    else
        printf("fd non valide\n");
    close(fd_in);

    return 0;
}
