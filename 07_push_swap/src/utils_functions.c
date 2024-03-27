/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_functions.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dfrade <dfrade@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/07 15:51:40 by dfrade            #+#    #+#             */
/*   Updated: 2023/12/08 18:54:06 by dfrade           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	argv_count(char **argv)
{
	int	i;

	i = 0;
	while (argv[i] != NULL)
		i++;
	return (i);
}

int	ft_isdigit(int c)
{
	if (c >= '0' && c <= '9')
		return (1);
	return (0);
}

long	ft_atol(const char *str)
{
	long	num;
	int		is_neg;
	int		i;

	num = 0;
	is_neg = 1;
	i = 0;
	while (str[i] && (str[i] == ' ' || str[i] == '\t'
			|| str[i] == '\n' || str[i] == '\r'
			|| str[i] == '\v' || str[i] == '\f'))
		i++;
	if (str[i] == '+')
		i++;
	else if (str[i] == '-')
	{
		is_neg *= -1;
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9')
	{
		num = (num * 10) + (str[i] - '0');
		i++;
	}
	return (num * is_neg);
}

void	call_operations(t_node	**stack_a, t_node **stack_b, char *op)
{
	if (ft_strncmp(op, SA, 2) == 0)
		swap_a(stack_a);
	else if (ft_strncmp(op, SB, 2) == 0)
		swap_b(stack_b);
	else if (ft_strncmp(op, SS, 2) == 0)
		swap_ab(stack_a, stack_b);
	else if (ft_strncmp(op, RA, 2) == 0)
		rotate_a(stack_a);
	else if (ft_strncmp(op, RB, 2) == 0)
		rotate_b(stack_b);
	else if (ft_strncmp(op, RRA, 3) == 0)
		reverse_rotate_a(stack_a);
	else if (ft_strncmp(op, RRB, 3) == 0)
		reverse_rotate_b(stack_b);
	else if (ft_strncmp(op, RRR, 3) == 0)
		reverse_rotate_ab(stack_a, stack_b);
	else if (ft_strncmp(op, RR, 2) == 0)
		rotate_ab(stack_a, stack_b);
	else if (ft_strncmp(op, PA, 2) == 0)
		push_a(stack_a, stack_b);
	else if (ft_strncmp(op, PB, 2) == 0)
		push_b(stack_a, stack_b);
	ft_printf("%s\n", op);
}

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	unsigned char	u1;
	unsigned char	u2;

	while (n > 0)
	{
		u1 = (unsigned char) *s1;
		u2 = (unsigned char) *s2;
		s1++;
		s2++;
		if (u1 != u2)
			return (u1 - u2);
		if (u1 == '\0')
			return (0);
		n--;
	}
	return (0);
}
