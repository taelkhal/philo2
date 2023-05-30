/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_if_philo_died.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taelkhal <taelkhal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/25 14:02:08 by taelkhal          #+#    #+#             */
/*   Updated: 2023/05/28 15:15:58 by taelkhal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	not_finish_eat(t_data *data)
{
	int	i;

	i = 0;
	if (data->philo[i].done_eating != 1)
	{
		pthread_mutex_lock(&data->philo->is_done);
		write_msg(data, "died");
		pthread_mutex_lock(&data->philo->print);
		return (0);
	}
	return (1);
}

int	check_if_philo_died(t_data *data)
{
	int	i;

	while (1)
	{
		i = -1;
		while (++i < data->philo->nb_of_philos)
		{
			pthread_mutex_lock(&data->philo->mutex);
			pthread_mutex_lock(&data->philo->mutex2);
			if (data[i].philo->time_to_die <= get_time() - data[i].last_meal)
			{
				if (!(not_finish_eat(data)))
					return (0);
				else if (data[i].philo->done_eating == 1)
					data->meals_eating_by_philo++;
				if (data->meals_eating_by_philo == data->philo->nb_of_philos)
					return (0);
			}
			pthread_mutex_unlock(&data->philo->mutex2);
			pthread_mutex_unlock(&data->philo->mutex);
		}
	}
	return (1);
}
