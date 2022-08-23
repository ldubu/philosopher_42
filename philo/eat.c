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

/*	Locks fourchette de droite et de gauche avant de lock ke mutex
	m_death_meal_check	pour le debut du repas. Puis on attend le temp du 
	repas avant d'unlock les fourchettes*/

void	mutex_msg(t_args *args, int philo_n, char *action)
{
	pthread_mutex_lock(&(args->m_death_meal_check));
	message(args, philo_n, action);
	pthread_mutex_unlock(&(args->m_death_meal_check));
}

void	eat(t_philo *philo, t_args *args)
{
	// printf("philo %d, index = %d %d\n", philo->nbr + 1, philo->left_fork, philo->right_fork);
	pthread_mutex_lock(&(args->m_forks[philo->left_fork]));
	mutex_msg(args, philo->nbr + 1, "has taken a fork");
	pthread_mutex_lock(&(args->m_forks[philo->right_fork]));
	mutex_msg(args, philo->nbr + 1, "has taken a fork");
	pthread_mutex_lock(&(args->m_death_meal_check));
	message(args, philo->nbr + 1, "is eating");
	philo->last_meal = get_time();
	pthread_mutex_unlock(&(args->m_death_meal_check));
	smart_sleep(args->time_eat, args);
	pthread_mutex_lock(&(args->m_all_eat_check));
	(philo->meal_nbr)++;
	pthread_mutex_unlock(&(args->m_all_eat_check));
	mutex_msg(args, philo->nbr + 1, "release a fork");
	pthread_mutex_unlock(&(args->m_forks[philo->left_fork]));
	mutex_msg(args, philo->nbr + 1, "release a fork");
	pthread_mutex_unlock(&(args->m_forks[philo->right_fork]));
}
