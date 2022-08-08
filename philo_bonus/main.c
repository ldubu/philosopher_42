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

int	main(int argc, char **argv)
{
	t_args_b	args;

	if (argc != 5 && argc != 6)
		return (error_message(1));
	if (parsing(argc, argv, &args))
		return (1);
	create_philo(&args);
	sem_close(args.forks);
	sem_unlink("forks");
	sem_unlink("messages");
	wait_philo(&args);
	return (0);
}
