/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taelkhal <taelkhal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/03 15:36:23 by taelkhal          #+#    #+#             */
/*   Updated: 2023/05/21 17:00:44 by taelkhal         ###   ########.fr       */
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
typedef struct s_philo
{	
	int				nb_of_philos;
	unsigned int	time_to_die;
	unsigned int	time_to_eat;
	unsigned int	time_to_sleep;
	int				num_of_meals;
	int				start;
	int				philo_is_dead;
	pthread_mutex_t *left_fork;
	pthread_mutex_t *right_fork;
	pthread_mutex_t	*forks_mutex;
	pthread_mutex_t	mutex;
	t_data			*data;
}					t_philo;
typedef struct s_data
{
	int				id;
	pthread_t		thread_id;
	int				num_of_meals;	
	int				last_meal;
	int				philo_is_eat;
	pthread_mutex_t *left_fork;
	pthread_mutex_t *right_fork;
	pthread_mutex_t	print;
	struct s_philo 	*philo;
}					t_data;




int	args_is_num(int ac, char **av);
int	fill_nums(int ac, char **av);
void	initialise_struct(t_philo *philos, int ac, char **av);
t_philo	*initialise_philosophers(t_data *data);
void	ft_sleep(int t);
int	get_time(void);
void	write_msg(t_philo *philos, char *msg);
void	philos_takes_forks_and_eat(t_philo *philos);
void	philo_is_sleep(t_philo *philos);
void	philo_is_think(t_philo *philos);
void	create_threads_for_philos(t_philo *philos);
int	philo_is_dead(t_philo *philos);

#endif