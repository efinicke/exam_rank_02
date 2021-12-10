#include <unistd.h>


void    ft_inter(char *s1, char *s2)
{
    int ascii[256] = {0};
    int i;

    i = -1;
    while (s2[++i])
    {
        if (ascii[(int)s2[i]] == 0)
            ascii[(int)s2[i]] = 1;
    }

    i = -1;
    while (s1[++i])
    {
        if (ascii[(int)s1[i]] == 1)
        {
            ascii[(int)s1[i]] = 2;
            write (1, &s1[i], 1);
        }
    }
}

int main(int argc, char **argv)
{
    if (argc == 3)
        ft_inter(argv[1], argv[2]);
    write(1, "\n", 1);
    return (0);
}