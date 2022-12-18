CLIENT = client
SERVER = server
LIBFT = libft

OPTIONS = -c
CFLAGS = -Wall -Wextra -Werror -Ilibft
LIB = -Llibft -lft

SRCS_CLIENT = client.c
SRCS_SERVER = server.c

OBJS_CLIENT = $(SRCS_CLIENT:.c=.o)
OBJS_SERVER = $(SRCS_SERVER:.c=.o)

CC = gcc
RM = rm -rf

all: $(LIBFT) $(CLIENT) $(SERVER)

$(LIBFT):
	make -C $(@)

%.o: %.c
	$(CC) $(CFLAGS) $(OPTIONS) $(<) -o $(<:.c=.o)

$(CLIENT): $(OBJS_CLIENT)
	$(CC) $(CFLAGS) $(OBJS_CLIENT) -o $(CLIENT) $(LIB)

$(SERVER): $(OBJS_SERVER)
	$(CC) $(CFLAGS) $(OBJS_SERVER) -o $(SERVER) $(LIB)

clean:
	$(RM) -f $(OBJS_CLIENT)
	$(RM) -f $(OBJS_SERVER)
	make -C $(LIBFT) clean

fclean: clean
	$(RM) -f $(CLIENT)
	$(RM) -f $(SERVER)
	make -C $(LIBFT) fclean

re: fclean all

.PHONY: re fclean clean all libft
