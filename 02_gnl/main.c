#include "gnl.h"

int            main(void)
{
    int        fd;
    char    *line;
    int         i;

    i = 0;    
    line = NULL;
    fd = open("test.txt", O_RDONLY);
    while ((line = get_next_line(fd)) != NULL)
    {
        ft_putendl((unsigned char *)line);
        free(line);
    }
    ft_putendl((unsigned char *)line);
    close(fd);
    
	printf("\nTest de LEAKS\n");
	system("leaks a.out | grep leaked\n"); 
	return (0);
}
