/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   0_main.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dfrade <dfrade@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/14 15:45:38 by dfrade            #+#    #+#             */
/*   Updated: 2024/07/14 20:25:44 by dfrade           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	main(int argc, char **argv)
{
	if (argc < 5 || argc > 6)
	{
		printf("Wrong number of arguments!\nHere is an example"\
		": ./philo 5(number_of_philosophers) 800(time_to_die) 200(time_to_eat)"\
		" 200(time_to_sleep) 7(times_to_eat/optional)\n");
		return (1);
	}
	if (!validate_args(++argv))
	{
		printf("Wrong arguments again :/\n");
		return (1);
	}
	initialize(argv);
	return (0);
}
