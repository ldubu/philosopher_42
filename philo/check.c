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
		if (args->philos[i].meal_nbr <= args->meal_nbr)
			break ;
		i++;
	}
	if (i == args->nbr_philo)
		args->all_eat = 1;
}

/*	Check si les philo ont depasser time_death depuis leur dernier repas
	un mutex protege le fait de checker la mort et le debut d'un repas en
	meme temps*/

void	check_death(t_args *args)
{
	int	i;

	while (!args->all_eat)
	{
		i = 0;
		while (i < args->nbr_philo)
		{
			pthread_mutex_lock(&(args->meal));
			if (get_time() - args->philos[i].last_meal >= args->time_die)
			{
				message(args, i + 1, "died");
				args->death = 1;
			}
			pthread_mutex_unlock(&(args->meal));
			i++;
		}
		if (args->death)
			break ;
		if (args->meal_nbr != -1)
			check_all_eat(args);
	}
}
