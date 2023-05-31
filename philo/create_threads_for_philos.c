/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_threads_for_philos.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taelkhal <taelkhal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/11 15:32:04 by taelkhal          #+#    #+#             */
/*   Updated: 2023/05/31 16:15:34 by taelkhal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	*routine(void *arg)
{
	t_data	*data;

	data = (t_data *)arg;
	if (!(data->philo_id % 2))
		ft_sleep(data->philo->time_to_eat);
	while (1)
	{
		philos_takes_forks_and_eat(data);
		pthread_mutex_lock(&data->philo->philo_is_eat);
		data->counter_of_meals++;
		pthread_mutex_unlock(&data->philo->philo_is_eat);
		if (data->philo->num_of_meals != -1
			&& data->counter_of_meals >= data->philo->num_of_meals)
		{
			pthread_mutex_lock(&data->philo->finish);
			data->philo->done_eating = 1;
			pthread_mutex_unlock(&data->philo->finish);
			break ;
		}
		philo_is_sleep(data);
		philo_is_think(data);
	}
	return (NULL);
}

void	create_threads_for_philos(t_philo *philos)
{
	int	i;

	i = 0;
	while (i < philos->nb_of_philos)
	{
		pthread_create(&philos->data[i].thread_id, NULL,
			&routine, &philos->data[i]);
		pthread_detach(philos->data[i].thread_id);
		i++;
		usleep(60);
	}
}
