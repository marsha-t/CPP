#include "Animal.hpp"

Animal::Animal(void): type("Animal")
{
	std::cout << RED "Animal default constructor called" RESET << std::endl;
}

Animal::Animal(std::string inputType):type(inputType)
{
	std::cout << RED "Animal string constructor called to create " << inputType << RESET << std::endl;
}

Animal::Animal(const Animal &obj): type(obj.type)
{
	std::cout << RED "Animal copy constructor called" RESET << std::endl;
}

Animal	&Animal::operator=(const Animal &obj)
{
	std::cout << RED "Animal copy assignment operator called" RESET << std::endl;
	if (this != &obj)
	{
		type = obj.type;
	}
	return (*this);
}

Animal::~Animal(void)
{
	std::cout << RED "Animal destructor called" RESET << std::endl;
}

std::string	Animal::getType(void) const
{
	return (RED + type + RESET);
}

void	Animal::makeSound(void) const
{
	std::cout << RED "Generic animal sound" RESET << std::endl;
}
