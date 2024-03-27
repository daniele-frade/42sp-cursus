/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_manip.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dfrade <dfrade@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/07 15:51:10 by dfrade            #+#    #+#             */
/*   Updated: 2023/12/08 19:14:35 by dfrade           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_node	*create_node(int number)
{
	t_node	*node;

	node = malloc(1 * sizeof(t_node));
	if (!node)
		return (NULL);
	node->value = number;
	node->next = NULL;
	node->nb_index = 0;
	return (node);
}

t_node	*stack_init(char **argv, t_node *stack_a)
{
	int		i;
	long	nb;
	t_node	*node;

	i = 0;
	node = NULL;
	while (argv[i] != NULL)
	{
		nb = ft_atol(argv[i]);
		if (has_range_error(nb) == 1 || has_duplication_error(stack_a, nb) == 1)
			free_and_exit(stack_a);
		node = create_node(nb);
		if (node == NULL)
			return (NULL);
		ft_lstadd_back(&stack_a, node);
		i++;
	}
	return (stack_a);
}

t_node	*ft_lstlast(t_node *list)
{
	if (list == NULL)
		return (list);
	while (list->next != NULL)
	{
		list = list->next;
	}
	return (list);
}

void	ft_lstadd_back(t_node **list, t_node *new)
{
	t_node	*last_node;

	if (list == NULL || new == NULL)
		return ;
	if (*list == NULL)
	{
		*list = new;
		return ;
	}
	last_node = ft_lstlast(*list);
	last_node->next = new;
}

int	is_stack_sorted(t_node *stack_a)
{
	if (stack_a == NULL)
		return (0);
	while (stack_a->next)
	{
		if (stack_a->value > stack_a->next->value)
			return (0);
		stack_a = stack_a->next;
	}
	return (1);
}
