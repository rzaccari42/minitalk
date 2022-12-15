SRCS = server.c client.c
OBJS = $(SRCS:.c=.o)

CC = gcc
CFLAGS = -Wall -Wextra -Werror

.PHONY: all server client clean fclean re

all: server client

server: libft server.o
	$(CC) server.o -o server libft/libft.a

client: libft client.o
	$(CC) client.o -o client libft/libft.a

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

libft:
	make -C libft

clean:
	rm -rf $(OBJS)
	make -C libft clean

fclean: clean
	rm -rf server client libft/libft.a

re: fclean all
