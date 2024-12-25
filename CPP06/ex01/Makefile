NAME = ex01

SRC = main.cpp Serializer.cpp 
OBJ = $(SRC:.cpp=.o)
CXXFLAGS = -Wall -Wextra -Werror -std=c++98

all: $(NAME)

$(NAME): $(OBJ)
	c++ $(OBJ) $(CXXFLAGS) -o $(NAME)

%.o: %.cpp Ex01.hpp Serializer.hpp 
	c++ $(CXXFLAGS) -c $< -o $@

clean:
	rm -rf $(OBJ)

fclean: clean
	rm -rf $(NAME)
	rm -rf *_shrubbery

re: fclean all

.PHONY: all clean fclean re
