/*
Assignment name  : ft_atoi_base
Expected files   : ft_atoi_base.c
Allowed functions: None
--------------------------------------------------------------------------------

Write a function that converts the string argument str (base N <= 16)
to an integer (base 10) and returns it.

The characters recognized in the input are: 0123456789abcdef
Those are, of course, to be trimmed according to the requested base. For
example, base 4 recognizes "0123" and base 16 recognizes "0123456789abcdef".

Uppercase letters must also be recognized: "12fdb3" is the same as "12FDB3".

Minus signs ('-') are interpreted only if they are the first character of the
string.

Your function must be declared as follows:

int	ft_atoi_base(const char *str, int str_base);
*/

int	can_i_use_this_char(char c, int base)
{
	char	*char_base;
	int		result;
	int		i;

	result = 0;
	if (c >= 'A' && c <= 'F')
		char_base = "0123456789ABCDEF";
	else
		char_base = "0123456789abcdef";
	i = 0;
	while (i < base)
	{
		if (char_base[i] == c)
			result = 1;
		i++;
	}
	return (result);
}

int	ft_atoi_base(const char *str, int str_base)
{
	int	signal;
	int	result;
	int	i;

	i = 0;
	result = 0;
	signal = 1;
	if (str[i] == '-')
	{
		signal = -1;
		i++;
	}
	while ((str[i] >= '0' && str[i] <= '9') || (str[i] >= 'a' && str[i] <= 'f') || (str[i] >= 'A' && str[i] <= 'F'))
	{
		if (is_base(str[i], str_base) == 1)
		{
			result = result * str_base;
			if (str[i] >= '0' && str[i] <= '9')
				result = result + (str[i] - '0');
			else if (str[i] >= 'a' && str[i] <= 'f')
				result = result + (str[i] - 'a' + 10);
			else if (str[i] >= 'A' && str[i] <= 'F')
				result = result + (str[i] - 'A' + 10);
		}
		else
			break ;
		i++;
	}
	return (result * signal);
}
