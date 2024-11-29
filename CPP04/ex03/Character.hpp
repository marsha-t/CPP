#ifndef CHARACTER_HPP
#define CHARACTER_HPP

#include "Ex03.hpp"

class Character: public ICharacter
{
	private:
		AMateria *slots[4];
	public:
		Character(void);
		Character(const Character &obj);
		Character	&operator=(const Character &obj);
		~Character(void);
};

#endif