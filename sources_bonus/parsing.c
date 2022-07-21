/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/19 14:49:56 by marvin            #+#    #+#             */
/*   Updated: 2022/07/19 14:49:56 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

static void	philo(t_philo *philo, int i)
{
	philo->nbr = i;
	philo->meal_nbr = 0;
}

static int	init_philos(t_args * args)
{
	int i;

	i = 0;
	while (i < args->nbr_philo)
	{
		args->philos[i].args = args;
		philo(&(args->philos[i]), i);
		i++;
	}
	return (1);
}

static int	init_mutex_sema(t_args *args)
{
	sem_open("/sema", O_CREATE, 0000644, args->nbr_philo);
	if (pthread_mutex_init(&(args->message), NULL))
			return (error_message(3));
	if (pthread_mutex_init(&(args->meal), NULL))
			return (error_message(3));
	return (0);
}


int	parsing(int ac, char **av, t_args *args)
{
	int i;

	i = 1;
	while (i < ac)
	{
		if (__strisnbr(av[i]))
			return (error_message(2));
		i++;
	}
	args->nbr_philo = __atoi(av[1]);
	args->time_die = __atoi(av[2]);
	args->time_eat = __atoi(av[3]);
	args->time_sleep = __atoi(av[4]);
	args->meal_nbr = -1;
	if (ac == 6)
		args->meal_nbr = __atoi(av[5]);
	args->all_eat = 0;
	args->death = 0;
	if (init_mutex_sema(args))
		return (1);
	init_philos(args);
	return (0);
}
