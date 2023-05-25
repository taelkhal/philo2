/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine_actions.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taelkhal <taelkhal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/21 15:28:17 by taelkhal          #+#    #+#             */
/*   Updated: 2023/05/25 16:56:32 by taelkhal         ###   ########.fr       */
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
	pthread_mutex_lock(&data->philo->forks[data->philo_id % data->philo->nb_of_philos]);
	write_msg(data, "has taken a fork");
	// pthread_mutex_lock(&data->philo->philo_is_eat);
	write_msg(data, "is eating");
	// pthread_mutex_unlock(&data->philo->philo_is_eat);
	pthread_mutex_lock(&data->philo->time);
	data->last_meal = get_time();
	pthread_mutex_unlock(&data->philo->time);
	ft_sleep(data->philo->time_to_eat);
	// data->philo->num_of_meals++;
	pthread_mutex_unlock(&data->philo->forks[data->philo_id - 1]);
	pthread_mutex_unlock(&data->philo->forks[data->philo_id % data->philo->nb_of_philos]);
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

// int	philo_is_dead(t_data *data)
// {
// 	int	i;
// 	int	t;

// 	i = 0;
// 	while (i < data->philo->nb_of_philos)
// 	{
// 		pthread_mutex_lock(&data->philo->philo_is_eat);
// 		t = get_time() - data[i].last_meal;
// 		if (t >= data->philo->time_to_die)
// 		{
// 			write_msg(data, " died ");
// 			return (0);
// 		}
// 		i++;
// 	}
// 	return (1);
// }
