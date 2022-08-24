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
# include <unistd.h>
# include <fcntl.h>
# include <sys/stat.h>
# include <sys/types.h>
# include <sys/wait.h>
# include "../libft/includes/libft.h"
# include <semaphore.h>

struct	s_args_bonus;

typedef struct s_philo_bonus
{
	int					nbr;
	int					meal_nbr;
	long long			last_meal;
	int					philo_id;
	pthread_t			thread_id;
	struct s_args_bonus	*args;
}				t_philo_b;

typedef struct s_args_bonus
{
	int				nbr_philo;
	int				time_die;
	int				time_eat;
	int				time_sleep;
	int				meal_nbr;
	int				all_eat;
	int				death;
	sem_t			*forks;
	sem_t			*message;
	sem_t			*meal_death;
	long long		first_time;
	t_philo_b		philos[250];
}					t_args_b;

/*--------------Error----------------*/
int			error_message(int type);

/*--------------Parsing--------------*/
int			parsing(int ac, char **av, t_args_b *args);

/*--------------Create-philo---------*/
int			create_philo(t_args_b *args);

/*--------------Eat------------------*/
void		eat(t_philo_b *philo, t_args_b *args);

/*--------------Check----------------*/
int			check_death(t_args_b *args, int i);

/*--------------Utils----------------*/
long long	get_time(void);
void		message(t_args_b *args, int philo_n, char *action);
void		smart_sleep(long long time, t_args_b *args);
int			wait_philo(t_args_b *args);

#endif
