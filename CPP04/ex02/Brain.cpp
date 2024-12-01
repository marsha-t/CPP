#include "Brain.hpp"

Brain::Brain(void): _nextIdeaIndex(0)
{
	std::cout << BLUE "Brain default constructor called" RESET << std::endl;
}

Brain::Brain(const Brain &obj): _nextIdeaIndex(obj._nextIdeaIndex)
{
	std::cout << BLUE "Brain copy constructor called" RESET << std::endl;
	for (unsigned int i = 0; i <= obj._nextIdeaIndex; i++)
	{
		_ideas[i] = obj._ideas[i];
	}
}

Brain::~Brain(void)
{
	std::cout << BLUE "Brain destructor called" RESET << std::endl;
}

Brain &Brain::operator=(const Brain &obj)
{
	std::cout << BLUE "Brain destructor called" RESET << std::endl;
	if (this != &obj)
	{
		_nextIdeaIndex = obj._nextIdeaIndex;
		for (unsigned int i = 0; i <= obj._nextIdeaIndex ; i++)
		{
			_ideas[i] = obj._ideas[i];
		}
	}
	return (*this);
}

unsigned int	Brain::getNextIdeaIndex(void) const
{
	return (_nextIdeaIndex);
}

void	Brain::setNextIdeaIndex(unsigned int newIndex)
{
	_nextIdeaIndex = newIndex;
}

std::string	Brain::getIdea(unsigned int index) const
{
	return (_ideas[index]);
}

void	Brain::setIdea(std::string idea)
{
	_ideas[_nextIdeaIndex++] = idea;
	if (_nextIdeaIndex == 100)
		_nextIdeaIndex = 0;
}
