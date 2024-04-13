/*
Assignment name	: ft_strspn
Expected files	: ft_strspn.c
Allowed functions: None
---------------------------------------------------------------

Reproduce exactly the behavior of the strspn function 
(man strspn).

The function should be prototyped as follows:

size_t	ft_strspn(const char *s, const char *accept);
*/

#include <unistd.h>

size_t	ft_strspn(const char *s, const char *accept)
{
	size_t	len;
	size_t	j;

	len = 0;
	j = 0;
	while (s[len])
	{
		j = 0;
		while (accept[j])
		{
			if (s[len] == accept[j])
				break ;
			j++;
		}
		if (accept[j] == '\0')
			break ;
		len++;
	}
	return (len);
}
