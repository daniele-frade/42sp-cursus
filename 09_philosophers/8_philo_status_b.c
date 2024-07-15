/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   8_philo_status_2.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dfrade <dfrade@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/14 15:57:25 by dfrade            #+#    #+#             */
/*   Updated: 2024/07/14 16:52:50 by dfrade           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	global_print(long time, t_philo *philo, char *action)
{
	if (!is_someone_dead(philo->table))
	{
		pthread_mutex_lock(&philo->table->someone_is_talking);
		if (!is_someone_dead(philo->table))
			printf("%9ld %d %s\n", time - philo->table->start_time,
				philo->numb + 1, action);
		pthread_mutex_unlock(&philo->table->someone_is_talking);
	}
}

void	observer(t_table *table, t_philo *philo, int total)
{
	int	i;

	i = 0;
	while (!is_someone_dead(table) && !everyone_eated(table, total))
	{
		if (am_i_dead(&philo[i]))
			set_someone_die(table);
		i++;
		if (i == total)
			i = 0;
		usleep(100);
	}
}
