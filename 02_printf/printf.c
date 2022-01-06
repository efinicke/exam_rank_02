# include <unistd.h>
# include <stdarg.h>
# include <stdio.h>
# include <string.h>
# include <limits.h>

int ret;

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

	ret = 0;
    i = -1;
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
				ft_putchar(str[i]);
        }
        else
			ft_putchar(str[i]);
    }
    va_end(params);
    return (ret);
}

int     main(void)
{
    //int x = 0;
    //int x = -122;
    //int x = 505543;
    int x = UINT_MAX;
    //int d = INT_MIN;
    //int d = INT_MAX;
    //int d = 0;
	//int d = 9999999999999999999;
    //int d = -25665;
    //int d = 25654;
    //char *str = "string";
    //char *str = NULL;

    int rret;
	int fret;

    //fret = ft_printf("d = %d\n", d);
    //rret = printf("d = %d\n", d);
    
	fret = ft_printf("x = %x\n", x);
    rret = printf("x = %x\n", x);
    
	//fret = ft_printf("%%s%w%%w\n");
	//rret = printf("%%s%w%%w\n");

    //printf("ret_real : %d\n", fret);
    //printf("ret_fake : %d\n", rret);

    return (0);
}
