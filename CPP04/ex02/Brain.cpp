#include "Brain.hpp"

Brain::Brain(void)
{
	std::cout << BLUE "Brain default constructor called" RESET << std::endl;
}

Brain::Brain(const Brain &obj):
{
	std::cout << BLUE "Brain copy constructor called" RESET << std::endl;
}
Brain &Brain::operator=(const Brain &obj)
{
	std::cout << BLUE "Brain destructor called" RESET << std::endl;
	if (this != &obj)
	{
		for (int i = 0; i < 100; i++)
		{
			ideas[i] = obj.ideas[i];
		}
	}
	return (*this);
}


Brain::~Brain(void)
{
	std::cout << BLUE "Brain destructor called" RESET << std::endl;
}
