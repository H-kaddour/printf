# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: hkaddour <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/01/14 13:09:58 by hkaddour          #+#    #+#              #
#    Updated: 2022/01/16 17:04:06 by hkaddour         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a
CC = gcc
HEADER = ft_printf.h 
CFLAGS = -Wall -Wextra -Werror
SRCS = ft_printf.c \
	   ft_printf_utils.c \
	   ft_putnbr.c

OBJS = $(SRCS:.c=.o)

YELLOW=$'\x1b[33m
BLUE=$'\x1b[34m
CYAN=$'\x1b[36m

all : $(NAME)

%.o: %.c
	@echo "$(CYAN) compile $(YELLOW) $^ $(BLUE)to $@"
	@$(CC) $(CFLAGS) -c $^ -I $(HEADER) 

$(NAME): $(OBJS) $(HEADER)
	@echo "$(CYAN) make $(BLUE) $@"
	@ar -rc $@ $^

clean:
	@echo "$(CYAN) clean"
	@rm -rf $(OBJS)

fclean: clean
	@echo "$(CYAN) fclean"
	@rm -rf $(NAME)

re: fclean all

.PHONY: all clean fclean re
