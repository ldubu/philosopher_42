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

void	mutex_msg(t_args *args, int philo_n, char *action)
{
	pthread_mutex_lock(&(args->meal));
	message(args, philo_n, action);
	pthread_mutex_unlock(&(args->meal));
}

/*	Locks fourchette de droite et de gauche avant de lock ke mutex meal
	pour le debut du repas. Puis on attend le temp du repas avant d'unlock
	les fourchettes*/

void	eat(t_philo *philo, t_args *args)
{
	pthread_mutex_lock(&(args->forks[philo->left_fork]));
	mutex_msg(args, philo->nbr + 1, "has taken a fork");
	if (philo->left_fork == philo->right_fork)
	{
		smart_sleep(args->time_die + args->time_sleep, args);
		return ;
	}
	pthread_mutex_lock(&(args->forks[philo->right_fork]));
	mutex_msg(args, philo->nbr + 1, "has taken a fork");
	pthread_mutex_lock(&(args->meal));
	message(args, philo->nbr + 1, "is eating");
	philo->last_meal = get_time();
	pthread_mutex_unlock(&(args->meal));
	smart_sleep(args->time_eat, args);
	(philo->meal_nbr)++;
	pthread_mutex_unlock(&(args->forks[philo->left_fork]));
	pthread_mutex_unlock(&(args->forks[philo->right_fork]));
}
