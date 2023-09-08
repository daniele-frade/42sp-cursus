/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils_bonus.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dfrade <dfrade@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/30 11:36:44 by dfrade            #+#    #+#             */
/*   Updated: 2023/09/07 15:04:51 by dfrade           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_bonus.h"

int	ft_strlen(char *str)
{
	int	length;

	length = 0;
	while (str[length])
		length++;
	return (length);
}

int	ft_putchar(char c)
{
	write(1, &c, 1);
	return (1);
}

int	ft_putstr(char *str)
{
	int	length;

	if (str == NULL)
		return (ft_putstr("(null)"));
	length = 0;
	while (str[length] != '\0')
	{
		write(1, &str[length], 1);
		length++;
	}
	return (length);
}

int	ft_putnbr_base(long int nb, char *base)
{
	int	length;
	int	base_length;

	length = 0;
	base_length = ft_strlen(base);
	if (nb < 0)
	{
		length = length + ft_putchar('-');
		nb = nb * -1;
	}
	if (nb >= base_length)
		length = length + ft_putnbr_base((nb / base_length), base);
	length = length + ft_putchar(base[nb % base_length]);
	return (length);
}

int	ft_putptr(unsigned long nb, char *base)
{
	int	length;
	int	base_length;

	length = 0;
	base_length = ft_strlen(base);
	if (nb == 0)
		return (ft_putstr("(nil)"));
	if (nb >= (unsigned long)base_length)
		length = length + ft_putptr((nb / base_length), base);
	else
		length = length + ft_putstr("0x");
	length = length + ft_putchar(base[nb % base_length]);
	return (length);
}
