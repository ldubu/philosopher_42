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

void	*routine(void *philo)
{
	t_philo	*true_philo;

	true_philo = (t_philo *)philo;
	printf("Je suis le philo %d\n", true_philo->nbr);
	return(philo);
}

int	create_philo(t_time *args, int i)
{
	pthread_t	tid;
	t_philo		philo;

	philo.nbr = i;
	pthread_create(&tid, NULL, &routine, (void *)&philo);
	(void) args;
	return (1);
}