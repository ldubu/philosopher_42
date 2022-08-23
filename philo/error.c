/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/01 13:14:23 by marvin            #+#    #+#             */
/*   Updated: 2022/07/01 13:14:23 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	error_message(int type)
{
	if (type == 1)
		printf("./philo number_of_philosophers time_to_die time_to_eat \
		time_to_sleep [number_of_times_each_philosopher_must_eat]\n");
	else if (type == 2)
		printf("Arguments must be positive number\n");
	else if (type == 3)
		printf("Problem while initializing mutex\n");
	else if (type == 4)
		printf("Problem during thread creation\n");
	else if (type == 5)
		printf("Philosopher number must be between 1 and 200");
	return (1);
}
