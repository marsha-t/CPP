#ifndef AMATERIA_HPP
#define AMATERIA_HPP

#include "Ex03.hpp"

class AMateria
{
	protected:
		std::string const _type;

	public:
		AMateria(std::string const &type);
		virtual ~AMateria(void);
		// ...
		std::string const &getType(void) const;
		
		// virtual AMateria *clone(void) const = 0;
		// virtual void use(ICharacter &target);
};

#endif