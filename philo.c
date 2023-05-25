/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taelkhal <taelkhal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/21 16:07:25 by taelkhal          #+#    #+#             */
/*   Updated: 2023/05/25 17:00:19 by taelkhal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int main(int ac, char **av)
{
	t_philo *philos;

	if (ac == 5 || ac == 6)
	{
	    philos = malloc(sizeof(t_philo));
	    if (!args_is_num(ac, av))
		{
			printf ("%s", "Error: Invalid Number\n");
			return (0);
		}
		if (!fill_nums(ac, av))
			return (0);
		initialise_struct(philos, ac, av);
		create_threads_for_philos(philos);
		check_death(philos->data);
	}
	else 
		printf ("%s", "Error: Invalid Number Of Arguments\n");
	return (0);
}