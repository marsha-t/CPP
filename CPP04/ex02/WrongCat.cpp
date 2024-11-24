#include "WrongCat.hpp"

WrongCat::WrongCat(void): WrongAnimal("WrongCat")
{
	std::cout << YELLOW STRIKE "WrongCat default constructor called" RESET << std::endl;
}

WrongCat::WrongCat(const WrongCat &obj): WrongAnimal(obj.type)
{
	std::cout << YELLOW STRIKE "WrongCat copy constructor called" RESET << std::endl;

}

WrongCat	&WrongCat::operator=(const WrongCat &obj)
{
	std::cout << YELLOW STRIKE "WrongCat copy assignment operator called" RESET << std::endl;
	if (this != &obj)
	{
		type = obj.type;
	}
	return (*this);
}

WrongCat::~WrongCat(void)
{
	std::cout << YELLOW STRIKE "WrongCat destructor called" RESET << std::endl;
}

std::string	WrongCat::getType(void) const{
	return (YELLOW STRIKE + type + RESET);
}
