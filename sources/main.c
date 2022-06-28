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
	int		i;

	i = 0;
	nbr_philo = parsing(argc, argv, &args);
	if (nbr_philo <= 0)
		return (1);
	while (i <= nbr_philo)
	{
		create_philo(&args, i);
		i++;
	}
	return (0);
}