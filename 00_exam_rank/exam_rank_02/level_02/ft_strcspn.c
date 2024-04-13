/*
Assignment name	: ft_strcspn
Expected files	: ft_strcspn.c
Allowed functions: None
---------------------------------------------------------------

Reproduce exactly the behavior of the function strcspn
(man strcspn).

The function should be prototyped as follows:

size_t	ft_strcspn(const char *s, const char *reject);
*/

#include <unistd.h>

size_t	ft_strcspn(const char *s, const char *reject)
{
	size_t	len;
	size_t	j;

	len = 0;
	j = 0;
	while (s[len])
	{
		j = 0;
		while (reject[j])
		{
			if (s[len] == reject[j])
				return (len);
			j++;
		}
		len++;
	}
	return (len);
}
