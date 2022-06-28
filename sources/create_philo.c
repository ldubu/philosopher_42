/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_philo.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/28 09:59:36 by marvin            #+#    #+#             */
/*   Updated: 2022/06/28 09:59:36 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static void	philo_init(t_philo *philo, t_time *args, t_cutlery *cutlery, int i)
{
	philo->state = THINK;
	philo->nbr = i;
	if (i != 1)
		philo->left_fork = i - 2;
	else
		philo->left_fork = args->nbr_philo - 1;
	if (i != args->nbr_philo)
		philo->right_fork = i;
	else
		philo->right_fork = 0;
	philo->nbr_of_meal = 0;
	philo->info = *args;
	philo->cutlery = cutlery;
}

static void	*routine(void *false_philo)
{
	t_philo	*philo;
	int hungry = 1;

	philo = (t_philo *)false_philo;
	printf("Je suis le philo %d\n", philo->nbr);
	if (philo->nbr % 2)
		usleep(500);
	else
		usleep(100);
	while (hungry)
	{
		if (philo->cutlery->forks[philo->left_fork])
		{
			pthread_mutex_lock(philo->cutlery->mutex_fork + philo->left_fork);
			philo->cutlery->forks[philo->left_fork] = TAKEN_FORK;
			if (philo->cutlery->forks[philo->right_fork])
			{
				pthread_mutex_lock(philo->cutlery->mutex_fork + philo->right_fork);
				philo->cutlery->forks[philo->right_fork] = TAKEN_FORK;
				printf("philo %d is eating\n", philo->nbr);
				hungry = 0;
				usleep(philo->info.time_to_eat);
				philo->cutlery->forks[philo->right_fork] = FREE_FORK;
				pthread_mutex_unlock(philo->cutlery->mutex_fork + philo->right_fork);
			}
			philo->cutlery->forks[philo->left_fork] = FREE_FORK;
			pthread_mutex_unlock(philo->cutlery->mutex_fork + philo->left_fork);
		}
	}
	return(philo);
}

int	create_philo(t_time *args, t_cutlery *cutlery, int i)
{
	pthread_t	tid;
	t_philo		philo;

	philo_init(&philo, args, cutlery, i);
	pthread_create(&tid, NULL, &routine, (void *)&philo);
	usleep(5);
	(void) args;
	return (1);
}