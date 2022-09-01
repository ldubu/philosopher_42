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
	sem_wait(args->s_message);
	if (!args->death)
		printf("%lli %i %s\n", get_time() - args->first_time, philo_n, action);
	sem_post(args->s_message);
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

int	wait_philo(t_args_b *args)
{
	int		i;
	int		wait_status;

	i = -1;
	while (++i < args->nbr_philo)
	{
		waitpid(-1, &wait_status, 0);
		if (WIFEXITED(wait_status) && WEXITSTATUS(wait_status) == 1)
		{
			i = -1;
			while (++i < args->nbr_philo)
				kill(args->philos[i].philo_id, SIGTERM);
			break ;
		}
	}
	i = -1;
	while (++i < args->nbr_philo)
	{
		sem_unlink("/sema");
	}
	return (1);
}

void	close_semaphore(t_args_b *args)
{
	sem_close(args->s_forks);
	sem_close(args->s_message);
	sem_close(args->s_meal_death);
	sem_close(args->all_eat);
	sem_close(args->death);
	sem_unlink("forks");
	sem_unlink("messages");
	sem_unlink("meal_death");
	sem_unlink("all_eat");
	sem_unlink("death");
}
