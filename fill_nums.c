/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_nums.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taelkhal <taelkhal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/08 16:00:11 by taelkhal          #+#    #+#             */
/*   Updated: 2023/05/23 13:59:00 by taelkhal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	fill_nums(int ac, char **av)
{
	int i;

	i = 1;
	while (i < ac)
	{
		if (ft_atoi(av[i]) < 1)
		{
			printf("Error: Invalid Arguments\n");
			return (0);
		}
		i++;
	}
	return (1);
}
