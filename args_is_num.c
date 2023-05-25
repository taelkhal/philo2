/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   args_is_num.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taelkhal <taelkhal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/08 15:54:46 by taelkhal          #+#    #+#             */
/*   Updated: 2023/05/23 15:40:15 by taelkhal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	args_is_num(int ac, char **av)
{
	int	i;

	i = 1;
	while (i < ac)
	{
		if (ft_isdigit(ft_atoi(av[i])))
			return (0);
		i++;
	}
	return (1);
}
