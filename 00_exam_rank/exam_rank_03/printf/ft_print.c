/*
Expected files: ft_printf.c

Allowed Functions: malloc, free, write, va_start, va_arg, va_copy and va_end
Prototype: int ft_printf(const char *, ... )

Write a function named ft_printf that will mimic the real printf but it will manage only the following conversions:

s (string)
d (decimal) 
x (lowercase hexademical)

Output Examples:
call: ft_printf("%s\n", "toto")
out: toto$
call: ft_printf("Magic %s is %d", "number", 42)
out: Magic number is 42%
call: ft_printf("Hexadecimal for %d is %x\n", 42, 42)
out: Hexadecimal for 42 is 2a$
*/

#include <unistd.h>
#include <stdarg.h>

int	ft_putchar(char c);
int	ft_putstr(char *str);
int	ft_putnbr(long int nbr);
int	ft_puthex(unsigned int nbr);
int	ft_format_handler(va_list args, char str);


int	ft_printf(const char *str, ...)
{
	va_list	args;
	int		length;
	int		i;

	if (str == NULL)
		return (-1);

	va_start(args, str);
	length = 0;
	i = 0;

	while (str[i])
	{
		if (str[i] == '%')
		{
			i++;
			length = length + ft_format_handler(args, str[i]);
		}
		else
			length = length + ft_putchar(str[i]);
		i++;
	}
	va_end(args);
	return (length);
}

int	ft_putchar(char c)
{
	write(1, &c, 1);
	return (1);
}

int	ft_putstr(char *str)
{
	int	length;

	length = 0;
	if (str == NULL)
		return (ft_putstr("(null)"));

	while (str[length])
	{
		write(1, &str[length], 1);
		length++;
	}
	return (length);
}

int	ft_putnbr(long int nbr)
{
	int	length = 0;
	char index[] = "0123456789";

	if (nbr < 0)
	{
		length = length + ft_putchar('-');
		nbr = nbr * -1;
	}

	if (nbr > 9)
		length = length + ft_putnbr(nbr / 10);
	length = length + ft_putchar(index[nbr % 10]);
	return (length);
}

int	ft_puthex(unsigned int nbr)
{
	int	length;

	length = 0;
	char index[] = "0123456789abcdef";
	if(nbr > 15)
		length = length + ft_puthex(nbr / 16);
	length = length + ft_putchar(index[nbr % 16]);
	return (length);
}

int	ft_format_handler(va_list args, char str)
{
	int	length;

	length = 0;
	if (str == 's')
		length = length + ft_putstr(va_arg(args, char *));
	else if (str == 'd' || str == 'i')
		length = length + ft_putnbr(va_arg(args, int));
	else if (str == 'x')
		length = length + ft_puthex(va_arg(args, unsigned int));
	return (length);
}

