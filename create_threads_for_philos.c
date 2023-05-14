/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_threads_for_philos.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taelkhal <taelkhal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/11 15:32:04 by taelkhal          #+#    #+#             */
/*   Updated: 2023/05/11 15:46:36 by taelkhal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	create_threads_for_philos(int nb_philos, t_philo *philos)
{
	pthread_t threads[nb_philos];
	int	i;

	i = 0;
	while (i < nb_philos)
	{
		pthread_create(&threds[i], NULL, )
	}
	
	
}