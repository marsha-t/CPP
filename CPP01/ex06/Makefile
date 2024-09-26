NAME = ex06

FILES = main.cpp Harl.cpp
FLAGS = -Wall -Wextra -Werror -std=c++98

all: $(NAME)

$(NAME):
	c++ $(FILES) $(FLAGS) -o $(NAME)

clean:
	rm -rf $(NAME)

fclean: clean

re: fclean all

.PHONY: all clean fclean re
