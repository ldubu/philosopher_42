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

/*	Locks fourchette de droite et de gauche avant de lock ke mutex meal
	pour le debut du repas. Puis on attend le temp du repas avant d'unlock
	les fourchettes*/

void	eat(t_philo *philo, t_args *args)
{
	pthread_mutex_lock(&(args->m_forks[philo->left_fork]));
	message(args, philo->nbr + 1, "has taken a fork");
	if (philo->left_fork == philo->right_fork)
	{
		pthread_mutex_unlock(&(args->m_forks[philo->left_fork]));
		smart_sleep(args->time_die, args);
		return ;
	}
	pthread_mutex_lock(&(args->m_forks[philo->right_fork]));
	message(args, philo->nbr + 1, "has taken a fork");
	pthread_mutex_lock(&(args->m_last_meal));
	message(args, philo->nbr + 1, "is eating");
	philo->last_meal = get_time();
	pthread_mutex_unlock(&(args->m_last_meal));
	smart_sleep(args->time_eat, args);
	pthread_mutex_lock(&(args->m_meal_nbr));
	(philo->meal_nbr)++;
	pthread_mutex_unlock(&(args->m_meal_nbr));
	pthread_mutex_unlock(&(args->m_forks[philo->left_fork]));
	pthread_mutex_unlock(&(args->m_forks[philo->right_fork]));
}
