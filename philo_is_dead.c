/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_is_dead.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taelkhal <taelkhal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/18 15:24:22 by taelkhal          #+#    #+#             */
/*   Updated: 2023/05/18 16:00:21 by taelkhal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	philo_is_dead(t_philo *philo)
{
	pthread_mutex_lock(&philo->args->mutex);
	if (philo->args->philo_is_dead == 1)
	{
		pthread_mutex_unlock(&philo->args->mutex);
		return (1);
	}
	pthread_mutex_unlock(&philo->args->mutex);
	return (0);
}