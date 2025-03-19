NAME = ex01

SRC = main.cpp Span.cpp
OBJ = $(SRC:.cpp=.o)
CXXFLAGS = -Wall -Wextra -Werror -std=c++98

all: $(NAME)

$(NAME): $(OBJ)
	c++ $(OBJ) $(CXXFLAGS) -o $(NAME)

%.o: %.cpp Span.hpp
	c++ $(CXXFLAGS) -c $< -o $@

clean:
	rm -rf $(OBJ)

fclean: clean
	rm -rf $(NAME)

re: fclean all

.PHONY: all clean fclean re