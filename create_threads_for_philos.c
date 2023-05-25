/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_threads_for_philos.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taelkhal <taelkhal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/11 15:32:04 by taelkhal          #+#    #+#             */
/*   Updated: 2023/05/25 16:52:05 by taelkhal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

// void	*routine(void *philo)
// {
// 	t_data	*philos;

// 	philos = (t_data *)philo;
// 	while (1)
// 	{
// 		philos_takes_forks_and_eat(philos);
// 		philo_is_sleep(philos);
// 		philo_is_think(philos);
// 		philo_is_dead(philos);
// 	}
// 	return (NULL);
// }



void	*routine(void *arg)
{
	t_data *data;
	int			ate;

	ate = 0;
	data = (t_data *)arg;
	if (!(data->philo_id % 2))
		ft_sleep(data->philo->time_to_eat);
	while (1)
	{
		philos_takes_forks_and_eat(data);
		pthread_mutex_lock(&data->philo->philo_is_eat);
		ate++;
		pthread_mutex_unlock(&data->philo->philo_is_eat);
		if (data->philo->num_of_meals != -1 && ate >= data->philo->num_of_meals)
		{
			pthread_mutex_lock(&data->philo->mat);
			data->philo->done_eating = 1;
			pthread_mutex_unlock(&data->philo->mat);
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
	philos->start_time = get_time();
	while (i < philos->nb_of_philos)
	{
		pthread_create(&philos->data[i].thread_id, NULL,
			&routine, &philos->data[i]);
		pthread_detach(philos->data[i].thread_id);
		i++;
		usleep(50);
	}
}

// void	create_threads_for_philos(t_philo *philos)
// {
// 	int	i;

// 	i = 0;
// 	philos->start = get_time();
// 	while (i < philos->nb_of_philos)
// 	{
// 		pthread_create(&philos->data[i].thread_id, NULL, &routine, &philos->data[i]); 
// 		pthread_detach(philos->data[i].thread_id);
// 		i++;
// 		// add thread_join
// 		usleep(60);
// 	}
// }


