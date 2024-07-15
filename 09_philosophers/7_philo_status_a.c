/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   7_philo_status_1.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dfrade <dfrade@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/14 15:57:25 by dfrade            #+#    #+#             */
/*   Updated: 2024/07/14 16:53:22 by dfrade           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

long	get_last_feeding(t_philo *philo)
{
	long	last_feeding;

	pthread_mutex_lock(&philo->table->someone_is_eating);
	last_feeding = philo->last_feeding;
	pthread_mutex_unlock(&philo->table->someone_is_eating);
	return (last_feeding);
}

void	set_last_feeding(t_philo *philo)
{
	pthread_mutex_lock(&philo->table->someone_is_eating);
	philo->last_feeding = get_actual_time();
	pthread_mutex_unlock(&philo->table->someone_is_eating);
}

long	get_actual_time(void)
{
	struct timeval	time;

	gettimeofday(&time, 0);
	return ((time.tv_sec * 1000) + (time.tv_usec / 1000));
}

void	update_finished_to_eat(t_philo *philo)
{
	pthread_mutex_lock(&philo->table->eat_checker);
	philo->table->philos_that_finished_to_eat++;
	pthread_mutex_unlock(&philo->table->eat_checker);
}

int	everyone_eated(t_table *table, int total)
{
	int	everyone;

	pthread_mutex_lock(&table->eat_checker);
	everyone = table->philos_that_finished_to_eat;
	pthread_mutex_unlock(&table->eat_checker);
	return (everyone == total);
}
