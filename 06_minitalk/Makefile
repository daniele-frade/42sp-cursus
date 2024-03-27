# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: dfrade <dfrade@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/11/14 15:27:27 by dfrade            #+#    #+#              #
#    Updated: 2023/11/15 17:17:37 by dfrade           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = minitalk

NAME_CLIENT = client

NAME_SERVER = server

NAME_CLIENT_BONUS = client_bonus

NAME_SERVER_BONUS = server_bonus

CC = cc

FLAGS = -Wall -Werror -Wextra -g

INCLUDE = -I headers

SRC_PATH = ./src/

FT_PRINTF_PATH = ./printf/

SRC_CLIENT =	$(addprefix $(FT_PRINTF_PATH), ft_printf.c ft_printf_utils.c) \
				$(addprefix $(SRC_PATH), client.c utils.c)

SRC_SERVER =	$(addprefix $(FT_PRINTF_PATH), ft_printf.c ft_printf_utils.c) \
				$(addprefix $(SRC_PATH), server.c utils.c)

SRC_CLIENT_BONUS =	$(addprefix $(FT_PRINTF_PATH), ft_printf.c ft_printf_utils.c) \
					$(addprefix $(SRC_PATH), client_bonus.c utils.c)

SRC_SERVER_BONUS =	$(addprefix $(FT_PRINTF_PATH), ft_printf.c ft_printf_utils.c) \
					$(addprefix $(SRC_PATH), server_bonus.c utils.c)

OBJECTS_CLIENT = $(SRC_CLIENT:%.c=%.o)

OBJECTS_SERVER = $(SRC_SERVER:%.c=%.o)

OBJECTS_CLIENT_BONUS = $(SRC_CLIENT_BONUS:%.c=%.o)

OBJECTS_SERVER_BONUS = $(SRC_SERVER_BONUS:%.c=%.o)

all: $(NAME)

%.o: %.c
	$(CC) $(FLAGS) -c $< $(INCLUDE) -o $@

$(NAME_CLIENT): $(OBJECTS_CLIENT)
	$(CC) $(FLAGS) $(SRC_CLIENT) $(INCLUDE) -o $(NAME_CLIENT)

$(NAME_SERVER): $(OBJECTS_SERVER)
	$(CC) $(FLAGS) $(SRC_SERVER) $(INCLUDE) -o $(NAME_SERVER)

$(NAME): $(NAME_CLIENT) $(NAME_SERVER)

$(NAME_CLIENT_BONUS): $(OBJECTS_CLIENT_BONUS)
	$(CC) $(FLAGS) $(SRC_CLIENT_BONUS) $(INCLUDE) -o $(NAME_CLIENT_BONUS)

$(NAME_SERVER_BONUS): $(OBJECTS_SERVER_BONUS)
	$(CC) $(FLAGS) $(SRC_SERVER_BONUS) $(INCLUDE) -o $(NAME_SERVER_BONUS)

bonus: $(NAME_CLIENT_BONUS) $(NAME_SERVER_BONUS)

clean:
	rm -f $(OBJECTS_CLIENT) $(OBJECTS_SERVER) $(OBJECTS_CLIENT_BONUS) $(OBJECTS_SERVER_BONUS)

fclean: clean
	rm -f $(NAME_CLIENT) $(NAME_SERVER) $(NAME_CLIENT_BONUS) $(NAME_SERVER_BONUS)

re: fclean all

.PHONY: all clean fclean re bonus