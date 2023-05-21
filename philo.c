/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taelkhal <taelkhal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/21 16:07:25 by taelkhal          #+#    #+#             */
/*   Updated: 2023/05/21 16:53:48 by taelkhal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int main(int ac, char **av)
{
	t_philo *philos;

	if (ac == 5 || ac == 6)
	{
	    philos = malloc(sizeof(t_philo));
		if (philos->num_of_meals == 0)
			return(0);
	    if (!args_is_num(ac, av))
		{
			printf ("%s", "Error: Invalid Number\n");
			return (0);
		}
		if (!fill_nums(ac, av))
			return (0);
		initialise_struct(philos, ac, av);
		exit (1);
		create_threads_for_philos(philos);
	}
	printf ("%s", "Error: Invalid Number Of Arguments\n");
}