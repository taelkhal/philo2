/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initialise_struct.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taelkhal <taelkhal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/17 15:42:42 by taelkhal          #+#    #+#             */
/*   Updated: 2023/05/17 16:00:55 by taelkhal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	initialise_struct(t_arguments *args, int ac, char **av)
{
	int	i;

	i = 0;
	if (ac == 5 || ac == 6)
	{
		args->nb_of_philo = ft_atoi(av[1]);
		args->time_to_die = ft_atoi(av[2]);
		args->time_to_eat = ft_atoi(av[3]);
		args->time_to_sleep = ft_atoi(av[4]);
		if (ac == 6)
			args->num_of_meals = ft_atoi(av[5]);
		else
			args->num_of_meals = 0;
		args->philo_is_dead = 0;
	}
}