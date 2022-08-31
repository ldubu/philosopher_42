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

/*	La fonction get_time transforme le retour de gettimeofday en un chiffre
	utilisable */

long long	get_time(void)
{
	struct timeval	t;

	gettimeofday(&t, NULL);
	return ((t.tv_sec * 1000) + (t.tv_usec / 1000));
}

/*	Pour pas que les messages se melangent, on a un mutex sur les messages*/

void	message(t_args *args, int philo_n, char *action)
{
	pthread_mutex_lock(&(args->m_death));
	if (!args->death)
	{
		pthread_mutex_lock(&(args->m_message));
		printf("%lli %i %s\n", get_time() - args->first_time, philo_n, action);
		pthread_mutex_unlock(&(args->m_message));
	}
	pthread_mutex_unlock(&(args->m_death));
}

/*	Smart sleep surveille si un philo n'est pas mort pendant que le philo
	mange ou dort*/

void	smart_sleep(long long time, t_args *args)
{
	long long	i;
	int			end;

	end = 1;
	i = get_time();
	if (time > args->time_die)
	{
		smart_sleep(args->time_die, args);
		return ;
	}
	while (end)
	{
		if ((get_time() - i) >= time)
			break ;
		usleep(time / 10);
		pthread_mutex_lock(&(args->m_death));
		if (args->death)
			end = 0;
		pthread_mutex_unlock(&(args->m_death));
	}
}

int	check_eat_death(t_args *args)
{
	pthread_mutex_lock(&(args->m_death));
	if (args->death)
	{
		pthread_mutex_unlock(&(args->m_death));
		return (1);
	}
	pthread_mutex_unlock(&(args->m_death));
	pthread_mutex_lock(&(args->m_all_eat));
	if (args->death)
	{
		pthread_mutex_unlock(&(args->m_all_eat));
		return (1);
	}
	pthread_mutex_unlock(&(args->m_all_eat));
	return (0);
}
