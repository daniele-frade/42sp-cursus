/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dfrade <dfrade@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/21 14:34:09 by dfrade            #+#    #+#             */
/*   Updated: 2023/12/08 19:10:59 by dfrade           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "ft_printf.h"
# include <unistd.h>
# include <stdlib.h>

# define INT_MAX 2147483647
# define INT_MIN -2147483648
# define SA "sa"
# define SB "sb"
# define SS "ss"
# define RA "ra"
# define RB "rb"
# define RR "rr"
# define RRA "rra"
# define RRB "rrb"
# define RRR "rrr"
# define PA "pa"
# define PB "pb"

typedef struct s_node
{
	int				nb_index;
	int				value;
	struct s_node	*next;
}	t_node;

// Check parameter and handling erros:
int		has_syntax_error(char *str);
int		has_range_error(long long nb);
int		has_duplication_error(t_node *stack_a, int nb);
void	free_and_exit(t_node *stack_a);
void	free_list(t_node *current_node);

// Stack manipulation:
t_node	*create_node(int number);
t_node	*ft_lstlast(t_node *list);
void	ft_lstadd_back(t_node **list, t_node *new);
t_node	*stack_init(char **argv, t_node *stack_a);
int		is_stack_sorted(t_node *stack_a);

// Operations:
void	swap_a(t_node **stack_a);
void	swap_b(t_node **stack_b);
void	swap_ab(t_node **stack_a, t_node **stack_b);
void	rotate_a(t_node **stack_a);
void	rotate_b(t_node **stack_b);
void	rotate_ab(t_node **stack_a, t_node **stack_b);
void	reverse_rotate_a(t_node **stack_a);
void	reverse_rotate_b(t_node **stack_b);
void	reverse_rotate_ab(t_node **stack_a, t_node **stack_b);
void	push_a(t_node **stack_a, t_node **stack_b);
void	push_b(t_node **stack_a, t_node **stack_b);
t_node	*find_penultimate_node(t_node *stack);

// Sort operations:
void	sort_three(t_node **stack_a);
void	sort_five(t_node **stack_a, t_node **stack_b);
void	sort_four(t_node **stack_a, t_node **stack_b);
int		smallest_node_pos(t_node *stack_a);
void	radix_sort(t_node **stack_a, t_node **stack_b, int stack_len);
int		digits_in_bits(int number);
void	normalizer(t_node *list);
void	sort_push_swap(t_node **stack_a, t_node **stack_b, int argc);

// Utils:
int		argv_count(char **argv);
int		ft_isdigit(int c);
long	ft_atol(const char *str);
void	call_operations(t_node	**stack_a, t_node **stack_b, char *op);
int		ft_strncmp(const char *s1, const char *s2, size_t n);
int		print_error(char *str);

#endif