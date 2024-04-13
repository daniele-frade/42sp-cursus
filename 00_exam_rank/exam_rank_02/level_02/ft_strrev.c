/*
Assignment name  : ft_strrev
Expected files   : ft_strrev.c
Allowed functions:
--------------------------------------------------------------------------------

Write a function that reverses (in-place) a string.

It must return its parameter.

Your function must be declared as follows:

char    *ft_strrev(char *str);
*/

#include <stdio.h>

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

char	*ft_strrev(char *str)
{
	int		start_index;
	int		last_index;
	char	temp_swap;

	start_index = 0;
	last_index = ft_strlen(str) - 1;
	while (start_index < last_index)
	{
		temp_swap = str[last_index];
		str[last_index] = str[start_index];
		str[start_index] = temp_swap;
		last_index--;
	}
	return (str);
}
