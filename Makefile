# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: fbbot <marvin@42.fr>                       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/11/28 10:42:22 by fbbot             #+#    #+#              #
#    Updated: 2023/12/05 14:33:10 by fbbot            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME := libftprintf.a
CC := cc
CFLAGS := -Wall -Wextra -Werror
SRCS := ft_printf.c ft_writearg.c ft_putstr.c ft_putnbr.c ft_putnbr_base.c \
	ft_putpointer.c
OBJS := $(SRCS:%.c=%.o)
BSRCS := ft_writeflag.c 
BOBJS := $(BSRCS:.c=.o)

.PHONY : all bonus clean fclean re

all : $(NAME)

$(NAME) : $(OBJS)
	ar rcs $(NAME) $(OBJS)

$(BOBJS) : $(BSRCS)
	$(CC) $(CFLAGS) -c $(BSRCS)
	ar rcs $(NAME) $(BOBJS)

bonus : $(BOBJS)

clean :
	rm -rf $(OBJS) $(BOBJS)

fclean : clean
	rm -rf $(NAME)

re : fclean all
