/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_nums.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taelkhal <taelkhal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/08 16:00:11 by taelkhal          #+#    #+#             */
/*   Updated: 2023/05/21 16:19:31 by taelkhal         ###   ########.fr       */
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
			printf("Error: Invalid Arguments\n", 2);
			return (0);
		}
		i++;
	}
	return (1);
}
