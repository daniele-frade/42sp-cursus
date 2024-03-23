/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dfrade <dfrade@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/12 13:30:59 by dfrade            #+#    #+#             */
/*   Updated: 2023/11/15 15:38:14 by dfrade           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINITALK_H
# define MINITALK_H

# include <signal.h>
# include <stdlib.h>
# include <unistd.h>
# include "ft_printf.h"

// server
void	sig_handler(int received_signal, siginfo_t *all_sig_info, void *cont);
// client
int		check_params(char *argv1, char *argv2);
int		check_params_2(int argc);
void	server_signal(int sig);
void	send_signal_in_bits(unsigned char c, int server_pid);
// utils
int		ft_atoi(const char *str);
int		ft_isdigit(int c);

#endif