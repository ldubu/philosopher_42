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

static int	check_meal(t_args *args, t_philo *philo)
{
	pthread_mutex_lock(&(args->m_meal_nbr));
	if (args->meal_nbr != -1 && philo->meal_nbr >= args->meal_nbr)
	{
		pthread_mutex_unlock(&(args->m_meal_nbr));
		return (1);
	}
	pthread_mutex_unlock(&(args->m_meal_nbr));
	return (0);
}

/*	Quand on lance un thread, on donne une fonction avec laquelle chaque
	thread va debuter. Pour eviter un deadlock, les philo pair demarre avec un
	decalage. Puis ils mangent, dorment et pensent */

static void	*routine(void *void_philo)
{
	t_philo	*philo;
	t_args	*args;

	philo = (t_philo *)void_philo;
	args = philo->args;
	if (philo->nbr % 2)
		usleep(15000);
	pthread_mutex_lock(&(args->m_death));
	while (!args->death)
	{
		pthread_mutex_unlock(&(args->m_death));
		eat(philo, args);
		if (check_eat_death(args))
			return (NULL);
		message(args, philo->nbr + 1, "is sleeping");
		smart_sleep(args->time_sleep, args);
		message(args, philo->nbr + 1, "is thinking");
		if (check_meal(args, philo))
			return (NULL);
		if (args->nbr_philo % 3 == 0 && (args->time_eat * 3) < args->time_die)
			smart_sleep(args->time_eat, args);
		pthread_mutex_lock(&(args->m_death));
	}
	pthread_mutex_unlock(&(args->m_death));
	
	
	return (NULL);
}

/*	Cette fonction creer un thread pour chaque philo puis lance la
	fonction qui va checker s'il sont mort ou ont tous manger assez*/

int	create_philo(t_args *args)
{
	int	i;

	i = 0;
	args->first_time = get_time();
	while (i < args->nbr_philo)
	{
		if (pthread_create(&(args->philos[i].thread_id), NULL, &routine, \
		(void *)&args->philos[i]))
			return (error_message(4));
		pthread_mutex_lock(&(args->m_last_meal));
		args->philos[i].last_meal = get_time();
		pthread_mutex_unlock(&(args->m_last_meal));
		i++;
		usleep(5);
	}
	check_death(args);
	i = 0;
	while (i < args->nbr_philo)
		pthread_join(args->philos[i++].thread_id, NULL);
	return (0);
}
