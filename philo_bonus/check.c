/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldubuche <ldubuche@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/28 11:44:46 by ldubuche          #+#    #+#             */
/*   Updated: 2022/07/28 14:49:17 by ldubuche         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

/*	Check si les philo ont depasser time_death depuis leur dernier repas
	un mutex protege le fait de checker la mort et le debut d'un repas en
	meme temps*/

int	check_death(t_args_b *args, int i)
{
	while (1)
	{
		// fprintf(stderr, "%i: test %lli\n", i, get_time() - args->first_time);
		pthread_mutex_lock(&(args->meal));
		if (get_time() - args->philos[i].last_meal > args->time_die)
		{
			message(args, args->philos[i].nbr + 1, "died");
			args->death = 1;
		}
		pthread_mutex_unlock(&(args->meal));
		if (args->death)
			return (1);
		if (args->meal_nbr != -1)
		{
			if (args->philos[i].meal_nbr >= args->meal_nbr)
				return (2);
		}
	}
}
