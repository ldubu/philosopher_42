/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_bonus.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/19 14:21:15 by marvin            #+#    #+#             */
/*   Updated: 2022/07/19 14:21:15 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_BONUS_H
# define PHILO_BONUS_H

# include <sys/time.h>
# include <pthread.h>
# include <stdio.h>
# include <stdbool.h>
# include "../libft/includes/libft.h"
# include <semaphore.h>

struct s_args;

typedef struct s_philo
{
	int				nbr;
	int				meal_nbr;
	long long		last_meal;
	pthread_t		philo_id;
	struct s_args	*args;
}				t_philo;


typedef struct s_args
{
	int				nbr_philo;
	int				time_die;
	int				time_eat;
	int				time_sleep;
	int				meal_nbr;
	int				all_eat;
	int				death;
	pthread_mutex_t	message;
	pthread_mutex_t meal;
	long long		first_time;
	t_philo			philos[250];
}					t_args;

/*--------------Error----------------*/
int	error_message(int type);

/*--------------Parsing--------------*/
int	parsing(int ac, char **av, t_args *args);

/*--------------Create-philo---------*/
int	create_philo(t_args *args);

/*--------------Eat------------------*/
void		eat(t_philo *philo, t_args *args);

/*--------------Check----------------*/
void check_death(t_args *args);

/*--------------Utils----------------*/
long long	get_time(void);
void		message(t_args *args, int philo_n, char *action);
void		smart_sleep(long long time, t_args *args);

#endif