NAME = ex01

FILES = main.cpp ClapTrap.cpp ScavTrap.cpp
CPPFLAGS = -Wall -Wextra -Werror -std=c++98

all: $(NAME)

$(NAME): ClapTrap.hpp ScavTrap.hpp
	c++ $(FILES) $(CPPFLAGS) -o $(NAME)

clean:
	rm -rf $(NAME)

fclean: clean

re: fclean all

.PHONY: all clean fclean re
