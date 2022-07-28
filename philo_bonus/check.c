/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldubuche <ldubuche@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/28 11:44:46 by ldubuche          #+#    #+#             */
/*   Updated: 2022/07/28 12:40:14 by ldubuche         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

/*	Check si les philo ont depasser time_death depuis leur dernier repas
	un mutex protege le fait de checker la mort et le debut d'un repas en
	meme temps*/

int	check_death(void *void_philo)
{
	t_philo_b	*philo;

	philo = (t_philo_b *) void_philo;
	while (1)
	{
		fprintf(stderr, "test %lli\n", get_time() - philo->args->first_time);
		pthread_mutex_lock(&(philo->args->meal));
		if (get_time() - philo->last_meal > philo->args->time_die)
		{
			message(philo->args, philo->nbr + 1, "died");
			philo->args->death = 1;
		}
		pthread_mutex_unlock(&(philo->args->meal));
		if (philo->args->death)
			return (1);
		if (philo->args->meal_nbr != -1)
		{
			if (philo->meal_nbr <= philo->args->meal_nbr)
				return (2);
		}
	}
}
