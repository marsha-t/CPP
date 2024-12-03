#include "Ice.hpp"

Ice::Ice(void): AMateria("ice")
{
	debugMsg(BLUE "Ice default constructor called" RESET);
}

Ice::Ice(const Ice &obj): AMateria(obj.getType())
{
	debugMsg(BLUE "Ice copy constructor called" RESET);
}

Ice	&Ice::operator=(const Ice &obj)
{
	debugMsg(BLUE "Ice copy assignment operator called" RESET);
	if (this != &obj)
	{
		std::cout << BLUE "Assigning Materia to each other doesn't make sense" RESET << std::endl;
	}	
	return (*this);
}

Ice::~Ice(void)
{
	debugMsg(BLUE "Ice destructor called" RESET);
}

AMateria	*Ice::clone(void) const
{
	debugMsg(BLUE "Ice clone function called" RESET);
	AMateria	*clonedIce = new Ice(*this);
	return (clonedIce);
}

void	Ice::use(ICharacter &target)
{
	std::cout << BLUE BOLD "* shoots an ice bolt at " << target.getName() << " *" RESET << std::endl;
}

void	Ice::dropToFloor(void)
{
	_character = NULL;
	for (int i = 0; i < MAXFLOORSIZE; i++)
	{
		if (_floor[i] == NULL)
		{
			_floor[i] = this;
			successMsg(BLUE "Ice dropped to floor" RESET);
			return ;
		}
	}
	warningMsg(BLUE "Floor is too full" RESET);
	delete this;
}