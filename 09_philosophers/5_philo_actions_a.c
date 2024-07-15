/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   5_philo_actions_1.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dfrade <dfrade@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/14 15:55:13 by dfrade            #+#    #+#             */
/*   Updated: 2024/07/14 16:51:18 by dfrade           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	philo_think(t_philo *philo)
{
	global_print(get_actual_time(), philo, "is thinking");
	usleep(999);
}

void	philo_sleep(t_philo *philo)
{
	global_print(get_actual_time(), philo, "is sleeping");
	usleep(philo->table->time_to_sleep * 1000);
}

void	eating(t_philo *philo)
{
	set_last_feeding(philo);
	global_print(get_actual_time(), philo, "is eating");
	if (philo->remaing_times_to_eat > 0)
		philo->remaing_times_to_eat--;
	usleep(philo->table->time_to_eat * 1000);
}
