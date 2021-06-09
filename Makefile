# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: yarroubi <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/06/09 09:32:37 by yarroubi          #+#    #+#              #
#    Updated: 2021/06/09 09:44:39 by yarroubi         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #


AUTHOR = younes

CC = gcc
CFLAGS = -Wall -Werror -Wextra

SERVER = server
CLIENT = client
NAME = $(SERVER) $(CLIENT)

PATH = 

CC = gcc
CFLAGS = -Wall -Wextra -Werror

SERVER_OBJ = $(SERVER_SRC:.c=.o)
CLIENT_OBJ = $(CLIENT_SRC:.c=.o)

OBJ = $(SERVER_OBJ) $(CLIENT_OBJ)


all: $(NAME)

$(SERVER): $(SERVER_OBJ)
	@$(CC) -o $@ $^ $(CFLAGS)

$(CLIENT): $(CLIENT_OBJ)
	@$(CC) -o $@ $^ $(CFLAGS)

%.o: %.c
	@$(CC) -o $@ -c $< $(CFLAGS)

clean:
	@rm -rf $(OBJ)

fclean: clean
	@rm -rf $(NAME)

re: fclean all
