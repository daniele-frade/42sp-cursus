NAME = libftprintf.a

CC = cc

FLAGS = -Wall -Wextra -Werror

SOURCE = ./src/ft_printf.c ./src/ft_printf_utils.c

BONUS_SOURCE = ./src/ft_printf_bonus.c ./src/ft_printf_utils_bonus.c

OBJECTS = $(SOURCE:%.c=%.o)

BONUS_OBJECTS = $(BONUS_SOURCE:%.c=%.o)

all: $(if $(wildcard ./src/ft_printf_bonus.o), , $(NAME))

$(NAME): $(OBJECTS)

bonus: $(if $(wildcard ./src/ft_printf.o), fclean $(BONUS_OBJECTS), $(BONUS_OBJECTS))

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