/*
Assignment name  : rostring
Expected files   : rostring.c
Allowed functions: write, malloc, free
--------------------------------------------------------------------------------

Write a program that takes a string and displays this string after rotating it
one word to the left.

Thus, the first word becomes the last, and others stay in the same order.

A "word" is defined as a part of a string delimited either by spaces/tabs, or
by the start/end of the string.

Words will be separated by only one space in the output.

If there's less than one argument, the program displays \n.

Example:

$>./rostring "abc   " | cat -e
abc$
$>
$>./rostring "Que la      lumiere soit et la lumiere fut"
la lumiere soit et la lumiere fut Que
$>
$>./rostring "     AkjhZ zLKIJz , 23y"
zLKIJz , 23y AkjhZ
$>
$>./rostring "first" "2" "11000000"
first
$>
$>./rostring | cat -e
$
$>
*/

#include <unistd.h>

int	main(int argc, char **argv)
{
	int	i;
	int	first_word;
	int	flag;

	if (argc >= 2)
	{
		i = 0;
		flag = 0;
		while (argv[1][i] == ' ' || argv[1][i] == '\t')
			i++;
		first_word = i;
		while (argv[1][i] && (argv[1][i] != ' ' && argv[1][i] != '\t'))
			i++;
		while (argv[1][i])
		{
			while (argv[1][i] == ' ' || argv[1][i] == '\t')
				i++;
			while (argv[1][i] && (argv[1][i] != ' ' && argv[1][i] != '\t'))
			{
				write(1, &argv[1][i], 1);
				i++;
				flag = 1;
			}
			while (argv[1][i] == ' ' || argv[1][i] == '\t')
				i++;
			if (argv[1][i] != '\0')
				write(1, " ", 1);
		}
		if (flag == 1)
			write(1, " ", 1);
		while (argv[1][first_word] && (argv[1][first_word] != ' ' && argv[1][first_word] != '\t'))
		{
			write(1, &argv[1][first_word], 1);
			first_word++;
		}
	}
	write(1, "\n", 1);
	return (0);
}
