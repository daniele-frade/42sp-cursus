/*
Assignment name  : max
Expected files   : max.c
Allowed functions:
--------------------------------------------------------------------------------

Write the following function:

int		max(int* tab, unsigned int len);

The first parameter is an array of int, the second is the number of elements in
the array.

The function returns the largest number found in the array.

If the array is empty, the function returns 0.
*/

int	max(int	*tab, unsigned int len)
{
	int	max;
	int	i;

	if (len > 0)
	{
		i = 0;
		max = tab[i];
		while (len > 0)
		{
			if (tab[i] > max)
				max = tab[i];
			len--;
			i++;
		}
		return (max);
	}
	return (0);
}
