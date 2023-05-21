/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initialise_struct.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taelkhal <taelkhal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/17 15:42:42 by taelkhal          #+#    #+#             */
/*   Updated: 2023/05/21 16:56:57 by taelkhal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	init_mutex(t_philo *philos)
{
	int	i;

	i = 0;
	philos->forks_mutex = malloc(sizeof(pthread_mutex_t) * philos->nb_of_philos);
	if (!philos->forks_mutex)
		return ;
	while (i < philos->nb_of_philos)
	{
		pthread_mutex_init(&philos->forks_mutex[i], NULL);
		i++;
	}
	pthread_mutex_init(&philos->mutex, NULL);
	return ;
	
}
void	initialise_struct(t_philo *philos, int ac, char **av)
{
	int	i;

	i = 0;
	if (ac == 5 || ac == 6)
	{
		philos->nb_of_philos = ft_atoi(av[1]);
		philos->time_to_die = ft_atoi(av[2]);
		philos->time_to_eat = ft_atoi(av[3]);
		philos->time_to_sleep = ft_atoi(av[4]);
		if (ac == 6)
			philos->num_of_meals = ft_atoi(av[5]);
		else
			philos->num_of_meals = -1;
		exit (1);
		philos->start = get_time();
		philos->philo_is_dead = 0;
		init_mutex(philos);
		philos = initialise_philosophers(philos);
	}
}
