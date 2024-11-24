#include "Dog.hpp"

Dog::Dog(void): AAnimal("Dog"), dogBrain(new Brain())
{
	std::cout << GREEN "Dog default constructor called" RESET << std::endl;
}

Dog::Dog(const Dog &obj): AAnimal(obj.type), dogBrain(new Brain())
{
	std::cout << GREEN "Dog copy constructor called" RESET << std::endl;
}

Dog	&Dog::operator=(const Dog &obj)
{
	std::cout << GREEN "Dog copy assignment operator called" RESET << std::endl;
	if (this != &obj)
	{
		type = obj.type;
		delete dogBrain;
		dogBrain = new Brain();	
	}
	return (*this);
}

Dog::~Dog(void)
{
	std::cout << GREEN "Dog destructor called" RESET << std::endl;
	delete dogBrain;
}

std::string	Dog::getType(void) const
{
	return (GREEN + type + RESET);
}

void	Dog::printBrainAddress(void) const
{
	std::cout << GREEN "Brain address: " << dogBrain << RESET << std::endl;
}

void	Dog::makeSound(void) const
{
	std::cout << GREEN "BARK" RESET << std::endl;
}
