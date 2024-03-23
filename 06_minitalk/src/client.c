/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dfrade <dfrade@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/12 13:31:09 by dfrade            #+#    #+#             */
/*   Updated: 2023/11/15 16:17:57 by dfrade           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

#define NO 0
#define YES 1

int	g_can_i_send_a_signal;

int	main(int argc, char **argv)
{
	int	server_pid;
	int	i;

	g_can_i_send_a_signal = 0;
	if (check_params(argv[1], argv[2]) != 0 && check_params_2(argc) != 0)
	{
		signal(SIGUSR1, server_signal);
		server_pid = ft_atoi(argv[1]);
		i = 0;
		while (argv[2][i] != '\0')
		{
			send_signal_in_bits(argv[2][i], server_pid);
			i++;
		}
	}
	else
		return (ft_printf("ERROR\n"));
	return (0);
}

int	check_params(char *argv1, char *argv2)
{
	int	i;

	i = 0;
	while (argv1[i] != '\0')
	{
		if (!ft_isdigit(argv1[i]))
		{
			ft_printf("ERROR: Invalid PID\n");
			return (0);
		}
		i++;
	}
	if (ft_atoi(argv1) < 0)
	{
		ft_printf("ERROR: Invalid PID\n");
		return (0);
	}
	if (!argv2)
	{
		ft_printf("ERROR: Empty string!\n");
		return (0);
	}
	return (1);
}

int	check_params_2(int argc)
{
	if (argc != 3)
	{
		ft_printf("ERROR: Invalid number of arguments!\n");
		return (0);
	}
	return (1);
}

void	send_signal_in_bits(unsigned char c, int server_pid)
{
	int	shift_times;
	int	bit_result;

	shift_times = 7;
	while (shift_times >= 0)
	{
		g_can_i_send_a_signal = 0;
		bit_result = c >> shift_times;
		if (bit_result % 2 == 0)
		{
			kill(server_pid, SIGUSR1);
			while (g_can_i_send_a_signal == 0)
				;
		}
		else if (bit_result % 2 == 1)
		{
			kill(server_pid, SIGUSR2);
			while (g_can_i_send_a_signal == 0)
				;
		}
		shift_times--;
	}
}

void	server_signal(int sig)
{
	(void)sig;
	g_can_i_send_a_signal = 1;
}
