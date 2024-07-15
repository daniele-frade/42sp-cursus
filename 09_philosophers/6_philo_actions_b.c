/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   6_philo_actions_2.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dfrade <dfrade@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/14 15:55:13 by dfrade            #+#    #+#             */
/*   Updated: 2024/07/14 16:50:55 by dfrade           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	try_to_eat(t_philo *philo)
{
	if (philo->numb & 1)
	{
		lock_fork(philo, philo->left_fork);
		lock_fork(philo, philo->right_fork);
	}
	else
	{
		lock_fork(philo, philo->right_fork);
		lock_fork(philo, philo->left_fork);
	}
	if (philo->left_fork >= 0 && philo->right_fork >= 0
		&& !is_someone_dead(philo->table))
		eating(philo);
	unlock_fork(philo, philo->left_fork);
	unlock_fork(philo, philo->right_fork);
}

void	lock_fork(t_philo *philo, int fork_num)
{
	if (fork_num >= 0)
	{
		pthread_mutex_lock(&philo->table->forks[fork_num]);
		global_print(get_actual_time(), philo, "has taken a fork");
	}
}

void	unlock_fork(t_philo *philo, int fork_num)
{
	if (fork_num >= 0)
		pthread_mutex_unlock(&philo->table->forks[fork_num]);
}
