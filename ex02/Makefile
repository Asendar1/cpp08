SRC = main.cpp
OBJ = main.o

CXX = c++ -Wall -Wextra -Werror -std=c++98
NAME = mutant

all: $(NAME)
$(NAME): $(OBJ)
	$(CXX) $(OBJ) -o $(NAME)

clean:
	rm -f $(OBJ)
fclean: clean
	rm -f $(NAME)
re: fclean all
.PHONY: all clean fclean re
