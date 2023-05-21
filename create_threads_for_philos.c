/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_threads_for_philos.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taelkhal <taelkhal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/11 15:32:04 by taelkhal          #+#    #+#             */
/*   Updated: 2023/05/21 16:38:40 by taelkhal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	*routine(void *philo)
{
	t_philo	*philos;

	philos = (t_philo *)philo;
	while (1)
	{
		philos_takes_forks_and_eat(philos);
		philo_is_sleep(philos);
		philo_is_think(philos);
	}
	return (NULL);
}

void	create_threads_for_philos(t_philo *philos)
{
	int	i;

	i = 0;
	philos->start = get_time();
	while (i < philos->nb_of_philos)
	{
		pthread_create(&philos->data[i].thread_id, NULL, &routine, &philos->data[i]);
		i++;
		usleep(60);
	}
}
