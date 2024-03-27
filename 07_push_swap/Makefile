NAME = push_swap

CC = cc

FLAGS = -Wall -Werror -Wextra -g

INCLUDE = -I headers

SRC =	./printf/ft_printf.c \
		./printf/ft_printf_utils.c \
		./src/main.c \
		./src/error_handling.c \
		./src/stack_manip.c \
		./src/swap_operations.c \
		./src/push_operations.c \
		./src/rotate_operations.c \
		./src/reverse_rotate_operations.c \
		./src/small_stack_sort.c \
		./src/large_stack_sort.c \
		./src/utils_functions.c

OBJECTS = $(SRC:%.c=%.o)

all: $(NAME)

%.o: %.c
	$(CC) $(FLAGS) -c $< $(INCLUDE) -o $@

$(NAME): $(OBJECTS)
	$(CC) $(FLAGS) $(SRC) $(INCLUDE) -o $(NAME)

clean:
	rm -f $(OBJECTS)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re