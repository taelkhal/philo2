/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taelkhal <taelkhal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/03 15:36:23 by taelkhal          #+#    #+#             */
/*   Updated: 2023/05/30 16:22:18 by taelkhal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <pthread.h>
# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include <sys/time.h>

# define RED	"\033[1m\033[31m"
//libft
int			ft_isdigit(int c);
int			ft_atoi(const char *str);

typedef struct s_data
{
	int				philo_id;
	long long		last_meal;
	pthread_t		thread_id;
	int				counter_of_meals;
	int				meals_eating_by_philo;
	struct s_philo	*philo;
}					t_data;

typedef struct s_philo
{	
	int				nb_of_philos;
	int				time_to_die;
	int				time_to_eat;
	int				time_to_sleep;
	int				num_of_meals;
	pthread_mutex_t	print;
	pthread_mutex_t	*forks;
	pthread_mutex_t	time;
	long long		start_time;
	pthread_mutex_t	philo_is_eat;
	pthread_mutex_t	mutex;
	pthread_mutex_t	mat;
	pthread_mutex_t	is_done;
	pthread_mutex_t	mutex2;
	int				done_eating;
	t_data			*data;
}					t_philo;

long long	get_time(void);
void		ft_sleep(int t);
int			args_is_num(int ac, char **av);
int			fill_nums(int ac, char **av);
void		initialise_struct(t_philo *philos, int ac, char **av);
void		*initialise_philosophers(t_philo *philos);
void		write_msg(t_data *data, char *msg);
void		philos_takes_forks_and_eat(t_data *data);
void		philo_is_sleep(t_data *data);
void		philo_is_think(t_data *data);
void		create_threads_for_philos(t_philo *philos);
int			check_if_philo_died(t_data *data);

#endif