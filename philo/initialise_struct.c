/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initialise_struct.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taelkhal <taelkhal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/17 15:42:42 by taelkhal          #+#    #+#             */
/*   Updated: 2023/05/31 16:15:43 by taelkhal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	init_mutex(t_philo *philos)
{
	int	i;

	i = 0;
	philos->forks = malloc(sizeof(pthread_mutex_t) * philos->nb_of_philos);
	while (i < philos->nb_of_philos)
	{
		pthread_mutex_init(&philos->forks[i], NULL);
		i++;
	}
	pthread_mutex_init(&philos->died1, NULL);
	pthread_mutex_init(&philos->finish, NULL);
	pthread_mutex_init(&philos->print, NULL);
	pthread_mutex_init(&philos->philo_is_eat, NULL);
	pthread_mutex_init(&philos->time, NULL);
	pthread_mutex_init(&philos->died2, NULL);
	pthread_mutex_init(&philos->is_done, NULL);
	return ;
}

void	initialise_struct(t_philo *philos, int ac, char **av)
{
	philos->nb_of_philos = ft_atoi(av[1]);
	philos->time_to_die = ft_atoi(av[2]);
	philos->time_to_eat = ft_atoi(av[3]);
	philos->time_to_sleep = ft_atoi(av[4]);
	if (ac == 6)
		philos->num_of_meals = ft_atoi(av[5]);
	else
		philos->num_of_meals = -1;
	philos->start_time = get_time();
	philos->forks = NULL;
	initialise_philosophers(philos);
	init_mutex(philos);
}
