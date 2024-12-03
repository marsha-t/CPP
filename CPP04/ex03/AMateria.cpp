#include "AMateria.hpp"
#include "Character.hpp"

AMateria* AMateria::_floor[2] = { NULL };

AMateria::AMateria(std::string const &type): _type(type)
{
	debugMsg(RED "AMateria string constructor called" RESET);
	// std::cout << RED "AMateria string constructor called" RESET << std::endl;
}

AMateria::~AMateria(void)
{
	debugMsg(RED "AMateria destructor called" RESET);
	// std::cout << RED "AMateria destructor called" RESET << std::endl;
}

std::string const &AMateria::getType(void) const
{
	return (_type);
}

std::string const &AMateria::getCharacterName(void) const
{
	return (_character->getName());
}

// std::string const &AMateria::getSourceNameName(void) const
// {
// 	return (_source->getName());
// }

void	AMateria::setCharacter(Character *character)
{
	_character = character;
}

void	AMateria::use(ICharacter &target)
{
	std::cout << RED BOLD "* does something to " << target.getName() << " *" RESET << std::endl;
}

void	AMateria::dropToFloor(void)
{
	_character = NULL;
	for (int i = 0; i < MAXFLOORSIZE; i++)
	{
		if (_floor[i] == NULL)
		{
			_floor[i] = this;
			return ;
		}
	}
	warningMsg(RED "Floor is too full" RESET);
	delete this;
}

void AMateria::cleanFloor(void)
{
	for (int i = 0; i < MAXFLOORSIZE; i++)
	{
		if (_floor[i] != NULL)
		{
			delete _floor[i];
			_floor[i] = NULL;
		}
	}
	successMsg(RED "Floor is empty" RESET);
}