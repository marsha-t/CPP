NAME = ex03

FILES = main.cpp AMateria.cpp
CXXFLAGS = -Wall -Wextra -Werror -std=c++98

all: $(NAME)

$(NAME): $(FILES) Ex03.hpp AMateria.hpp
	c++ $(FILES) $(CXXFLAGS) -o $(NAME)

clean:
	rm -rf $(NAME)

fclean: clean

re: fclean all

.PHONY: all clean fclean re