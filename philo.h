/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taelkhal <taelkhal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/03 15:36:23 by taelkhal          #+#    #+#             */
/*   Updated: 2023/05/25 16:46:32 by taelkhal         ###   ########.fr       */
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

typedef struct s_data
{
	int			philo_id;
	long long	last_meal;
	pthread_t	thread_id;
	int			coounter_of_meals;
	struct s_philo 	*philo;
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
	pthread_mutex_t time;
	long long	start_time;
	pthread_mutex_t philo_is_eat;
	pthread_mutex_t mutex; // mutex2
	pthread_mutex_t mat; // mutex 1
	pthread_mutex_t is_done; // mutex 1
	pthread_mutex_t mutex2; // mutex 1
	int 			philo_is_died;
	int 			done_eating;
	t_data			*data;
}					t_philo;


int	args_is_num(int ac, char **av);
int	fill_nums(int ac, char **av);
void	initialise_struct(t_philo *philos, int ac, char **av);
void	*initialise_philosophers(t_philo *philos);
void	ft_sleep(int t);
long long	get_time(void);
void	write_msg(t_data *data, char *msg);
void	philos_takes_forks_and_eat(t_data *data);
void	philo_is_sleep(t_data *data);
void	philo_is_think(t_data *data);
void 	create_threads_for_philos(t_philo *philos);
int	philo_is_dead(t_data *data);
// test 
int	check_death(t_data *data);
int	not_done_eating(t_data *data);
void	lock(t_data **data);
void	unlock(t_data **data);

#endif






// is done
// mutex 2