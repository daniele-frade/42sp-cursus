/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_handling.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dfrade <dfrade@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/07 15:49:58 by dfrade            #+#    #+#             */
/*   Updated: 2023/12/08 19:14:45 by dfrade           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	has_syntax_error(char *str)
{
	if (!str || !*str)
		return (1);
	if (*str == '-' || *str == '+')
		str++;
	if (*str == '\0')
		return (1);
	while (*str != '\0')
	{
		if (!ft_isdigit(*str))
			return (1);
		else
			str++;
	}
	return (0);
}

int	has_range_error(long long nb)
{
	if (nb < INT_MIN || nb > INT_MAX)
		return (1);
	else
		return (0);
}

int	has_duplication_error(t_node *stack_a, int nb)
{
	if (stack_a == NULL)
		return (0);
	while (stack_a)
	{
		if (stack_a->value == nb)
			return (1);
		stack_a = stack_a->next;
	}
	return (0);
}

int	print_error(char *str)
{
	int	length;

	if (str == NULL)
		return (ft_putstr("(null)"));
	length = 0;
	while (str[length] != '\0')
	{
		write(2, &str[length], 1);
		length++;
	}
	return (length);
}
