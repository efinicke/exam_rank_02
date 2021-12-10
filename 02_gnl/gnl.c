#include "gnl.h"

static int		crush_first_c(char *str, char c1, char c2)
{
	int	i;

	i = -1;
	if (!str)
		return (-1);
	while (str[++i])
	{
		if (str[i] == c1)
		{
			str[i] = c2;
			return (i);
		}
	}
	return (-1);
}

char	*get_next_line(int fd)
{
	static char	*bigstring;
	char		buf[BUFFER_SIZE + 1];
	char        *line;
	int			ret;
	int			i;
	char 		*tmp;

	ret = 1;
	if (fd < 0 || BUFFER_SIZE <= 0)
		return (0);
	while (((i = crush_first_c(bigstring, '\n', '\0')) == -1) 
			&& ((ret = read(fd, buf, BUFFER_SIZE)) != 0))
	{
		if (ret == -1)
			return (NULL);
		buf[ret] = '\0';
		bigstring = ft_strjoin_free(bigstring, buf);
	}
	line = ft_strdup(bigstring);
	tmp = bigstring;
	bigstring = ft_strdup(&bigstring[i + 1]);
	free(tmp);
	if (ret == 0)
	{
		free(line);
		return (NULL);
	}
	return (line);
}
