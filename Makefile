# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: fbbot <marvin@42.fr>                       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/11/28 10:42:22 by fbbot             #+#    #+#              #
#    Updated: 2023/11/28 10:47:10 by fbbot            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME := libftprintf.a
CC := cc
CFLAGS := -Wall -Wextra -Werror -I.
SRCS := ft_printf.c 
OBJS := $(SRCS:%.c=%.o)
BSRCS := $(SRCS) 
BOBJS := $(BSRCS:.c=.o)

.PHONY : all bonus clean fclean re

all : $(NAME)

$(NAME) : $(OBJS)
	ar rcs $(NAME) $(OBJS)

bonus : $(BOBJS)
	ar rcs $(NAME) $(BOBJS)

clean :
	rm -rf $(BOBJS)

fclean : clean
	rm -rf $(NAME)

re : fclean all
