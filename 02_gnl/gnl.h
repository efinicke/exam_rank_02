#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

 #ifndef BUFFER_SIZE
 # define BUFFER_SIZE 10
 #endif


# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include <fcntl.h>


int		ft_strlen(char *s);
char    *ft_strdup(char *str);
void    ft_putendl(unsigned char *str);
char	*ft_strjoin_free(char *bigstring, char *buf);
char	*get_next_line(int fd);

#endif
