/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sleep.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taelkhal <taelkhal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/17 16:09:01 by taelkhal          #+#    #+#             */
/*   Updated: 2023/05/25 16:04:08 by taelkhal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	ft_sleep(int t)
{
	long long	begin;

	begin = get_time();
	usleep(t * 1000 * 0.9);
	while (get_time() - begin < (long int)t)
		usleep(50);
}
