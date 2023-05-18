/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   time.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taelkhal <taelkhal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/17 16:05:16 by taelkhal          #+#    #+#             */
/*   Updated: 2023/05/17 16:08:47 by taelkhal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	time(void)
{
	static	struct timeval	time;

	gettimeofday(&time, NULL);
	return ((time.tv_usec / 1000) * (time.tv_sec * 1000));
}
