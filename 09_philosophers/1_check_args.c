/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   1_check_args.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dfrade <dfrade@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/14 16:37:05 by dfrade            #+#    #+#             */
/*   Updated: 2024/07/14 16:59:01 by dfrade           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	is_a_valid_int(char *arg)
{
	int		digits;
	char	*bigger;

	if (!arg || !*arg)
		return (0);
	while ((*arg >= 9 && *arg <= 13) || *arg == ' ')
		arg++;
	if (*arg == '+')
		arg++;
	while (*arg == '0')
		arg++;
	if (!*arg)
		return (0);
	digits = 0;
	while (*arg >= '0' && *arg <= '9' && ++digits < 11)
		arg++;
	bigger = "2147483647";
	if (digits++ == 10)
		while (--digits)
			if (arg[-digits] > bigger[10 - digits])
				return (0);
	while ((*arg >= 9 && *arg <= 13) || *arg == ' ')
		arg++;
	return (!*arg);
}

int	is_only_positive_numbers(char *str)
{
	if (!str || !*str)
		return (0);
	while ((*str >= 9 && *str <= 13) || *str == ' ')
		str++;
	if (*str == '+')
		str++;
	if (!*str)
		return (0);
	while (*str >= '0' && *str <= '9')
		str++;
	while ((*str >= 9 && *str <= 13) || *str == ' ')
		str++;
	return (!*str);
}

int	validate_args(char **args)
{
	char	**start;

	if (!args || !*args)
		return (1);
	start = args;
	while (is_only_positive_numbers(*args))
		args++;
	if (!*args)
	{
		args = start;
		while (is_a_valid_int(*args))
			args++;
		if (*args)
			printf ("Enter a positive integer between 1 and 2147483647.\n");
	}
	return (*args == NULL);
}
