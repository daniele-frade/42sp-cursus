/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate_operations.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dfrade <dfrade@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/07 15:50:59 by dfrade            #+#    #+#             */
/*   Updated: 2023/12/07 21:18:10 by dfrade           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rotate_a(t_node **stack_a)
{
	t_node	*last_node;

	if (stack_a == NULL || (*stack_a) == NULL || (*stack_a)->next == NULL)
		return ;
	last_node = ft_lstlast(*stack_a);
	last_node->next = (*stack_a);
	(*stack_a) = (*stack_a)->next;
	last_node->next->next = NULL;
}

void	rotate_b(t_node **stack_b)
{
	t_node	*last_node;

	if (stack_b == NULL || (*stack_b) == NULL || (*stack_b)->next == NULL)
		return ;
	last_node = ft_lstlast(*stack_b);
	last_node->next = (*stack_b);
	(*stack_b) = (*stack_b)->next;
	last_node->next->next = NULL;
}

void	rotate_ab(t_node **stack_a, t_node **stack_b)
{
	if (stack_b == NULL || (*stack_b) == NULL || (*stack_b)->next == NULL)
		return ;
	if (stack_a == NULL || (*stack_a) == NULL || (*stack_a)->next == NULL)
		return ;
	rotate_a(stack_a);
	rotate_b(stack_b);
}
