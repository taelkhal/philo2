# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: taelkhal <taelkhal@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/05/03 15:30:16 by taelkhal          #+#    #+#              #
#    Updated: 2023/05/25 17:04:19 by taelkhal         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = philo
CC = cc
FLAGS = -Wall -Wextra -Werror -fsanitize=address -g3

SRCS = utils.c args_is_num.c fill_nums.c initialise_struct.c \
		initialise_philosophers.c sleep.c time.c routine_actions.c \
		create_threads_for_philos.c philo.c test.c \


OBJS = $(SRCS:.c=.o)
all : $(NAME)

$(NAME) : $(OBJS)
	$(CC) $(FLAGS) $(OBJS) -o  $(NAME)

clean :
	rm -f $(OBJS)
fclean :
	rm -f $(OBJS)
	rm -f $(NAME)
re : fclean all