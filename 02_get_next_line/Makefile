NAME = libftget_next_line.a

CC = cc

FLAGS = -Wall -Wextra -Werror

SOURCE = ./src/get_next_line.c ./src/get_next_line_utils.c

BONUS_SOURCE = ./src/get_next_line_bonus.c ./src/get_next_line_utils_bonus.c

OBJECTS = $(SOURCE:%.c=%.o)

BONUS_OBJECTS = $(BONUS_SOURCE:%.c=%.o)

all: $(if $(wildcard ./src/get_next_line_bonus.o), , $(NAME))

$(NAME): $(OBJECTS)

bonus: $(if $(wildcard ./src/get_next_line.o), fclean $(BONUS_OBJECTS), $(BONUS_OBJECTS))

%.o: %.c
	$(CC) $(FLAGS) -c $< -I ./header -o $@
	ar -rsc $(NAME) $@

clean:
	rm -f $(OBJECTS) $(BONUS_OBJECTS)

fclean: clean
	rm -f $(NAME)

re: fclean
	make all

.PHONY: all clean fclean re