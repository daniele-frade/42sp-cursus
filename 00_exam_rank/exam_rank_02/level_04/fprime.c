/*
Assignment name  : fprime
Expected files   : fprime.c
Allowed functions: printf, atoi
--------------------------------------------------------------------------------

Write a program that takes a positive int and displays its prime factors on the
standard output, followed by a newline.

Factors must be displayed in ascending order and separated by '*', so that
the expression in the output gives the right result.

If the number of parameters is not 1, simply display a newline.

The input, when there is one, will be valid.

Examples:

$> ./fprime 225225 | cat -e
3*3*5*5*7*11*13$
$> ./fprime 8333325 | cat -e
3*3*5*5*7*11*13*37$
$> ./fprime 9539 | cat -e
9539$
$> ./fprime 804577 | cat -e
804577$
$> ./fprime 42 | cat -e
2*3*7$
$> ./fprime 1 | cat -e
1$
$> ./fprime | cat -e
$
$> ./fprime 42 21 | cat -e
$
*/

// Relembrando decomposição em fatores primos: 
// 1 - Escolha o menor número primo que divide o número
// 2 - Continue dividindo pelo menor primo até não ser mais divisível
// 3 - Repita o processo até obter fatores primos
// 4 - Escreva a decomposição em fatores primos
// 4 é divisível por 2, então dividimos por 2, ficando com 12; 
// 12 é divisível por 2, então dividimos por 2 novamente, ficando com 6;
// 6 é divisível por 2, então dividimos por 2 mais uma vez, ficando com 3;
// Agora, 3 é um número primo, então paramos.
// A decomposição em fatores primos de 24 é, portanto, 2 * 2 * 2 * 3. 
// Esses são os fatores primos que, quando multiplicados, resultam em 24.

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
	if (str[i] == '-' || str[i] == '+')
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
	char index[] = "0123456789";
	if (number > 9)
		ft_putnbr(number / 10);
	write(1, &index[number % 10], 1);
}

int	main(int argc, char **argv)
{
	int	number;
	int	divisor;

	divisor = 2;
	if (argc == 2)
	{
		number = ft_atoi(argv[1]);
		if (number == 1)
			ft_putnbr(number);
		while (number >= 2)
		{
			if (number % divisor == 0)
			{
				ft_putnbr(divisor);
				number = number / divisor;
				if (number != 1)
					write(1, "*", 1);
			}
			else
				divisor++;
		}
	}
	write(1, "\n", 1);
	return (0);
}
