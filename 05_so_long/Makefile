# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: dfrade <dfrade@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/11/08 10:51:46 by dfrade            #+#    #+#              #
#    Updated: 2023/11/11 11:52:59 by dfrade           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = so_long

CC = cc

FLAGS = -Wall -Werror -Wextra -g

INCLUDE = -I headers

MLX_FLAGS = -lmlx -lX11 -lXext

SRC_PATH = ./src/

SRC =	$(addprefix $(SRC_PATH)libs/gnl/, get_next_line.c get_next_line_utils.c) \
		$(addprefix $(SRC_PATH)libs/printf/, ft_printf.c ft_printf_utils.c) \
		$(addprefix $(SRC_PATH), main.c read_and_create_map.c render_map.c utils_and_erros.c validate_map_1.c validate_map_2.c validate_map_3.c)

OBJECTS = $(SRC:%.c=%.o)

all: $(NAME)

%.o: %.c
	$(CC) $(FLAGS) -c $< $(INCLUDE) -o $@

$(NAME): $(OBJECTS)
	$(CC) $(FLAGS) $(SRC) $(INCLUDE) $(MLX_FLAGS) -o $(NAME)

clean:
	rm -f $(OBJECTS)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re