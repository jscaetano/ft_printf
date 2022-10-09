# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: joacaeta <joacaeta@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/10/09 17:42:04 by joacaeta          #+#    #+#              #
#    Updated: 2022/10/09 17:42:04 by joacaeta         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = gcc
CFLAGS = -Wall -Wextra -Werror
SO = libft.so

SRCS =	ft_atoi.c \
		ft_bzero.c \
		ft_calloc.c \
		ft_isalnum.c \
		ft_isalpha.c \
		ft_isascii.c \
		ft_isdigit.c \
		ft_isprint.c \
		ft_memcpy.c \
		ft_memchr.c \
		ft_memcmp.c \
		ft_memset.c \
		ft_memmove.c \
		ft_strncmp.c \
		ft_strlcat.c \
		ft_strnstr.c \
		ft_strlcpy.c \
		ft_strrchr.c \
		ft_strchr.c \
		ft_strlen.c \
		ft_strdup.c \
		ft_toupper.c \
		ft_tolower.c \
		\
		ft_substr.c \
		ft_strjoin.c \
		ft_strtrim.c \
		ft_split.c \
		ft_itoa.c \
		ft_strmapi.c \
		ft_putchar_fd.c \
		ft_putstr_fd.c \
		ft_putendl_fd.c \
		ft_putnbr_fd.c \
		ft_striteri.c

BONUS = ft_lstnew.c \
		ft_lstadd_front.c \
		ft_lstsize.c \
		ft_lstlast.c \
		ft_lstadd_back.c \
		ft_lstdelone.c \
		ft_lstclear.c \
		ft_lstiter.c \
		ft_lstmap.c

OBJS = $(SRCS:.c=.o)
OBJS_BONUS = $(BONUS:.c=.o)

.c.o : libft.h
	$(CC) $(CFLAGS) -c $< -o $(<:.c=.o) -I.

libft.a: $(OBJS)
	ar rcs libft.a $(OBJS)

all:	libft.a

bonus: $(OBJS) $(OBJS_BONUS)
	ar rcs libft.a $(OBJS) $(OBJS_BONUS)

clean:
	rm -f $(OBJS) $(OBJS_BONUS)

fclean: clean
	rm -f libft.a

re:		fclean all

.PHONY: clean fclean re all bonus
