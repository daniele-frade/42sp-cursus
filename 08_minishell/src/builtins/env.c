/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csilva-m <csilva-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/01 11:31:53 by csilva-m          #+#    #+#             */
/*   Updated: 2024/04/18 15:47:54 by csilva-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	env(char **argv)
{
	t_env	*stack;

	if (matrice_len(argv) > 1)
	{
		ft_putendl_fd("env: too many arguments", STDERR_FILENO);
		get_core()->exit_status = 127;
		return ;
	}
	stack = get_core()->env_list;
	while (stack)
	{
		ft_putstr_fd(stack->key, STDIN_FILENO);
		ft_putstr_fd("=", STDIN_FILENO);
		ft_putendl_fd(stack->value, STDIN_FILENO);
		stack = stack->next;
	}
	get_core()->exit_status = 0;
}
