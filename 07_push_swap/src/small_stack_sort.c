/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   small_stack_sort.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dfrade <dfrade@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/07 16:56:40 by dfrade            #+#    #+#             */
/*   Updated: 2023/12/08 19:15:20 by dfrade           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_three(t_node **stack_a)
{
	int	node_01;
	int	node_02;
	int	node_03;

	node_01 = (*stack_a)->value;
	node_02 = (*stack_a)->next->value;
	node_03 = (*stack_a)->next->next->value;
	if (node_01 < node_02 && node_01 < node_03 && node_02 > node_03)
	{
		call_operations(stack_a, NULL, RRA);
		call_operations(stack_a, NULL, SA);
	}	
	else if (node_01 > node_02 && node_01 < node_03 && node_02 < node_03)
		call_operations(stack_a, NULL, SA);
	else if (node_01 < node_02 && node_01 > node_03 && node_02 > node_03)
		call_operations(stack_a, NULL, RRA);
	else if (node_01 > node_02 && node_01 > node_03 && node_02 < node_03)
		call_operations(stack_a, NULL, RA);
	else if (node_01 > node_02 && node_01 > node_03 && node_02 > node_03)
	{
		call_operations(stack_a, NULL, SA);
		call_operations(stack_a, NULL, RRA);
	}
}

void	sort_four(t_node **stack_a, t_node **stack_b)
{
	int	small_node_pos;

	small_node_pos = smallest_node_pos(*stack_a);
	if (small_node_pos == 2)
		call_operations(stack_a, NULL, SA);
	else if (small_node_pos == 3)
	{
		call_operations(stack_a, NULL, RRA);
		call_operations(stack_a, NULL, RRA);
	}
	else if (small_node_pos == 4)
		call_operations(stack_a, NULL, RRA);
	call_operations(stack_a, stack_b, PB);
	sort_three(stack_a);
	call_operations(stack_a, stack_b, PA);
}

void	sort_five(t_node **stack_a, t_node **stack_b)
{
	int	small_node_pos;

	small_node_pos = smallest_node_pos(*stack_a);
	if (small_node_pos == 2)
		call_operations(stack_a, NULL, SA);
	else if (small_node_pos == 3)
	{
		call_operations(stack_a, NULL, RA);
		call_operations(stack_a, NULL, SA);
	}
	else if (small_node_pos == 4)
	{
		call_operations(stack_a, NULL, RRA);
		call_operations(stack_a, NULL, RRA);
	}
	else if (small_node_pos == 5)
		call_operations(stack_a, NULL, RRA);
	call_operations(stack_a, stack_b, PB);
	sort_four(stack_a, stack_b);
	call_operations(stack_a, stack_b, PA);
}

int	smallest_node_pos(t_node *stack_a)
{
	int		i;
	int		position;
	t_node	*smallest;

	i = 1;
	position = 1;
	smallest = stack_a;
	while (stack_a)
	{
		if (smallest->value > stack_a->value)
		{
			smallest = stack_a;
			position = i;
		}
		stack_a = stack_a->next;
		i++;
	}
	return (position);
}

void	print_sorted_stack(t_node *stack_a)
{
	while (stack_a)
	{
		ft_printf("%d\n", stack_a->value);
		stack_a = stack_a->next;
	}
}
