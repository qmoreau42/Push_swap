# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: qmoreau <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/01/06 14:04:05 by qmoreau           #+#    #+#              #
#    Updated: 2022/03/09 14:11:59 by qmoreau          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = gcc

NAME = push_swap

FLAGS = -Wall -Wextra -Werror

SRCS = push_swap.c\


OBJS = $(SRCS:.c=.o)

$(NAME) : $(OBJS)
			cd Libft && $(MAKE) bonus
			cp Libft/libft.a $(NAME).a
			ar -rcs $(NAME).a $(OBJS)
			$(CC) $(FLAGS) -o $(NAME) $(NAME).a

all : $(NAME)

clean :
		rm -f $(OBJS) $(NAME)
		$(MAKE) clean -C ./Libft

fclean : clean
		rm -f $(NAME).a $(NAME)
		rm -f libft.a
		$(MAKE) fclean -C ./Libft

re : fclean all

.PHONY : fclean clean re all
