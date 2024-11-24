#include "WrongAnimal.hpp"

WrongAnimal::WrongAnimal(void): type("WrongAnimal")
{
	std::cout << RED STRIKE "WrongAnimal default constructor called" RESET << std::endl;
}

WrongAnimal::WrongAnimal(std::string inputType): type(inputType)
{
	std::cout << RED STRIKE "WrongAnimal string constructor called" RESET << std::endl;
}

WrongAnimal::WrongAnimal(const WrongAnimal &obj): type(obj.type)
{
	std::cout << RED STRIKE "WrongAnimal copy constructor called" RESET << std::endl;
}

WrongAnimal	&WrongAnimal::operator=(const WrongAnimal &obj)
{
	std::cout << RED STRIKE "WrongAnimal copy assignment operator" RESET << std::endl;
	if (this != &obj)
	{
		type = obj.type;
	}
	return (*this);
}

WrongAnimal::~WrongAnimal(void)
{
	std::cout << RED STRIKE "WrongAnimal destructor called" RESET << std::endl;
}

std::string	WrongAnimal::getType(void) const
{
	return (RED STRIKE + type + RESET);
}

void	WrongAnimal::makeSound(void) const
{
	std::cout << RED STRIKE "Generic wrong animal noise" RESET << std::endl;
}
