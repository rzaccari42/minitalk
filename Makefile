# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: razaccar <razaccar@student.42lausanne.c    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/06/18 16:08:44 by razaccar          #+#    #+#              #
#    Updated: 2024/06/18 16:08:48 by razaccar         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS = server.c client.c
OBJS = $(SRCS:.c=.o)

CC = gcc
CFLAGS = -Wall -Wextra -Werror

all: server client

server: libft/libft.a server.o
	$(CC) server.o -o server libft/libft.a

client: libft/libft.a client.o
	$(CC) client.o -o client libft/libft.a

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

libft/libft.a:
	make -C libft

clean:
	rm -rf $(OBJS)
	make -C libft clean

fclean: clean
	rm -rf server client libft/libft.a
	make -C libft fclean

re: fclean all

.PHONY: all server client clean fclean re

