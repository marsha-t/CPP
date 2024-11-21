#include "WrongAnimal.hpp"

WrongAnimal::WrongAnimal(void): type("WrongAnimal")
{
	std::cout << STRIKE "WrongAnimal default constructor called" RESET << std::endl;
}

WrongAnimal::WrongAnimal(const WrongAnimal &obj): type(obj.type)
{
	std::cout << STRIKE "WrongAnimal copy constructor called" RESET << std::endl;
}

WrongAnimal	&WrongAnimal::operator=(const WrongAnimal &obj)
{
	std::cout << STRIKE "WrongAnimal copy assignment operator" RESET << std::endl;
	if (this != &obj)
	{
		type = obj.type;
	}
	return (*this);
}

WrongAnimal::~WrongAnimal(void)
{
	std::cout << STRIKE "WrongAnimal destructor called" RESET << std::endl;
}

void	WrongAnimal::makeSound(void)
{
	std::cout << STRIKE "Generic wrong animal noise" RESET << std::endl;
}
