# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: dferrari <dferrari@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/11/23 22:43:35 by dferrari          #+#    #+#              #
#    Updated: 2023/11/24 05:15:13 by dferrari         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a

CC = cc

CFLAGS = -Wall -Werror -Wextra

HEADER = libftprintf.a

SRC = ft_printf.c \
	  ft_printhex.c \
	  ft_printp.c \
	  ft_printunsigned.c \
	  ft_put.c \
	  ft_strlen.c \
	  ft_targeting.c \
	  
OBJ = $(SRC:.c=.o)

all: $(NAME)

RM = rm -f

$(NAME): $(OBJ)
	ar rcs $@ $^

%.o: %.c
	$(CC) $(CFLAGS) -I $(HEADER) -c $< -o $@

clean:
	$(RM) $(OBJ)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: re fclean clean