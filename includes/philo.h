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
# include <pthread.h>
# include <stdio.h>
# include <stdbool.h>
# include "../libft/includes/libft.h"

# define TAKEN_FORK false
# define FREE_FORK	true

typedef enum e_state
{
	EAT = 0,
	SLEEP,
	THINK,
}				t_state;

typedef struct s_cutlery
{
	pthread_mutex_t	*mutex_fork;
	bool			*forks;
}					t_cutlery;

typedef struct s_time
{
	int		nbr_philo;
	long	time_to_die;
	long	time_to_eat;
	long	time_to_sleep;
	long	nbr_of_time;
}			t_time;

typedef struct s_philo
{
	t_state		state;
	int			nbr;
	int			left_fork;
	int			right_fork;
	int			nbr_of_meal;
	long		last_meal;
	t_time		info;
	t_cutlery	*cutlery;
}				t_philo;

int	parsing(int ac, char **av, t_time *args);
int	create_philo(t_time *args, t_cutlery *cutlery, int i);

#endif