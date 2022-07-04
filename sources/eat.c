/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   eat.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/28 14:12:08 by marvin            #+#    #+#             */
/*   Updated: 2022/06/28 14:12:08 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	eat(t_philo *philo, t_args *args)
{
	pthread_mutex_lock(&(args->forks[philo->left_fork]));
	message(args, philo->nbr + 1, "has taken a fork");
	pthread_mutex_lock(&(args->forks[philo->right_fork]));
	message(args, philo->nbr + 1, "has taken a fork");
	pthread_mutex_lock(&(args->meal));
	message(args, philo->nbr + 1, "is eating");
	philo->last_meal = get_time();
	pthread_mutex_unlock(&(args->meal));
	smart_sleep(args->time_eat, args);
	(philo->meal_nbr) ++;
	pthread_mutex_unlock(&(args->forks[philo->left_fork]));
	pthread_mutex_unlock(&(args->forks[philo->right_fork]));
}