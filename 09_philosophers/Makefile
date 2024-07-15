NAME	=	philo

SRC		=	0_main \
			1_check_args \
			2_philo_init \
			3_philo_routine_a \
			4_philo_routine_b \
			5_philo_actions_a \
			6_philo_actions_b \
			7_philo_status_a \
			8_philo_status_b

PATH_O	=	objs/
OBJS	=	$(addprefix $(PATH_O), $(addsuffix .o, $(SRC)))

CFLAGS	=	-pthread -Wall -Wextra -Werror

$(PATH_O)%.o: %.c philo.h
	cc -c $(CFLAGS) $< -o $@

all: $(PATH_O) $(NAME) 

$(PATH_O):
	mkdir -p $(PATH_O)

$(NAME): $(OBJS)
	cc $(CFLAGS) $(OBJS) -o $@

clean:
	rm -f $(OBJS) valgs -r $(PATH_O)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re objs
