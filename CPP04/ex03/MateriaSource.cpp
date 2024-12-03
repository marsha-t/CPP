#include "MateriaSource.hpp"

MateriaSource::MateriaSource(void): _name("Untitled")
{
	debugMsg(PURPLE "MateriaSource constructor called" RESET);
	for (int i = 0; i < 4; i++)
	{
		_memory[i] = NULL;
	}
}

MateriaSource::MateriaSource(std::string name): _name(name)
{
	debugMsg(PURPLE "MateriaSource string constructor called" RESET);
	for (int i = 0; i < 4; i++)
	{
		_memory[i] = NULL;
	}
}
MateriaSource::MateriaSource(const MateriaSource &obj): _name(obj.getName())
{
	debugMsg(PURPLE "MateriaSource copy constructor called" RESET);
	for (int i = 0; i < 4; i++)
	{
		if (_memory[i] != NULL)
			_memory[i] = obj._memory[i]->clone();
	}
}

MateriaSource::~MateriaSource(void)
{
	debugMsg(PURPLE "MateriaSource destructor called" RESET);
	for (int i = 0; i < 4; i++)
	{
		delete _memory[i];
		_memory[i] = NULL;
	}
}

MateriaSource &MateriaSource::operator=(const MateriaSource &obj)
{
	debugMsg(PURPLE "MateriaSource copy assignment operator called" RESET);
	if (this != &obj)
	{
		for (int i = 0; i < 4; i++)
		{
			if (_memory[i] != NULL)
				_memory[i] = obj._memory[i]->clone();
		}
	}
	return (*this);
}

std::string const &MateriaSource::getName(void) const
{
	return (_name);
}

void	MateriaSource::setName(std::string name)
{
	_name = name;
}

void	MateriaSource::learnMateria(AMateria *newMateria)
{
	for (int i = 0; i < 4; i++)
	{
		if (_memory[i] == NULL)
		{
			_memory[i] = newMateria;
			return ;
		}
	}
	warningMsg(PURPLE "Memory is full" RESET );
	delete newMateria;
}

AMateria	*MateriaSource::createMateria(std::string const &type)
{
	for (int i = 0; i < 4; i++)
	{
		if (_memory[i] != NULL && _memory[i]->getType() == type)
		{
			return (_memory[i]->clone());
		}
	}
	warningMsg(PURPLE "Unknown Materia type" RESET);
	return (NULL);
}