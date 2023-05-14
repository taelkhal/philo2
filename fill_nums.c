/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_nums.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taelkhal <taelkhal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/08 16:00:11 by taelkhal          #+#    #+#             */
/*   Updated: 2023/05/08 16:06:24 by taelkhal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	fill_nums(int ac, char **av)
{
	int i;

	i = 1;
	while (i < ac)
	{
		if (ft_atoi(av[i]) < 1)
		{
			ft_putstr("Error: Invalid Arguments\n", 2);
			exit (0);
		}
		i++;
	}
}