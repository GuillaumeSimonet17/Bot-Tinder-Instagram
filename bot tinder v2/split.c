#include "read.h"

void	*ft_calloc(size_t elementCount, size_t elementSize)
{
	unsigned char	*bloc;
	size_t			i;

	i = 0;
	if (elementSize != 0 && elementCount > SIZE_MAX / elementSize)
		return (NULL);
	bloc = (void *)malloc((elementCount * elementSize));
	if (!bloc)
		return (NULL);
	while (i < elementCount * elementSize)
	{
		bloc[i] = 0;
		i++;
	}
	return (bloc);
}

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*new;
	size_t	i;

	i = 0;
	if (!s)
		return (NULL);
	if (len > ft_strlen((char *)s) - start)
		len = ft_strlen((char *)s) - start;
	if (start > (unsigned)ft_strlen((char *)s))
	{
		new = malloc(sizeof(char) * 1);
		if (!new)
			return (NULL);
		new[i] = 0;
		return (new);
	}
	new = malloc(sizeof(char) * (len + 1));
	if (!new)
		return (NULL);
	while (s[start] && i < len && s[start] != '\n')
		new[i++] = s[start++];
	new[i] = 0;
	return (new);
}

static char	**ft_clear_all(char **strs, int a)
{
	while (a >= 0)
	{
		free(strs[a]);
		a--;
	}
	free(strs);
	return (0);
}

static int	ft_nb_str(char const *s, char c)
{
	int	nb_str;
	int	i;

	nb_str = 0;
	i = 0;
	while (s[i])
	{
		if (s[i] == c)
		{
			while (s[i] == c)
			i++;
		}
		if (s[i] == '\0')
			break ;
		while (s[i] && s[i] != c)
			i++;
		nb_str++;
	}
	return (nb_str);
}

char	**ft_scan(char const *s, char **strs, char c, int i)
{
	int	start;
	int	j;

	start = 0;
	j = 0;
	while (s[i])
	{
		if (s[i] == c)
			while (s[i] == c)
				i++;
		if (s[i] == '\0')
			break ;
		start = i;
		while (s[start] && s[start] != c)
			start ++;
		strs[j] = ft_substr(s, i, start - i);
        // if (strs[j][0] == '\n')
        //     dprintf(2, "oui\n");
		if (!strs[j])
			return (ft_clear_all(strs, j - 1));
		j++;
		i = start;
	}
	return (strs);
}

char	**ft_split(char const *s, char c)
{
	char	**strs;

	if (!s)
		return (0);
	strs = ft_calloc(sizeof(char *), ft_nb_str(s, c) + 1);
	if (!strs)
		return (NULL);
	return (ft_scan(s, strs, c, 0));
}