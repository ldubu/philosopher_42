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
	while (!args->death)
	{
		eat(philo, args);
		if (args->all_eat)
			break ;
		message(args, philo->nbr + 1, "is sleeping");
		smart_sleep(args->time_sleep, args);
		message(args, philo->nbr + 1, "is thinking");
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
		args->philos[i].last_meal = get_time();
		i++;
		usleep(5);
	}
	check_death(args);
	i = 0;
	while (i < args->nbr_philo)
		pthread_join(args->philos[i++].thread_id, NULL);
	return (0);
}
