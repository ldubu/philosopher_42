/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/01 13:50:15 by marvin            #+#    #+#             */
/*   Updated: 2022/07/01 13:50:15 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

long long	get_time(void)
{
	struct timeval	t;

	gettimeofday(&t, NULL);
	return ((t.tv_sec * 1000) + (t.tv_usec / 1000));
}

void	message(t_args *args, int philo_n, char *action)
{
	pthread_mutex_lock(&(args->message));
	if (!args->death)
		printf("%lli %i %s\n", get_time() - args->first_time, philo_n, action);
	pthread_mutex_unlock(&(args->message));
}

void		smart_sleep(long long time, t_args *args)
{
	long long i;

	i = get_time();
	while (!(args->death))
	{
		if ((get_time() - i) >= time)
			break ;
		usleep(50);
	}
}