# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: heahn <heahn@student.42seoul.kr>           +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/10/10 10:42:23 by heahn             #+#    #+#              #
#    Updated: 2021/11/04 04:02:27 by heahn            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS = main.c 

OBJS = $(SRCS:.c=.o)

NAME = push_swap

RM	= rm -rf
LIB = ar rcu
CC = gcc
CFLAGS = -Wall -Wextra -Werror



all	: $(NAME)

$(NAME) : $(OBJS)
	@echo "==COMPILE $(NAME)=="
	@$(CC) $(CFLAGS) -o $(NAME) $(OBJS)



clean : 
	@echo "==REMOVE OBJECT FILE=="
	@$(RM) $(OBJS)

fclean : clean
	@echo "==REMOVE $(NAME)=="	
	@$(RM) $(NAME)

re : fclean all

.PHONY: all clean fclean re bonus
