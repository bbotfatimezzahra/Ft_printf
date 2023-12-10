# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: fbbot <marvin@42.fr>                       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/11/28 10:42:22 by fbbot             #+#    #+#              #
#    Updated: 2023/12/06 15:28:43 by fbbot            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME := libftprintf.a
CC := cc
CFLAGS := -Wall -Wextra -Werror
SRCS := ft_printf.c ft_writearg.c ft_putstr.c ft_putnbr.c ft_putnbr_base.c \
	ft_putpointer.c ft_writeflag.c ft_putsign.c ft_putzero.c
OBJS := $(SRCS:%.c=%.o)

.PHONY : all bonus clean fclean re 

all : $(NAME)

$(NAME) : $(OBJS)
	ar rcs $(NAME) $(OBJS)

bonus : $(NAME)

clean :
	rm -rf $(OBJS) 

fclean : clean
	rm -rf $(NAME)

re : fclean all
