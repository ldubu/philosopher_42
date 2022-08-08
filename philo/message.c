/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   message.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/30 14:18:26 by marvin            #+#    #+#             */
/*   Updated: 2022/06/30 14:18:26 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	message(int msg_type, int philo_nbr, t_time *args)
{
	pthread_mutex_lock(args->mutex_msg);
	if (msg_type == 1)
		printf("%d is eating\n", philo_nbr);
	pthread_mutex_unlock(args->mutex_msg);
}
