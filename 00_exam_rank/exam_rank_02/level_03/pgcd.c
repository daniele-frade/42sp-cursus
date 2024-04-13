/*
Assignment name  : pgcd
Expected files   : pgcd.c
Allowed functions: printf, atoi, malloc, free
--------------------------------------------------------------------------------

Write a program that takes two strings representing two strictly positive
integers that fit in an int.

Display their highest common denominator followed by a newline (It's always a
strictly positive integer).

If the number of parameters is not 2, display a newline.

Examples:

$> ./pgcd 42 10 | cat -e
2$
$> ./pgcd 42 12 | cat -e
6$
$> ./pgcd 14 77 | cat -e
7$
$> ./pgcd 17 3 | cat -e
1$
$> ./pgcd | cat -e
$
*/

#include <stdio.h>
#include <stdlib.h>

int	main(int argc, char **argv)
{
	int	number_01;
	int	number_02;
	int	result;
	int	div;

	number_01 = 0;
	number_02 = 0;
	result = 1;
	div = 1;
	if (argc == 3)
	{
		number_01 = atoi(argv[1]);
		number_02 = atoi(argv[2]);
		while (div < number_01 && div < number_02)
		{
			if ((number_01 % div) == 0 && (number_02 % div == 0))
			{
				result = div;
			}
			div++;
		}
		printf("%d", result);
	}
	printf("\n");
	return (0);
}
