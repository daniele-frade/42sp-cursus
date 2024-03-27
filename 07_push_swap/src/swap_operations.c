/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap_operations.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dfrade <dfrade@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/07 15:51:25 by dfrade            #+#    #+#             */
/*   Updated: 2023/12/08 20:06:56 by dfrade           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	swap_a(t_node **stack_a)
{
	t_node	*temp;

	if (stack_a == NULL || (*stack_a) == NULL || (*stack_a)->next == NULL)
		return ;
	temp = (*stack_a)->next;
	(*stack_a)->next = (*stack_a)->next->next;
	temp->next = (*stack_a);
	(*stack_a) = temp;
}

void	swap_b(t_node **stack_b)
{
	t_node	*temp;

	if (stack_b == NULL || (*stack_b) == NULL || (*stack_b)->next == NULL)
		return ;
	temp = (*stack_b)->next;
	(*stack_b)->next = (*stack_b)->next->next;
	temp->next = (*stack_b);
	(*stack_b) = temp;
}

void	swap_ab(t_node **stack_a, t_node **stack_b)
{
	if (stack_a == NULL || (*stack_a) == NULL || (*stack_a)->next == NULL)
		return ;
	if (stack_b == NULL || (*stack_b) == NULL || (*stack_b)->next == NULL)
		return ;
	swap_a(stack_a);
	swap_b(stack_b);
}
