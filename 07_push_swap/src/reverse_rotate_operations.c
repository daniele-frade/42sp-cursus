/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_rotate_operations.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dfrade <dfrade@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/06 19:21:05 by dfrade            #+#    #+#             */
/*   Updated: 2023/12/08 18:54:43 by dfrade           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	reverse_rotate_a(t_node **stack_a)
{
	t_node	*penultimate_node;

	if (stack_a == NULL || (*stack_a) == NULL || (*stack_a)->next == NULL)
		return ;
	penultimate_node = find_penultimate_node(*stack_a);
	penultimate_node->next->next = (*stack_a);
	(*stack_a) = penultimate_node->next;
	penultimate_node->next = NULL;
}

void	reverse_rotate_b(t_node **stack_b)
{
	t_node	*penultimate_node;

	if (stack_b == NULL || (*stack_b) == NULL || (*stack_b)->next == NULL)
		return ;
	penultimate_node = find_penultimate_node(*stack_b);
	penultimate_node->next->next = (*stack_b);
	(*stack_b) = penultimate_node->next;
	penultimate_node->next = NULL;
}

void	reverse_rotate_ab(t_node **stack_a, t_node **stack_b)
{
	if (stack_a == NULL || (*stack_a) == NULL || (*stack_a)->next == NULL)
		return ;
	if (stack_b == NULL || (*stack_b) == NULL || (*stack_b)->next == NULL)
		return ;
	reverse_rotate_a(stack_a);
	reverse_rotate_b(stack_b);
}

t_node	*find_penultimate_node(t_node *stack)
{
	if (stack == NULL || stack->next == NULL)
		return (NULL);
	while (stack->next->next != NULL)
		stack = stack->next;
	return (stack);
}
