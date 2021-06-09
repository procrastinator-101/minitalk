# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: yarroubi <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/06/09 09:32:37 by yarroubi          #+#    #+#              #
#    Updated: 2021/06/09 11:59:48 by yarroubi         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

AUTHOR = younes

CC = gcc
CFLAGS = -Wall -Werror -Wextra

SERVER = server
CLIENT = client

NAME = $(SERVER) $(CLIENT)

BONUS_PATH = ft_bonus
MANDATORY_PATH = ft_mandatory

CC = gcc
CFLAGS = -Wall -Wextra -Werror

CLIENT_MANDATORY_SRC = $(MANDATORY_PATH)/ft_atoi_check.c \
					   $(MANDATORY_PATH)/ft_client.c \
					   $(MANDATORY_PATH)/ft_putstr_fd.c \
					   $(MANDATORY_PATH)/ft_transmit_string.c

SERVER_MANDATORY_SRC = $(MANDATORY_PATH)/ft_append_character.c \
					   $(MANDATORY_PATH)/ft_putendl_fd.c \
					   $(MANDATORY_PATH)/ft_putstr_fd.c \
					   $(MANDATORY_PATH)/ft_server.c \
					   $(MANDATORY_PATH)/ft_strlen.c

CLIENT_BONUS_SRC = $(BONUS_PATH)/ft_atoi_check_bonus.c \
				   $(BONUS_PATH)/ft_client_bonus.c \
				   $(BONUS_PATH)/ft_putstr_fd_bonus.c \
				   $(BONUS_PATH)/ft_transmit_string_bonus.c

SERVER_BONUS_SRC = $(BONUS_PATH)/ft_append_character_bonus.c \
				   $(BONUS_PATH)/ft_putendl_fd_bonus.c \
				   $(BONUS_PATH)/ft_putstr_fd_bonus.c \
				   $(BONUS_PATH)/ft_server_bonus.c \
				   $(BONUS_PATH)/ft_strlen_bonus.c


ifndef BONUS
	CLIENT_SRC = $(CLIENT_MANDATORY_SRC)
	SERVER_SRC = $(SERVER_MANDATORY_SRC)
else
	CLIENT_SRC = $(CLIENT_BONUS_SRC)
	SERVER_SRC = $(SERVER_BONUS_SRC)
endif

SERVER_OBJ = $(SERVER_SRC:.c=.o)
CLIENT_OBJ = $(CLIENT_SRC:.c=.o)

OBJ = $(SERVER_OBJ) $(CLIENT_OBJ)

all: $(NAME)

bonus	:
	@$(MAKE) BONUS=1 all

$(SERVER): $(SERVER_OBJ)
	@$(CC) -o $@ $^ $(CFLAGS)

$(CLIENT): $(CLIENT_OBJ)
	@$(CC) -o $@ $^ $(CFLAGS)

%.o: %.c
	@$(CC) -o $@ -c $< $(CFLAGS)

clean:
	@rm -rf $(OBJ)

clean_bonus :
	@$(MAKE) BONUS=1 clean

fclean: clean
	@rm -rf $(NAME)

fclean_bonus :
	@$(MAKE) BONUS=1 fclean

re: fclean all

re_bonus : fclean_bonus bonus
