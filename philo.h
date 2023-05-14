/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taelkhal <taelkhal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/03 15:36:23 by taelkhal          #+#    #+#             */
/*   Updated: 2023/05/14 15:54:37 by taelkhal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <pthread.h>
# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include <sys/time.h>


//libft
int		ft_isdigit(int c);
int		ft_atoi(const char *str);
void	ft_putstr_fd(char *str, int fd);

typedef struct s_arguments
{	
	int				nb_of_philo;
	unsigned int	time_to_die;
	unsigned int	time_to_eat;
	unsigned int	time_to_sleep;
	int				num_of_meals;
	int				start;
	int				philo_is_dead;
	pthread_mutex_t *left_fork;
	pthread_mutex_t *right_fork;
	pthread_mutex_t	*fork_mutex;
	pthread_mutex_t	mutex;
	t_philo			*philos;
}					t_arguments;

typedef struct s_philo
{
	int				id;
	pthread_t		thread_id;
    unsigned int	time_to_die;
	unsigned int	time_to_eat;
	unsigned int	time_to_sleep;
	int				num_of_meals;	
	int				last_meal;
	int				philo_is_eat;
	pthread_mutex_t *left_fork;
	pthread_mutex_t *right_fork;
	struct s_arguments 	*args;
}					t_philo;

#endif