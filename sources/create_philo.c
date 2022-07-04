/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_philo.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/28 09:59:36 by marvin            #+#    #+#             */
/*   Updated: 2022/06/28 09:59:36 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static void	*routine(void *false_philo)
{
	t_philo	*philo;
	t_args	*args;

	philo = (t_philo *)false_philo;
	args = philo->args;
	if (philo->nbr % 2)
		usleep(15000);
	while (!args->death)
	{
		eat(philo, args);
		if (args->all_eat)
			break;
		message(args, philo->nbr + 1, "is sleeping");
		smart_sleep(args->time_sleep, args);
		message(args, philo->nbr + 1, "is thinking");
	}
	return (NULL);
}

void	check_all_eat(t_args *args)
{
	int	i;

	i = 0;
	while (i < args->nbr_philo)
	{
		if (args->philos[i].meal_nbr <= args->meal_nbr)
			break;
		i++;
	}
	if (i == args->nbr_philo)
		args->all_eat = 1;
}

void check_death(t_args *args)
{
	int i;
	while (!args->all_eat)
	{
		i = 0;
		while (i < args->nbr_philo)
		{
			pthread_mutex_lock(&(args->meal));
			if (get_time() - args->philos[i].last_meal > args->time_die)
			{
				message(args, i + 1, "died");
				args->death = 1;
			}
			pthread_mutex_unlock(&(args->meal));
			i++;
		}
		if (args->death)
			break;
		if (args->all_eat != -1)
			check_all_eat(args);
}
}

int	create_philo(t_args *args)
{
	int	i;

	i = 0;
	args->first_time = get_time();
	while (i < args->nbr_philo)
	{
		if (pthread_create(&(args->philos[i].thread_id), NULL, &routine, (void *)&args->philos[i]))
			return (error_message(4));
		args->philos[i].last_meal = get_time();
		i++;
		usleep(5);
	}
	check_death(args);
	return (0);
}


// static void	*routine(void *false_philo)
// {
// 	t_philo	*philo;

// 	philo = (t_philo *)false_philo;
// 	if (philo->nbr % 2)
// 		usleep(15000);
// 	while (philo->nbr_of_meal < 1)
// 	{
// 		eat(philo->cutlery->forks, philo->cutlery->mutex_fork, philo);
// 	}
// 	return(philo);
// }

// int	create_philo(t_time *args, t_cutlery *cutlery, int i)
// {
// 	pthread_t	tid;
// 	t_philo		philo;

// 	philo_init(&philo, args, cutlery, i);
// 	pthread_create(&tid, NULL, &routine, (void *)&philo);
// 	// usleep(5);
// 	(void) args;
// 	return (1);
// }