# include <unistd.h>
# include <stdarg.h>
# include <stdio.h>
# include <string.h>
# include <limits.h>

int ret;

int     ft_strlen(char *str)
{
    int i;

    i = 0;
    while (str[i])
        i++;
    return (i);
}

void    ft_putchar(char c)
{
    write(1, &c, 1);
    ret++;
}

void    ft_putstr(char *str)
{
    int i;

    i = -1;
    if (!str)
        str = "(null)";
    while (str[++i])
        ft_putchar(str[i]);
}

void	ft_hexa_putnbr(unsigned int nbr, char tab[16])
{
    (nbr > 15) ? ft_hexa_putnbr(nbr / 16, tab) : ft_putchar(tab[nbr]);
	(nbr > 15) ? ft_putchar(tab[nbr % 16]) : 0;
}

void    ft_putnbr(int nbr)
{
	long	n;

	n = nbr;
    (n < 0) ? ft_putchar('-') : 0;
	n = (n < 0) ? n * -1 : n;
	(n > 9) ? ft_putnbr(n / 10) : ft_putchar(n + 48);
	(n > 9) ? ft_putchar((n % 10) + 48) : 0;
}

int     ft_printf(const char *str, ...)
{
    va_list(params);
    int i;

    i = -1;
    ret = 0;
    if (str == NULL)
        return (-1);
    va_start(params, str);
    while (str[++i])
    {
        if (str[i] == '%')
        {
            i++;
            if (str[i] == 's')
                ft_putstr(va_arg(params, char *));
            else if (str[i] == 'd')
                ft_putnbr(va_arg(params, int));
            else if (str[i] == 'x')
                ft_hexa_putnbr(va_arg(params, unsigned int), "0123456789abcdef");
            else
            {
                write(1, &str[i], 1);
                ret++;
            }
        }
        else
        {
            write(1, &str[i], 1);
            ret++;
        }
    }
    va_end(params);
    return (ret);
}

int     main(void)
{
    //int x = 0;
    //int x = -1;
    //int x = 505543;
    //int x = UINT_MAX;
    //
    //int d = INT_MIN;
    //int d = INT_MAX;
    //int d = 0;
    //int d = -25665;
    //int d = 25654;
    //
    //char *str = "string";
    char *str = NULL;

    int ret = 0;

    //ret = ft_printf("%x\n", x);
    //ret = printf("%d\n", d);
    ret = ft_printf("%%\n", str);

    //ret = ft_printf("%x\n", x);
    //ret = ft_printf("%d\n", d);
    //ret = ft_printf("%s\n", str);

    //printf("%d\n", ret);
    //printf("%d\n", ret);
    printf("%d\n", ret);

    return (0);
}