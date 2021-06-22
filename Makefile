# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: yarroubi <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/06/09 09:32:37 by yarroubi          #+#    #+#              #
#    Updated: 2021/06/22 15:55:08 by yarroubi         ###   ########.fr        #
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
					   $(MANDATORY_PATH)/ft_display_error_msg.c \
					   $(MANDATORY_PATH)/ft_manage_error.c \
					   $(MANDATORY_PATH)/ft_putstr_fd.c \
					   $(MANDATORY_PATH)/ft_send_byte.c

SERVER_MANDATORY_SRC = $(MANDATORY_PATH)/ft_atoi_check.c \
					   $(MANDATORY_PATH)/ft_display_error_msg.c \
					   $(MANDATORY_PATH)/ft_manage_error.c \
					   $(MANDATORY_PATH)/ft_memcpy.c \
					   $(MANDATORY_PATH)/ft_putstr_fd.c \
					   $(MANDATORY_PATH)/ft_send_byte.c \
					   $(MANDATORY_PATH)/ft_server.c \
					   $(MANDATORY_PATH)/ft_text_append_char.c \
					   $(MANDATORY_PATH)/ft_text_create.c \
					   $(MANDATORY_PATH)/ft_text_expand.c \
					   $(MANDATORY_PATH)/ft_text_harddel.c

CLIENT_BONUS_SRC = $(BONUS_PATH)/ft_atoi_check_bonus.c \
				   $(BONUS_PATH)/ft_client_bonus.c \
				   $(BONUS_PATH)/ft_display_error_msg_bonus.c \
				   $(BONUS_PATH)/ft_manage_client_eot.c \
				   $(BONUS_PATH)/ft_manage_error_bonus.c \
				   $(BONUS_PATH)/ft_putstr_fd_bonus.c \
				   $(BONUS_PATH)/ft_send_byte_bonus.c

SERVER_BONUS_SRC = $(BONUS_PATH)/ft_display_error_msg_bonus.c \
				   $(BONUS_PATH)/ft_manage_error_bonus.c \
				   $(BONUS_PATH)/ft_manage_server_eot.c \
				   $(BONUS_PATH)/ft_memcpy_bonus.c \
				   $(BONUS_PATH)/ft_putstr_fd_bonus.c \
				   $(BONUS_PATH)/ft_send_byte_bonus.c \
				   $(BONUS_PATH)/ft_server_bonus.c \
				   $(BONUS_PATH)/ft_text_append_char_bonus.c \
				   $(BONUS_PATH)/ft_text_create_bonus.c \
				   $(BONUS_PATH)/ft_text_expand_bonus.c \
				   $(BONUS_PATH)/ft_text_harddel_bonus.c

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
