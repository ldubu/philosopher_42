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

int	main(int argc, char ** argv)
{
	t_args	args;

	if (argc != 5 && argc != 6)
		return (error_message(1));
	if (parsing(argc, argv, &args))
		return (1);
	create_philo(&args);
	return (0);
}
