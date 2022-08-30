# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: qmoreau <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/01/06 14:04:05 by qmoreau           #+#    #+#              #
#    Updated: 2022/08/28 18:33:28 by qmoreau          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = gcc -g

NAME = push_swap

FLAGS = -Wall -Wextra -Werror

SRCS = push_swap.c\
	   actions_1.c\
	   actions_2.c\
	   actions_3.c\
	   utils_1.c\
	   utils_2.c\
	   sort.c\
	   sort_1.c\
	   cost.c\



OBJS = $(SRCS:.c=.o)

$(NAME) : $(OBJS)
			cd Libft && $(MAKE) bonus
			cp Libft/libft.a $(NAME).a
			ar -rcs $(NAME).a $(OBJS)
			$(CC) $(FLAGS) -o $(NAME) $(NAME).a

all : $(NAME)

clean :
		rm -f *.o $(NAME)
		$(MAKE) clean -C ./Libft

fclean : clean
		rm -f $(NAME).a $(NAME)
		rm -f libft.a
		$(MAKE) fclean -C ./Libft

re : fclean all

.PHONY : fclean clean re all
