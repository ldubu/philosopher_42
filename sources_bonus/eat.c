/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   eat.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/21 14:05:17 by marvin            #+#    #+#             */
/*   Updated: 2022/07/21 14:05:17 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

void	eat(t_philo_b *philo, t_args_b *args)
{
	sem_wait(args->forks);
	message(args, philo->nbr + 1, "has taken a fork");
	sem_wait(args->forks);
	message(args, philo->nbr + 1, "has taken a fork");
	pthread_mutex_lock(&(args->meal));
	message(args, philo->nbr + 1, "is eating");
	philo->last_meal = get_time();
	pthread_mutex_unlock(&(args->meal));
	smart_sleep(args->time_eat, args);
	(philo->meal_nbr)++;
	sem_post(args->forks);
	sem_post(args->forks);
}
