# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: hkaddour <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/01/14 13:09:58 by hkaddour          #+#    #+#              #
#    Updated: 2022/01/15 17:03:29 by hkaddour         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a
CC = gcc
HEADER = ft_printf.h 
CFLAGS = -Wall -Wextra -Werror
SRCS = ft_printf.c \
	   ft_printf_utils.c

OBJS = $(SRCS:.c=.o)

all : $(NAME)

%.o: %.c
	$(CC) $(CFLAGS) -c $^ -I $(HEADER) 

$(NAME): $(OBJS)
	ar -rc $@ $^

clean:
	rm -rf $(OBJS)
	rm -rf *.o

fclean: clean
	rm -rf $(NAME)

re: fclean all

.PHONY: all clean fclean re
