NAME = mutated

WFLAGS = -Wall -Werror -Wextra
CPPFLAGS = -std=c++98 -O3 -I ./include/

SRC_DIR = ./src
OBJ_DIR = ./objs
SOURCES = $(wildcard $(SRC_DIR)/*.cpp)
OBJECTS = $(patsubst $(SRC_DIR)/%.cpp,$(OBJ_DIR)/%.o,$(SOURCES))
HEADERS = $(wildcard ./include/*.hpp)

all: $(NAME)

$(NAME): $(OBJECTS)
	c++ $(CPPFLAGS) $(WFLAGS) $(OBJECTS) -o $(NAME)

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.cpp $(HEADERS)
	mkdir -p $(OBJ_DIR)
	c++ $(CPPFLAGS) $(WFLAGS) -c $< -o $@

clean:
	rm -rf $(OBJ_DIR)

fclean: clean
	rm -f $(NAME)

re: fclean all