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

struct s_args;

typedef struct s_philo
{
	int				nbr;
	int				left_fork;
	int				right_fork;
	int				meal_nbr;
	long long		last_meal;
	pthread_t		thread_id;
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
	pthread_mutex_t	forks[250];
	pthread_mutex_t	message;
	pthread_mutex_t meal;
	long long		first_time;
	t_philo			philos[250];
}					t_args;

/*----------Error message---------*/
int	error_message(int type);

/*----------Parsing---------------*/
int	parsing(int ac, char **av, t_args *args);

/*-----------Utils------------*/
long long	get_time(void);
void		message(t_args *args, int philo_n, char *action);
void	eat(t_philo *philo, t_args *args);
int	create_philo(t_args *args);
void		smart_sleep(long long time, t_args *args);

#endif