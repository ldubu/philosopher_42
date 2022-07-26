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

#include "philo_bonus.h"

/*	La fonction get_time transforme le retour de gettimeofday en un chiffre
	utilisable */

long long	get_time(void)
{
	struct timeval	t;

	gettimeofday(&t, NULL);
	return ((t.tv_sec * 1000) + (t.tv_usec / 1000));
}

/*	Pour pas que les messages se melangent, on a un mutex sur les messages*/

void	message(t_args_b *args, int philo_n, char *action)
{
	pthread_mutex_lock(&(args->message));
	if (!args->death)
		printf("%lli %i %s\n", get_time() - args->first_time, philo_n, action);
	pthread_mutex_unlock(&(args->message));
}

/*	Smart sleep surveille si un philo n'est pas mort pendant que le philo
	mange ou dort*/

void	smart_sleep(long long time, t_args_b *args)
{
	long long	i;

	i = get_time();
	while (!(args->death))
	{
		if ((get_time() - i) >= time)
			break ;
		usleep(50);
	}
}

/* Fonction pour attendre tout les philos */

int	status_handler(int wstatus)
{
	if (WIFEXITED(wstatus))
		return (WEXITSTATUS(wstatus));
	if (WIFSIGNALED(wstatus))
		return (128 + WTERMSIG(wstatus));
	return (wstatus);
}

int	wait_philo(t_args_b *args)
{
	int	i;
	int	wstatus;

	i = 0;
	while (i < args->nbr_philo)
	{
		waitpid(args->philos[i].philo_id, &wstatus, 0);
		i++;
	}
	return (status_handler(wstatus));
}
