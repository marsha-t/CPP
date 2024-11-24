#include "AAnimal.hpp"

AAnimal::AAnimal(void): type("AAnimal")
{
	std::cout << RED "AAnimal default constructor called" RESET << std::endl;
}

AAnimal::AAnimal(std::string inputType):type(inputType)
{
	std::cout << RED "AAnimal string constructor called to create " << inputType << RESET << std::endl;
}

AAnimal::AAnimal(const AAnimal &obj): type(obj.type)
{
	std::cout << RED "AAnimal copy constructor called" RESET << std::endl;
}

AAnimal	&AAnimal::operator=(const AAnimal &obj)
{
	std::cout << RED "AAnimal copy assignment operator called" RESET << std::endl;
	if (this != &obj)
	{
		type = obj.type;
	}
	return (*this);
}

AAnimal::~AAnimal(void)
{
	std::cout << RED "AAnimal destructor called" RESET << std::endl;
}

std::string	AAnimal::getType(void) const
{
	return (RED + type + RESET);
}

void	AAnimal::makeSound(void) const
{
	std::cout << RED "Generic animal sound" RESET << std::endl;
}
