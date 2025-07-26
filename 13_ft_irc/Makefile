# Program name
NAME := ircserv

# Directories
SRC_DIR := source
OBJ_DIR := objects
HDR_DIR := header

# Compiler settings
CC := c++
CFLAGS := -Wall -Wextra -Werror -std=c++98 $(addprefix -I, $(shell find $(HDR_DIR) -type d))

# Automatically find all .cpp files in the source directory
SRC := $(shell find $(SRC_DIR) -type f -name "*.cpp")
OBJ := $(patsubst $(SRC_DIR)/%.cpp, $(OBJ_DIR)/%.o, $(SRC))

# Default target
all: $(NAME)

# Link the final executable
$(NAME): $(OBJ)
	@echo "✅"
	@$(CC) $(OBJ) -o $@

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.cpp
	@mkdir -p $(dir $@)
	@echo -n "."
	@$(CC) $(CFLAGS) -c $< -o $@

# Run Valgrind
val: all
	@valgrind --leak-check=full --show-leak-kinds=all --track-fds=yes --track-origins=yes ./$(NAME) 6667 123456 || echo ""

# Cleanup object files
clean:
	@rm -rf $(OBJ_DIR)

# Full cleanup including the executable
fclean: clean
	@rm -f $(NAME)

# Recompile everything
re: fclean all

.PHONY: all clean fclean re val

