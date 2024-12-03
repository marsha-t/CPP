#ifndef EX03_HPP
#define EX03_HPP

#include <string>
#include <cstdlib>
#include <iostream>
#include "ICharacter.hpp"
#include "AMateria.hpp"
#include "IMateriaSource.hpp"

# define MAXFLOORSIZE 20
# define RESET "\033[0m"
# define RED "\033[31m"
# define GREEN "\033[32m"
# define YELLOW "\033[33m"
# define BLUE "\033[34m"
# define PURPLE "\033[35m"
# define BOLD "\033[1m"
# define STRIKE "\033[9m"

void	debugMsg(std::string msg);
void	warningMsg(std::string msg);
void	successMsg(std::string msg);


#endif