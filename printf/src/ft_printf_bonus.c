/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dfrade <dfrade@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/09 14:06:25 by dfrade            #+#    #+#             */
/*   Updated: 2023/09/09 17:31:31 by dfrade           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_bonus.h" 

int	ft_printf(const char *string, ...)
{
	va_list	args;
	size_t	i;
	int		length;

	if (string == NULL)
		return (-1);
	va_start(args, string);
	i = 0;
	length = 0;
	while (string[i] != '\0')
	{
		if (string[i] == '%')
		{
			i++;
			while (string[i] == '#' || string[i] == '+' || string[i] == ' ')
				i++;
			length += ft_format_handler(args, string[i], string[i - 1]);
		}
		else
			length += ft_putchar(string[i]);
		i++;
	}
	va_end(args);
	return (length);
}

int	ft_format_handler(va_list args, char format, char flag)
{
	int	length;

	length = 0;
	if (format == 'c')
		length += ft_putchar((char)va_arg(args, int));
	else if (format == 's')
		length += ft_putstr(va_arg(args, char *));
	else if (format == 'p')
		length += ft_putptr(va_arg(args, unsigned long), HEX_LW);
	else if (format == 'd' || format == 'i')
		length += ft_putnbr_base_flag(va_arg(args, int), DEC, flag);
	else if (format == 'u')
		length += ft_putnbr_base(va_arg(args, unsigned int), DEC);
	else if (format == 'x')
		length += ft_putnbr_base_flag(va_arg(args, unsigned int), HEX_LW, flag);
	else if (format == 'X')
		length += ft_putnbr_base_flag(va_arg(args, unsigned int), HEX_UP, flag);
	else if (format == '%')
		length += ft_putchar('%');
	return (length);
}

int	ft_putnbr_base_flag(long int nb, char *base, char flag)
{
	int	length;

	length = 0;
	if ((flag == '+') && (nb >= 0))
		length += ft_putchar('+');
	else if ((flag == ' ') && (nb >= 0))
		length += ft_putchar(' ');
	else if ((flag == '#') && (nb > 0))
	{
		if (ft_strcmp (base, HEX_LW) == 0)
		{
			length += ft_putchar('0');
			length += ft_putchar('x');
		}
		else if (ft_strcmp (base, HEX_UP) == 0)
		{
			length += ft_putchar('0');
			length += ft_putchar('X');
		}
	}
	length += ft_putnbr_base(nb, base);
	return (length);
}

int	ft_strcmp(const char *s1, const char *s2)
{
	int	i;

	i = 0;
	while ((s1[i] == s2[i]) && (s1[i] != '\0') && (s2[i] != '\0'))
		i++;
	return (s1[i] - s2[i]);
}
