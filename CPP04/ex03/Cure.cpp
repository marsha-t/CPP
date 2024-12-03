#include "Cure.hpp"

Cure::Cure(void): AMateria("cure")
{
	debugMsg(YELLOW "Cure default constructor called" RESET);
}

Cure::Cure(const Cure &obj): AMateria(obj.getType())
{
	debugMsg(YELLOW "Cure copy constructor called" RESET);
}

Cure	&Cure::operator=(const Cure &obj)
{
	debugMsg(YELLOW "Cure copy assignment operator called" RESET);
	if (this != &obj)
	{
		std::cout << YELLOW "Assigning Materia to each other doesn't make sense" RESET << std::endl;
	}	
	return (*this);
}

Cure::~Cure(void)
{
	debugMsg(YELLOW "Cure destructor called" RESET);
}

AMateria	*Cure::clone(void) const
{
	debugMsg(YELLOW "Cure clone function called" RESET);
	AMateria	*clonedCure = new Cure(*this);
	return (clonedCure);
}

void	Cure::use(ICharacter &target)
{
	std::cout << YELLOW BOLD "* heals " << target.getName() << "'s wounds *" RESET << std::endl;
}

void	Cure::dropToFloor(void)
{
	_character = NULL;
	for (int i = 0; i < MAXFLOORSIZE; i++)
	{
		if (_floor[i] == NULL)
		{
			_floor[i] = this;
			successMsg(YELLOW "Cure dropped to floor" RESET);
			return ;
		}
	}
	warningMsg(YELLOW "Floor is too full" RESET);
	delete this;
}