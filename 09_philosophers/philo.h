/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dfrade <dfrade@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/14 15:45:51 by dfrade            #+#    #+#             */
/*   Updated: 2024/07/14 16:59:36 by dfrade           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <pthread.h>
# include <stdio.h>
# include <stdlib.h>
# include <sys/time.h>
# include <unistd.h>

struct s_table
{
	int				time_to_die;
	int				time_to_eat;
	int				time_to_sleep;
	int				times_must_eat;
	int				someone_is_dead;
	int				philos_that_finished_to_eat;
	long			start_time;
	pthread_mutex_t	*forks;
	pthread_mutex_t	death_checker;
	pthread_mutex_t	someone_is_eating;
	pthread_mutex_t	someone_is_talking;
	pthread_mutex_t	init_timer;
	pthread_mutex_t	someone_died;
	pthread_mutex_t	eat_checker;
};
typedef struct s_table	t_table;

struct s_philo
{
	int				numb;
	int				right_fork;
	int				left_fork;
	int				remaing_times_to_eat;
	long			last_feeding;
	pthread_t		thread;
	t_table			*table;
};
typedef struct s_philo	t_philo;

// 1_check_args
int		is_a_valid_int(char *arg);
int		is_only_positive_numbers(char *str);
int		validate_args(char **args);

// 2_philo_init
void	init_philos(t_philo *philo, int total, t_table *table);
void	init_mutexes(t_table *table, int total);
int		ft_atoi(const char *nptr);
void	init_table(char **args, t_table *table);
int		initialize(char **args);

// 3_philo_routine
void	start_dinner(t_philo *philo, int total);
void	*dinner(void *arg);
void	finish_dinner(t_table *table, t_philo *philo, int total);
int		am_i_dead(t_philo *philo);
int		is_someone_dead(t_table *table);
void	set_someone_die(t_table *table);

// 4_philo_actions
void	philo_think(t_philo *philo);
void	philo_sleep(t_philo *philo);
void	eating(t_philo *philo);
void	try_to_eat(t_philo *philo);
void	lock_fork(t_philo *philo, int fork_num);
void	unlock_fork(t_philo *philo, int fork_num);

// 5_philo_status
long	get_last_feeding(t_philo *philo);
void	set_last_feeding(t_philo *philo);
long	get_actual_time(void);
int		everyone_eated(t_table *table, int total);
void	global_print(long time, t_philo *philo, char *action);
void	update_finished_to_eat(t_philo *philo);
void	observer(t_table *table, t_philo *philo, int total);

#endif