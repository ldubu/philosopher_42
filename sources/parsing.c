/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/13 13:29:51 by marvin            #+#    #+#             */
/*   Updated: 2022/06/13 13:29:51 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	parsing(int ac, char **av, t_time *args)
{
	int	i;

	i = 1;
	if (ac != 5 && ac != 6)
	{
		printf("./philo number_of_philosophers time_to_die time_to_eat \
		time_to_sleep [number_of_times_each_philosopher_must_eat]\n");
		return (0);
	}
	while (i < ac)
	{
		if (!__strisnbr(av[i]))
		{
			printf("Arguments must be number\n");
			return (0);
		}
		i++;
	}
	args->nbr_philo = __atoi(av[1]);
	args->time_to_die = __atoi(av[2]);
	args->time_to_eat = __atoi(av[3]);
	args->time_to_sleep = __atoi(av[4]);
	if (ac == 6)
		args->nbr_of_time = __atoi(av[5]);
	return (i);
}