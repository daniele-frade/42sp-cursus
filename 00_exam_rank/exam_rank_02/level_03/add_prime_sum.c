/*
Assignment name  : add_prime_sum
Expected files   : add_prime_sum.c
Allowed functions: write, exit
--------------------------------------------------------------------------------

Write a program that takes a positive integer as argument and displays the sum
of all prime numbers inferior or equal to it followed by a newline.

If the number of arguments is not 1, or the argument is not a positive number,
just display 0 followed by a newline.

Yes, the examples are right.

Examples:

$>./add_prime_sum 5
10
$>./add_prime_sum 7 | cat -e
17$
$>./add_prime_sum | cat -e
0$
$>
*/

#include <unistd.h>

int ft_atoi(char *str)
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
	if(number > 9)
		ft_putnbr (number / 10);
	write(1, &index[number % 10], 1);
}

int	main(int argc, char **argv)
{
	int	number;
	int	result;
	int	i;
	int	j;

	result = 0;
	if (argc == 2)
	{
		number = ft_atoi(argv[1]);
		if (number <= 1)
		{
			write(1, "0\n", 2);
			return (0);
		}
		int	primes[number];
		while (number > 0)
		{
			primes[number - 1] = number;
			number--;
		}
		number = ft_atoi(argv[1]);
		primes[0] = 0;
		i = 1;
		while (i < number)
		{
			j = i - 1;
			while (j > 0)
			{
				if (primes[j] != 0)
				{
					if (primes[i] % primes[j] == 0)
						break ;
				}
				j--;
			}
			if (j == 0)
				i++;
			else
			{
				primes[i] = 0;
				i++;
			}
		}
		i = 0;
		while (i < number)
		{
			result = result + primes[i];
			i++;
		}
		ft_putnbr(result);
		write(1, "\n", 1);
	}
	else
		write(1, "0\n", 2);
	return (0);
}
