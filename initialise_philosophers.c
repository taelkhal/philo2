/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initialise_philosophers.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taelkhal <taelkhal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/16 15:46:19 by taelkhal          #+#    #+#             */
/*   Updated: 2023/05/21 16:57:34 by taelkhal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

t_philo	*initialise_philosophers(t_data *data)
{
	t_philo	*philos;
	int	i;
	int nb_philos;

	i = 0;
	nb_philos = data->philo->nb_of_philos;
	philos = malloc(sizeof(t_philo) * nb_philos);
	if (!nb_philos)
		return (NULL);
	while (i < nb_philos)
	{
		data[i].id = i + 1;
		data[i].philo = philos;
		data[i].num_of_meals = 0;
		data[i].last_meal = 0;
		data[i].philo_is_eat = 0;
		data[i].left_fork = &data->philo->forks_mutex[i];
		data[i].right_fork = &data->philo->forks_mutex[(i + 1) % nb_philos];
		i++;
	}
	return (philos);
}
