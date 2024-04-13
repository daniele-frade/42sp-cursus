/*
Assignment name  : ft_itoa
Expected files   : ft_itoa.c
Allowed functions: malloc
--------------------------------------------------------------------------------

Write a function that takes an int and converts it to a null-terminated string.
The function returns the result in a char array that you must allocate.

Your function must be declared as follows:

char	*ft_itoa(int nbr);
*/

#include <stdlib.h>

int	count_digits(int nbr)
{
	int	digits;

	digits = 1;
	while (nbr / 10 != 0)
	{
		nbr = nbr / 10;
		digits++;
	}
	return (digits);
}

char	*ft_itoa(int nbr)
{
	char	*str;
	int		is_negative;
	int		qtd_digits;
	long	copy_number;

	copy_number = nbr;
	is_negative = 0;

	if (nbr < 0)
		is_negative = 1;
	qtd_digits = count_digits(nbr);

	str = malloc((qtd_digits + is_negative + 1) * sizeof(char));
	if (str == NULL)
		return (NULL);

	if (is_negative == 1)
		str[0] = '-';
	if (nbr == 0)
		str[0] = '0';
	str[qtd_digits + is_negative] = '\0';

	if (copy_number < 0)
		copy_number = copy_number * -1;
	while (copy_number != 0)
	{
		str[(qtd_digits + is_negative) - 1] = (copy_number % 10) + '0';
		copy_number = copy_number / 10;
		qtd_digits--;
	}
	return (str);
}

