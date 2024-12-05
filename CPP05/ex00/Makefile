NAME = ex00

FILES = main.cpp Bureaucrat.cpp
CXXFLAGS = -Wall -Wextra -Werror -std=c++98

all: $(NAME)

$(NAME): $(FILES) Bureaucrat.hpp
	c++ $(FILES) $(CXXFLAGS) -o $(NAME)

clean:
	rm -rf $(NAME)

fclean: clean

re: fclean all

.PHONY: all clean fclean re