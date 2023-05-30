/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initialise_philosophers.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taelkhal <taelkhal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/16 15:46:19 by taelkhal          #+#    #+#             */
/*   Updated: 2023/05/27 18:01:29 by taelkhal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	*initialise_philosophers(t_philo *philos)
{
	int	i;

	i = 0;
	philos->data = malloc(sizeof(t_data) * philos->nb_of_philos);
	if (!(philos->data))
		return (NULL);
	while (i < philos->nb_of_philos)
	{
		philos->data[i].philo_id = i + 1 ;
		philos->data[i].last_meal = get_time();
		philos->data[i].counter_of_meals = 0;
		philos->data[i].meals_eating_by_philo = 0;
		philos->data[i].philo = philos;
		i++;
	}
	return (NULL);
}
