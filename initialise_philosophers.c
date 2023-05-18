/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initialise_philosophers.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taelkhal <taelkhal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/16 15:46:19 by taelkhal          #+#    #+#             */
/*   Updated: 2023/05/17 15:41:35 by taelkhal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	initialise_philosophers(t_arguments *args)
{
	int	i;
	int nb_philos;

	i = 0;
	nb_philos = args->nb_of_philo;
	args->philos = malloc(sizeof(t_philo) * nb_philos);
	if (!nb_philos)
		return ;
	while (i < nb_philos)
	{
		args->philos[i].id = i + 1;
		args->philos[i].args = args;
		args->philos[i].time_to_die = args->time_to_die;
		args->philos[i].time_to_eat = args->time_to_eat;
		args->philos[i].time_to_sleep = args->time_to_sleep;
		args->philos[i].num_of_meals = 0;
		args->philos[i].last_meal = 0;
		args->philos[i].philo_is_eat = 0;
		args->philos[i].left_fork = &args->fork_mutex[i];
		args->philos[i].right_fork = &args->fork_mutex[(i + 1) % nb_philos];
		i++;
	}
	return ;
}

