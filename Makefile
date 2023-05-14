# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: taelkhal <taelkhal@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/05/03 15:30:16 by taelkhal          #+#    #+#              #
#    Updated: 2023/05/03 15:35:34 by taelkhal         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = philo
CC = cc
FLAGS = -Wall -Wextra -Werror
SRCS =


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