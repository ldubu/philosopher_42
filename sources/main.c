/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldubuche <laura.dubuche@gmail.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/13 13:25:07 by ldubuche          #+#    #+#             */
/*   Updated: 2022/06/13 13:25:07 by ldubuche         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	main(int argc, char **argv)
{
	t_time			args;
	int				nbr_philo;
	t_cutlery		cutlery;
	int				i;

	i = 0;
	nbr_philo = parsing(argc, argv, &args);
	if (nbr_philo <= 0)
		return (1);
	cutlery.mutex_fork = (pthread_mutex_t *) malloc(sizeof(pthread_mutex_t) * nbr_philo);
	cutlery.forks = (bool *) malloc(sizeof(bool) * nbr_philo);
	while (i < nbr_philo)
	{
		pthread_mutex_init(cutlery.mutex_fork + i, NULL);
		cutlery.forks[i] = FREE_FORK;
		i++;
	}
	i = 0;
	while (i < nbr_philo)
	{
		create_philo(&args, &cutlery, i+1);
		i++;
	}
	return (0);
}