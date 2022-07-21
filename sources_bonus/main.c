/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/19 14:25:44 by marvin            #+#    #+#             */
/*   Updated: 2022/07/19 14:25:44 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

t_args	args;

	if (argc != 5 && argc != 6)
		return (error_message(1));
	if (parsing(argc, argv, &args))
		return (1);
	create_philo(&args);
	sem_close();
	sem_unlink();
	wait_philo();
	return (0);