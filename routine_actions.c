/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine_actions.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taelkhal <taelkhal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/21 15:28:17 by taelkhal          #+#    #+#             */
/*   Updated: 2023/05/21 17:03:14 by taelkhal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	write_msg(t_philo *philos, char *msg)
{
	int	timestamp;

	timestamp = get_time() - philos->start;
	pthread_mutex_lock(&philos->data->print);
	printf ("%d philo %d %s\n", timestamp, philos->data->id, msg);
	pthread_mutex_unlock(&philos->data->print);
}

void	philos_takes_forks_and_eat(t_philo *philos)
{
	pthread_mutex_lock(&philos->right_fork);
	write_msg(philos, " has taken a fork");
	pthread_mutex_lock(&philos->left_fork);
	write_msg(philos, " has taken a fork");
	pthread_mutex_lock(&philos->data->philo_is_eat);
	write_msg(philos, " is eating");
	pthread_mutex_lock(&philos->mutex);
	philos->data->last_meal = get_time();
	ft_sleep(philos->time_to_eat);
	philos->num_of_meals++;
	pthread_mutex_unlock(&philos->mutex);
	pthread_mutex_unlock(&philos->right_fork);
	pthread_mutex_unlock(&philos->left_fork);
}

void	philo_is_sleep(t_philo *philos)
{
	write_msg(philos, " is sleeping");
	ft_sleep(philos->time_to_sleep);
}

void	philo_is_think(t_philo *philos)
{
	write_msg(philos, " is thinking");
}

int	philo_is_dead(t_philo *philos)
{
	int	i;
	int	t;

	i = 0;
	while (i < philos->nb_of_philos)
	{
		pthread_mutex_lock(&philos->data->philo_is_eat);
		t = get_time() - philos->data[i].last_meal;
		if (t >= philos->time_to_die)
		{
			write_msg(&philos->data[i], " died ");
			return (0);
		}
		i++;
	}
	return (1);
}
