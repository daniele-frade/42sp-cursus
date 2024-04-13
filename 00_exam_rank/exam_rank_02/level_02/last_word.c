/*
Assignment name  : last_word
Expected files   : last_word.c
Allowed functions: write
--------------------------------------------------------------------------------

Write a program that takes a string and displays its last word followed by a \n.

A word is a section of string delimited by spaces/tabs or by the start/end of
the string.

If the number of parameters is not 1, or there are no words, display a newline.

Example:

$> ./last_word "FOR PONY" | cat -e
PONY$
$> ./last_word "this        ...       is sparta, then again, maybe    not" | cat -e
not$
$> ./last_word "   " | cat -e
$
$> ./last_word "a" "b" | cat -e
$
$> ./last_word "  lorem,ipsum  " | cat -e
lorem,ipsum$
$>
*/

#include <unistd.h>

int	main(int argc, char **argv)
{
	int	i;
	int	word_index;

	if (argc == 2)
	{
		i = 0;
		word_index = -1;
		while (argv[1][i])
		{
			while (argv[1][i] && (argv[1][i] == ' ' || argv[1][i] == '\t'))
				i++;
			if (argv[1][i] != '\0')
				word_index = i;
			while (argv[1][i] && (argv[1][i] != ' ' && argv[1][i] != '\t'))
				i++;
		}
		while (argv[1][word_index] && (argv[1][word_index] != ' ' && argv[1][word_index] != '\t'))
		{
			write(1, &argv[1][word_index], 1);
			word_index++;
		}
	}
	write(1, "\n", 1);
	return (0);
}
