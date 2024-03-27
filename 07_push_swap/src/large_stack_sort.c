/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   large_stack_sort.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dfrade <dfrade@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/08 14:19:23 by dfrade            #+#    #+#             */
/*   Updated: 2023/12/08 16:11:34 by dfrade           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	digits_in_bits(int number)
{
	int	digits;

	digits = 1;
	while (number / 2)
	{
		digits++;
		number = number / 2;
	}
	return (digits);
}

void	normalizer(t_node *list)
{
	t_node	*current_node;
	t_node	*stack_a;

	if (list == NULL)
		return ;
	current_node = list;
	while (current_node)
	{
		stack_a = list;
		while (stack_a)
		{
			if (current_node->value > stack_a->value)
				current_node->nb_index++;
			stack_a = stack_a->next;
		}
		current_node = current_node->next;
	}
}

void	radix_sort(t_node **stack_a, t_node **stack_b, int stack_len)
{
	int	i;
	int	j;
	int	radix_usage;

	i = 0;
	radix_usage = digits_in_bits(stack_len - 1);
	while (i < radix_usage)
	{
		j = 0;
		while (j < stack_len)
		{
			if ((((*stack_a)->nb_index >> i) & 1) == 0)
				call_operations(stack_a, stack_b, PB);
			else
				call_operations(stack_a, stack_b, RA);
			j++;
		}
		while (*stack_b)
			call_operations(stack_a, stack_b, PA);
		i++;
	}
}
