/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dfrade <dfrade@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/26 10:53:50 by dfrade            #+#    #+#             */
/*   Updated: 2023/12/08 19:14:17 by dfrade           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int argc, char **argv)
{
	t_node	*stack_a;
	t_node	*stack_b;
	int		i;

	i = 1;
	stack_a = NULL;
	stack_b = NULL;
	if (argc == 1)
		return (1);
	while (argv[i] != NULL)
	{
		if (has_syntax_error(argv[i++]) == 1)
			free_and_exit(stack_a);
	}
	stack_a = stack_init(argv + 1, stack_a);
	sort_push_swap(&stack_a, &stack_b, argc);
	free_list(stack_a);
}

void	sort_push_swap(t_node **stack_a, t_node **stack_b, int argc)
{
	if (!is_stack_sorted(*stack_a))
	{
		if (argc - 1 == 2)
			call_operations(stack_a, stack_b, SA);
		else if (argc - 1 == 3)
			sort_three(stack_a);
		else if (argc - 1 == 4)
			sort_four(stack_a, stack_b);
		else if (argc - 1 == 5)
			sort_five(stack_a, stack_b);
		else
		{
			normalizer(*stack_a);
			radix_sort(stack_a, stack_b, argc - 1);
		}
	}
}

void	free_and_exit(t_node *stack_a)
{
	free_list(stack_a);
	print_error("Error\n");
	exit(1);
}

void	free_list(t_node *current_node)
{
	t_node	*next_node;

	while (current_node)
	{
		next_node = current_node->next;
		free(current_node);
		current_node = next_node;
	}
}
