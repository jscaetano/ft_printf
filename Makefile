# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: joacaeta <joacaeta@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/10/09 18:25:19 by joacaeta          #+#    #+#              #
#    Updated: 2022/10/09 18:25:19 by joacaeta         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME := libftprintf.a
CC := gcc
CFLAGS := -Wall -Werror -Wextra -Iinc -Ilibft -g # -fsanitize=address
SRCS := $(wildcard srcs/*.c)
OBJS := $(subst .c,.o,${SRCS})

all: ${NAME}

bonus: ${OBJS}

libftprintf.a: libft/libft.a ${OBJS}
	cp libft/libft.a $@
	ar rcs $@ ${OBJS}

libft/libft.a:
	make -C libft

clean:
	rm -f src/*.o
	make -C libft $@

fclean: clean
	rm -f ${OBJS}
	make -C libft $@

re: fclean all

.PHONY: all bonus fclean clean re libft/libft.a
