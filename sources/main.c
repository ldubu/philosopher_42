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
	t_time	args;
	int		nbr_philo;

	nbr_philo = parsing(argc, argv, &args);
	if (nbr_philo <= 0)
		return (1);
	printf("philo = %d, die = %lu, eat = %lu, sleep = %lu\n", nbr_philo, \
	args.time_to_die, args.time_to_eat, args.time_to_sleep);
	return (0);
}