/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine_actions.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taelkhal <taelkhal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/21 15:28:17 by taelkhal          #+#    #+#             */
/*   Updated: 2023/05/30 16:30:38 by taelkhal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	write_msg(t_data *data, char *msg)
{
	int	timestamp;

	timestamp = get_time() - data->philo->start_time;
	pthread_mutex_lock(&data->philo->print);
	printf ("%d philo %d %s\n", timestamp, data->philo_id, msg);
	pthread_mutex_unlock(&data->philo->print);
}

void	philos_takes_forks_and_eat(t_data *data)
{
	pthread_mutex_lock(&data->philo->forks[data->philo_id - 1]);
	write_msg(data, "has taken a fork");
	pthread_mutex_lock(&data->philo->forks[data->philo_id
		% data->philo->nb_of_philos]);
	write_msg(data, "has taken a fork");
	write_msg(data, "is eating");
	pthread_mutex_lock(&data->philo->time);
	data->last_meal = get_time();
	pthread_mutex_unlock(&data->philo->time);
	ft_sleep(data->philo->time_to_eat);
	pthread_mutex_unlock(&data->philo->forks[data->philo_id - 1]);
	pthread_mutex_unlock(&data->philo->forks[data->philo_id
		% data->philo->nb_of_philos]);
}

void	philo_is_sleep(t_data *data)
{
	write_msg(data, " is sleeping");
	ft_sleep(data->philo->time_to_sleep);
}

void	philo_is_think(t_data *data)
{
	write_msg(data, " is thinking");
}
