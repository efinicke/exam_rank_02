#include "gnl.h"

int		ft_strlen(char *str)
{
	int i;

	i = 0;
	if (!str)
		return (0);
	while (str[i])
		i++;
	return (i);
}

char	*ft_strdup(char *s1)
{
	char *s2;
	char *stmp;

	s2 = malloc(sizeof(*s1) * (ft_strlen(s1) + 1));
	if (!s2)
		return (NULL);
	stmp = s2;
	while (*s1)
		*s2++ = *s1++;
	*s2 = '\0';
	return (stmp);
}

void ft_putendl(unsigned char *str)
{
    static int i;

    i = 0;
    if (!str)
    {
        write(1, "(null)", 8);
        return ;
    }
    while (*str)
    {
        write(1, &(*str), 1);
        str++;
    }
    write(1, "\n", 1);
}

char	*ft_strjoin_free(char *bigstring, char *buf)
{
	char	*tab;
	int		len = ft_strlen(bigstring) + ft_strlen(buf);
	int 	j;
	int		i;

	i = 0;
	j = 0;
	if (!(tab = malloc(sizeof(char) * (len + 1))))
		return (NULL);
	while (bigstring && bigstring[i])
	{
		tab[i] = bigstring[i];
		i++;
	}
	while (buf && buf[j])
	{
		tab[i + j] = buf[j];
		j++;
	}
	free(bigstring);
	tab[i + j] = '\0';
	return (tab);
}
