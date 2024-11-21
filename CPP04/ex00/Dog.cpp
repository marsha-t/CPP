#include "Dog.hpp"

Dog::Dog(void): Animal("Dog")
{
	std::cout << GREEN "Dog default constructor called" RESET << std::endl;
}

Dog::Dog(const Dog &obj): Animal(obj.type)
{
	std::cout << GREEN "Dog copy constructor called" RESET << std::endl;
}

Dog	&Dog::operator=(const Dog &obj)
{
	std::cout << GREEN "Dog copy assignment operator called" RESET << std::endl;
	if (this != &obj)
	{
		type = obj.type;
	}
	return (*this);
}

Dog::~Dog(void)
{
	std::cout << GREEN "Dog destructor called" RESET << std::endl;
}

std::string	Dog::getType(void) const
{
	return (GREEN + type + RESET);
}

void	Dog::makeSound(void) const
{
	std::cout << GREEN "BARK" RESET << std::endl;
}
