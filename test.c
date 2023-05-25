/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taelkhal <taelkhal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/25 14:02:08 by taelkhal          #+#    #+#             */
/*   Updated: 2023/05/25 16:55:32 by taelkhal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	check_death(t_data *data)
{
	int	i;

	while (1)
	{
		i = -1;
		while (++i < data->philo->nb_of_philos)
		{
			lock(&data);
			if (data[i].philo->time_to_die <= get_time() - data[i].last_meal)
			{
				if (!(not_done_eating(data)))
					return (0);
				else if (data[i].philo->done_eating == 1)
					data->coounter_of_meals++;
				if (data->coounter_of_meals == data->philo->nb_of_philos)
					return (0);
			}
			unlock(&data);
		}
	}
	return (1);
}

int	not_done_eating(t_data *data)
{
	int	i;

	i = 0;
	if (data->philo[i].done_eating != 1)
	{
        pthread_mutex_lock(&data->philo->is_done);
		printf("%lld philo %d died\n", get_time() - data->philo->start_time,
			data->philo_id);
        pthread_mutex_lock(&data->philo->print);
		return (0);
	}
	return (1);
}

void	lock(t_data **data)
{
	pthread_mutex_lock(&(*data)->philo->mutex);
	pthread_mutex_lock(&(*data)->philo->mutex2);
}

void	unlock(t_data **data)
{
	pthread_mutex_unlock(&(*data)->philo->mutex2);
	pthread_mutex_unlock(&(*data)->philo->mutex);
}