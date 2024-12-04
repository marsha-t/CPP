#include "Cat.hpp"

Cat::Cat(void): Animal("Cat"), catBrain(new Brain())
{
	std::cout << YELLOW "Cat default constructor called" RESET << std::endl;
}

Cat::Cat(const Cat &obj): Animal(obj.type), catBrain(new Brain())
{
	std::cout << YELLOW "Cat copy constructor called" RESET << std::endl;
	for (unsigned int i = 0; i <= obj.catBrain->getNextIdeaIndex(); i++)
	{
		setIdea(obj.getIdea(i));
	}
}

Cat	&Cat::operator=(const Cat &obj)
{
	std::cout << YELLOW "Cat copy assignment operator called" RESET << std::endl;
	if (this != &obj)
	{
		type = obj.type;
		std:: cout << YELLOW "Delete catBrain at address " << catBrain << RESET << std::endl;
		delete catBrain;
		catBrain = NULL;
		std:: cout << YELLOW "Confirm deletion of catBrain i.e., it points to " << catBrain << RESET << std::endl;
		catBrain = new Brain();	
		if (obj.catBrain->getNextIdeaIndex() > 0)
		{
			for (unsigned int i = 0; i <= obj.catBrain->getNextIdeaIndex(); i++)
			{
				setIdea(obj.getIdea(i));
			}
		}
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


void	Cat::printBrain(void) const
{
	if (catBrain->getNextIdeaIndex() == 0)
		std::cout << YELLOW "Empty brain" RESET << std::endl;
	for (unsigned int i = 0; i <= catBrain->getNextIdeaIndex(); i++)
	{
		std::cout << YELLOW << catBrain->getIdea(i) << RESET << std::endl;
	}
}

void	Cat::setIdea(std::string idea)
{
	catBrain->setIdea(idea);
}

std::string	Cat::getIdea(unsigned int index) const
{
	return (catBrain->getIdea(index));
}

void	Cat::makeSound(void) const
{
	std::cout << YELLOW "MEOW" RESET << std::endl;
}