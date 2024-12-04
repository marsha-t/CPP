#include "Dog.hpp"

Dog::Dog(void): Animal("Dog"), dogBrain(new Brain())
{
	std::cout << GREEN "Dog default constructor called" RESET << std::endl;
}

Dog::Dog(const Dog &obj): Animal(obj.type), dogBrain(new Brain())
{
	std::cout << GREEN "Dog copy constructor called" RESET << std::endl;
	for (unsigned int i = 0; i <= obj.dogBrain->getNextIdeaIndex(); i++)
	{
		setIdea(obj.getIdea(i));
	}
}

Dog	&Dog::operator=(const Dog &obj)
{
	std::cout << GREEN "Dog copy assignment operator called" RESET << std::endl;
	if (this != &obj)
	{
		type = obj.type;
		std:: cout << GREEN "Delete dogBrain at address " << dogBrain << RESET << std::endl;
		delete dogBrain;
		dogBrain = NULL;
		std:: cout << GREEN "Confirm deletion of dogBrain i.e., it points to " << dogBrain << RESET << std::endl;
		dogBrain = new Brain();	
		if (obj.dogBrain->getNextIdeaIndex() > 0)
		{
			for (unsigned int i = 0; i <= obj.dogBrain->getNextIdeaIndex(); i++)
			{
				setIdea(obj.getIdea(i));
			}
		}
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

void	Dog::printBrain(void) const
{
	if (dogBrain->getNextIdeaIndex() == 0)
		std::cout << GREEN "Empty brain" RESET << std::endl;
	for (unsigned int i = 0; i <= dogBrain->getNextIdeaIndex(); i++)
	{
		std::cout << GREEN << dogBrain->getIdea(i) << RESET << std::endl;
	}
}

void	Dog::setIdea(std::string idea)
{
	dogBrain->setIdea(idea);
}

std::string	Dog::getIdea(unsigned int index) const
{
	return (dogBrain->getIdea(index));
}

void	Dog::makeSound(void) const
{
	std::cout << GREEN "BARK" RESET << std::endl;
}
