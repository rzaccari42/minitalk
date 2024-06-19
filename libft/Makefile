# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: razaccar <razaccar@student.42lausanne.c    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/05/27 23:20:39 by razaccar          #+#    #+#              #
#    Updated: 2024/05/28 02:00:58 by razaccar         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a

SRC_UTILS = $(wildcard src/utils/*.c)
SRC_PRINTF = $(wildcard src/ft_printf/*.c)
SRC_GNL = $(wildcard src/get_next_line/*.c)

SRC = $(SRC_UTILS) $(SRC_PRINTF) $(SRC_GNL)

OBJ = $(SRC:.c=.o)

CC = gcc
CFLAGS = -Wall -Wextra -Werror -I include

AR = ar rc
RM = rm -f

green := \033[0;32m

all: $(NAME)

$(NAME): $(OBJ)
	$(AR) $(NAME) $(OBJ)
	ranlib $(NAME)
	@echo "$(green)$(NAME) created."

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	$(RM) $(OBJ)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re