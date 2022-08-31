/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strisnbr.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/13 13:40:05 by marvin            #+#    #+#             */
/*   Updated: 2022/06/13 13:40:05 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	check_max_int(char *str)
{
	if (str[0] > '2')
		return (1);
	if (str[1] > '1')
		return (1);
	if (str[2] > '4')
		return (1);
	if (str[3] > '7')
		return (1);
	if (str[4] > '4')
		return (1);
	if (str[5] > '8')
		return (1);
	if (str[6] > '3')
		return (1);
	if (str[7] > '6')
		return (1);
	if (str[8] > '4')
		return (1);
	if (str[9] > '7')
		return (1);
	return (0);
}

int	__strisintpos(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] < '0' || str[i] > '9')
			return (1);
		i++;
	}
	if (i > 10)
		return (1);
	else if (i == 10)
		return (check_max_int(str));
	return (0);
}
