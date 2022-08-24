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

static void	philo(t_philo *philo, int i)
{
	philo->nbr = i;
	philo->left_fork = i;
	philo->right_fork = (i + 1) % (philo->args->nbr_philo);
	philo->meal_nbr = 0;
}

static int	init_philos(t_args *args)
{
	int	i;

	i = 0;
	while (i < args->nbr_philo)
	{
		args->philos[i].args = args;
		philo(&(args->philos[i]), i);
		i++;
	}
	return (1);
}

static int	init_mutex(t_args *args)
{
	int	i;

	i = 0;
	while (i < args->nbr_philo)
	{
		if (pthread_mutex_init(args->forks + i, NULL))
			return (error_message(3));
		i++;
	}
	if (pthread_mutex_init(&(args->message), NULL))
		return (error_message(3));
	if (pthread_mutex_init(&(args->meal), NULL))
		return (error_message(3));
	return (0);
}

int	parsing(int ac, char **av, t_args *args)
{
	int	i;

	i = 1;
	while (i < ac)
	{
		if (__strisnbr(av[i]))
			return (error_message(2));
		i++;
	}
	args->nbr_philo = __atoi(av[1]);
	if (args->nbr_philo == 0 || args->nbr_philo > 200)
		return (error_message(5));
	args->time_die = __atoi(av[2]);
	args->time_eat = __atoi(av[3]);
	args->time_sleep = __atoi(av[4]);
	args->meal_nbr = -1;
	if (ac == 6)
		args->meal_nbr = __atoi(av[5]);
	args->all_eat = 0;
	args->death = 0;
	if (init_mutex(args))
		return (1);
	init_philos(args);
	return (0);
}
