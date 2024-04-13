/*
Assignment name  : print_hex
Expected files   : print_hex.c
Allowed functions: write
--------------------------------------------------------------------------------

Write a program that takes a positive (or zero) number expressed in base 10,
and displays it in base 16 (lowercase letters) followed by a newline.

If the number of parameters is not 1, the program displays a newline.

Examples:

$> ./print_hex "10" | cat -e
a$
$> ./print_hex "255" | cat -e
ff$
$> ./print_hex "5156454" | cat -e
4eae66$
$> ./print_hex | cat -e
$
*/

#include <unistd.h>

int	ft_atoi(char *str)
{
	int	i;
	int	result;
	int	signal;

	i = 0;
	result = 0;
	signal = 1;
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

void	ft_putnbr(unsigned int nbr)
{
	char hex_index[] = "0123456789abcdef";
	if (nbr > 15)
		ft_putnbr(nbr / 16);
	write(1, &hex_index[nbr % 16], 1);
}

int	main(int argc, char **argv)
{
	int	number;

	if (argc == 2)
	{
		number = ft_atoi(argv[1]);
		ft_putnbr(number);
	}
	write(1, "\n", 1);
}
