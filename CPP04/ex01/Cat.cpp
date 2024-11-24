#include "Cat.hpp"

Cat::Cat(void): Animal("Cat"), catBrain(new Brain())
{
	std::cout << YELLOW "Cat default constructor called" RESET << std::endl;
}

Cat::Cat(const Cat &obj): Animal(obj.type), catBrain(new Brain())
{
	std::cout << YELLOW "Cat copy constructor called" RESET << std::endl;
}

Cat	&Cat::operator=(const Cat &obj)
{
	std::cout << YELLOW "Cat copy assignment operator called" RESET << std::endl;
	if (this != &obj)
	{
		type = obj.type;
		delete catBrain;
		catBrain = new Brain();
	}
	return (*this);
}

Cat::~Cat(void)
{
	std::cout << YELLOW "Cat destructor called" RESET << std::endl;
	delete catBrain;
}

std::string	Cat::getType(void) const
{
	return (YELLOW + type + RESET);
}

void	Cat::printBrainAddress(void) const
{
	std::cout << YELLOW "Brain address: " << catBrain << RESET << std::endl;
}

void	Cat::makeSound(void) const
{
	std::cout << YELLOW "MEOW" RESET << std::endl;
}