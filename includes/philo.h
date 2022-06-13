/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldubuche <laura.dubuche@gmail.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/10 13:29:00 by ldubuche          #+#    #+#             */
/*   Updated: 2022/06/10 13:29:00 by ldubuche         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <sys/time.h>
# include <stdio.h>
# include "../libft/includes/libft.h"

typedef enum e_state
{
	EAT = 0,
	SLEEP,
	THINK,
}				t_state;

typedef struct s_time
{
	long	time_to_die;
	long	time_to_eat;
	long	time_to_sleep;
	long	nbr_of_time;
}				t_time;

typedef struct s_philo
{
	t_state	state;
	int		nbr;
	int		nbr_of_meal;
	long	last_meal;
	t_time	info;
}		t_philo;

int	parsing(int ac, char **av, t_time *args);

#endif