/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_operations.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dfrade <dfrade@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/07 15:50:27 by dfrade            #+#    #+#             */
/*   Updated: 2023/12/07 15:50:29 by dfrade           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	push_a(t_node **stack_a, t_node **stack_b)
{
	t_node	*temp;

	if (stack_b == NULL || (*stack_b) == NULL)
		return ;
	temp = (*stack_b)->next;
	(*stack_b)->next = (*stack_a);
	(*stack_a) = (*stack_b);
	(*stack_b) = temp;
}

void	push_b(t_node **stack_a, t_node **stack_b)
{
	t_node	*temp;

	if (stack_a == NULL || (*stack_a) == NULL)
		return ;
	temp = (*stack_a)->next;
	(*stack_a)->next = (*stack_b);
	(*stack_b) = (*stack_a);
	(*stack_a) = temp;
}
