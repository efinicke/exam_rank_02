#include "gnl.h"

static int	crush_first_c(char *str, char c1, char c2)
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
	static char	*bigstring = NULL;
	char		buf[BUFFER_SIZE + 1];
	char		*line;
	char		*tmp;
	int			i;
	int			ret;

	ret = 1;
	tmp = NULL;
	line = NULL;
	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	while (((i = crush_first_c(bigstring, '\n', '\0')) == -1)
		&& ((ret = read(fd, buf, BUFFER_SIZE)) != 0))
	{
		if (ret == -1)
			return (NULL);
		buf[ret] = '\0';
		bigstring = ft_strjoin_free(bigstring, buf);
	}
	line = ft_strdup(bigstring);
	if (i != -1)
	{
		tmp = bigstring;
		bigstring = ft_strdup(&bigstring[i + 1]);
		free(tmp);
	}
	if (ret == 0 && bigstring == NULL)
		return (NULL);
	if (ret == 0)
	{
		free(bigstring);
		bigstring = NULL;
		return (line);
	}
	line = ft_strjoin_free(line, "\n");
	return (line);
}
