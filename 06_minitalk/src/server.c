/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dfrade <dfrade@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/12 13:31:28 by dfrade            #+#    #+#             */
/*   Updated: 2023/11/15 19:30:44 by dfrade           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

int	main(void)
{
	struct sigaction	server_sigaction;

	server_sigaction.sa_handler = NULL;
	server_sigaction.sa_sigaction = sig_handler;
	sigemptyset(&server_sigaction.sa_mask);
	server_sigaction.sa_flags = SA_SIGINFO;
	ft_printf("PID = %d\n", getpid());
	sigaction(SIGUSR1, &server_sigaction, NULL);
	sigaction(SIGUSR2, &server_sigaction, NULL);
	while (1)
		pause();
	return (0);
}

void	sig_handler(int received_signal, siginfo_t *all_sig_info, void *cont)
{
	static int	bits;
	static char	received_char;

	(void)cont;
	if (received_signal == SIGUSR1)
		received_char = (received_char << 1) | 0;
	else if (received_signal == SIGUSR2)
		received_char = (received_char << 1) | 1;
	bits++;
	if (bits == 8)
	{
		write(1, &received_char, 1);
		bits = 0;
		received_char = 0;
	}
	kill(all_sig_info->si_pid, SIGUSR1);
}
