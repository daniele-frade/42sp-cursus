/*
Assignment name  : tab_mult
Expected files   : tab_mult.c
Allowed functions: write
--------------------------------------------------------------------------------

Write a program that displays a number's multiplication table.

The parameter will always be a strictly positive number that fits in an int,
and said number times 9 will also fit in an int.

If there are no parameters, the program displays \n.

Examples:

$>./tab_mult 9
1 x 9 = 9
2 x 9 = 18
3 x 9 = 27
4 x 9 = 36
5 x 9 = 45
6 x 9 = 54
7 x 9 = 63
8 x 9 = 72
9 x 9 = 81
$>./tab_mult 19
1 x 19 = 19
2 x 19 = 38
3 x 19 = 57
4 x 19 = 76
5 x 19 = 95
6 x 19 = 114
7 x 19 = 133
8 x 19 = 152
9 x 19 = 171
$>
$>./tab_mult | cat -e
$
$>
*/

#include <unistd.h>

int	ft_atoi(char *str)
{
	int	i;
	int	signal;
	int	result;

	i = 0;
	signal = 1;
	result = 0;
	while (str[i] == ' ' || (str[i] >= 9 && str[i] <= 13))
		i++;
	if (str[i] == '+' || str[i] == '-')
	{
		if (str[i] == '-')
			signal = -1;
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9')
	{
		result = (result * 10) + (str[i] - '0');
		i++;
	}
	return (result * signal);
}

void	ft_putnbr(int number)
{
	char base[] = "0123456789";
	if (number > 9)
		ft_putnbr(number / 10);
	write (1, &base[number % 10], 1);
}

int	main(int argc, char **argv)
{
	int	mult;
	int	number;

	mult = 1;
	if (argc == 2)
	{
		number = ft_atoi(argv[1]);
		while (mult < 10)
		{
			ft_putnbr(mult);
			write(1, " x ", 3);
			ft_putnbr(number);
			write(1, " = ", 3);
			ft_putnbr(number * mult);
			write(1, "\n", 1);
			mult++;
		}
	}
	else
		write(1, "\n", 1);
}
