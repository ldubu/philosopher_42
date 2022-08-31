/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/19 13:38:22 by marvin            #+#    #+#             */
/*   Updated: 2022/07/19 13:38:22 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

/*	Check si tout les philos ont manges assez de fois*/

static void	check_all_eat(t_args *args)
{
	int	i;

	i = 0;
	while (i < args->nbr_philo)
	{
		pthread_mutex_lock(&(args->m_meal_nbr));
		if (args->philos[i].meal_nbr < args->meal_nbr)
		{
			pthread_mutex_unlock(&(args->m_meal_nbr));
			break ;
		}
		pthread_mutex_unlock(&(args->m_meal_nbr));
		i++;
	}
	if (i == args->nbr_philo)
	{
		pthread_mutex_lock(&(args->m_all_eat));
		args->all_eat = 1;
		pthread_mutex_lock(&(args->m_all_eat));
	}
}

static void	philo_died(t_args *args, int i)
{
	message(args, i + 1, "died");
	pthread_mutex_lock(&(args->m_death));
	args->death = 1;
	pthread_mutex_unlock(&(args->m_death));
}

static int	check_value_death(t_args *args)
{
	pthread_mutex_lock(&(args->m_death));
	if (args->death)
	{
		pthread_mutex_unlock(&(args->m_death));
		return (1);
	}
	pthread_mutex_unlock(&(args->m_death));
	return (0);
}

/*	Check si les philo ont depasser time_death depuis leur dernier repas
	un mutex protege le fait de checker la mort et le debut d'un repas en
	meme temps*/

void	check_death(t_args *args)
{
	int	i;

	pthread_mutex_lock(&(args->m_all_eat));
	while (!args->all_eat)
	{
		pthread_mutex_unlock(&(args->m_all_eat));
		i = 0;
		while (i < args->nbr_philo)
		{
			pthread_mutex_lock(&(args->m_last_meal));
			if (get_time() - args->philos[i].last_meal >= args->time_die)
				philo_died(args, i);
			pthread_mutex_unlock(&(args->m_last_meal));
			i++;
		}
		if (check_value_death(args))
			break ;
		if (args->meal_nbr != -1)
			check_all_eat(args);
		pthread_mutex_lock(&(args->m_all_eat));
	}
	pthread_mutex_unlock(&(args->m_all_eat));
}
