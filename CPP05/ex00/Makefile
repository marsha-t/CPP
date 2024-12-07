NAME = ex00

FILES = main.cpp Bureaucrat.cpp
CXXFLAGS = -Wall -Wextra -Werror -std=c++98

all: $(NAME)

$(NAME): $(FILES) Bureaucrat.hpp
	c++ $(FILES) $(CXXFLAGS) -o $(NAME)

clean:

fclean: 
	rm -rf $(NAME)

re: fclean all

.PHONY: all clean fclean re