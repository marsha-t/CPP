#include "Character.hpp"

Character::Character(void): _name("Untitled")
{
	debugMsg(GREEN "Character constructor called" RESET);
	for (int i = 0; i < 4; i++)
	{
		_slots[i] = NULL;
	}
}

Character::Character(std::string name): _name(name)
{
	debugMsg(GREEN "Character string constructor called" RESET);
	for (int i = 0; i < 4; i++)
	{
		_slots[i] = NULL;
	}
}

Character::Character(const Character &obj): _name(obj.getName())
{
	debugMsg(GREEN "Character copy constructor called" RESET);
	for (int i = 0; i < 4; i++)
	{
		if (obj._slots[i] != NULL)
		{
			_slots[i] = obj._slots[i]->clone();
		}
	}
}

Character::~Character(void)
{
	debugMsg(GREEN "Character destructor called" RESET);
	for (int i = 0; i < 4; i++)
	{
		if (_slots[i] != NULL)
		{
			delete _slots[i];
			_slots[i] = NULL;
		}
	}
}

Character	&Character::operator=(const Character &obj)
{
	debugMsg(GREEN "Character copy assignment operator called" RESET);
	if (this != &obj)
	{
		_name = obj.getName();
		for (int i = 0; i < 4; i++)
		{
			if (obj._slots[i] != NULL)
			{
				_slots[i] = obj._slots[i]->clone();
			}
		}
	}
	return (*this);
}

std::string const &Character::getName(void) const
{
	return (_name);
}

void	Character::equip(AMateria *m)
{
	if (!m)
	{
		warningMsg(GREEN "Can't equip null Materia" RESET);
		return ;
	}
	for (int i = 0; i < 4; i++)
	{
		if (_slots[i] == NULL)
		{
			_slots[i] = m;
			m->setCharacter(this);
			successMsg(GREEN + m->getType() + " equipped"  RESET);
			return ;
		}
	}
	warningMsg(GREEN "Slots are already full" RESET);
	delete m;
}

void	Character::unequip(int idx)
{
	if (idx < 0 || idx > 3)
	{
		warningMsg(GREEN "Can't unequip slot " RESET);
		return ;
	}
	if (_slots[idx] == NULL)
	{
		warningMsg(GREEN "Can't unequip empty slot" RESET);
		return ;
	}
	_slots[idx]->dropToFloor();
	_slots[idx] = NULL;
}

void	Character::use(int idx, ICharacter &target)
{
	if (idx < 0 || idx > 3)
	{
		warningMsg(GREEN "Nonexistent slot" RESET);
		return ;
	}
	if (_slots[idx] == NULL)
	{
		warningMsg(GREEN "Nothing to use" RESET);
	}
	else
	{
		_slots[idx]->use(target);
	}
}

void	Character::printMateria(void) const
{
	for (int i = 0; i < 4; i++)
	{
		if (_slots[i] != NULL)
			std::cout << GREEN << _slots[i]->getType() << RESET << std::endl;
	}
}