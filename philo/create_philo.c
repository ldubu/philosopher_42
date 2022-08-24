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
	while (1)
	{
		eat(philo, args);
		pthread_mutex_lock(&(args->m_all_eat_check));
		if (args->all_eat)
		{
			pthread_mutex_unlock(&(args->m_all_eat_check));
			return (NULL);
		}
		pthread_mutex_unlock(&(args->m_all_eat_check));
		mutex_msg(args, philo->nbr + 1, "is sleeping");
		smart_sleep(args->time_sleep, args);
		mutex_msg(args, philo->nbr + 1, "is thinking");
		pthread_mutex_lock(&(args->m_death_meal_check));
		if (args->death)
			return (NULL);
		pthread_mutex_unlock(&(args->m_death_meal_check));
	}
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
		pthread_mutex_lock(&(args->m_death_meal_check));
		args->philos[i].last_meal = get_time();
		pthread_mutex_unlock(&(args->m_death_meal_check));
		i++;
		usleep(5);
	}
	check_death(args);
	i = 2;
	while (i < args->nbr_philo)
	{
		printf("waiting for %d...\n", i+1);
		pthread_join(args->philos[i++].thread_id, NULL);
	}
		
	return (0);
}
