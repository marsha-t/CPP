#ifndef AMATERIA_HPP
#define AMATERIA_HPP

#include "Ex03.hpp"

class Character;
class MateriaSource;

class AMateria
{
	protected:
		std::string const _type;
		Character	*_character;
		MateriaSource	*_source;
		static AMateria	*_floor[2];
	public:
		// Constructors
		AMateria(std::string const &type);

		// Destructors
		virtual ~AMateria(void);
		
		// Getters 
		std::string const &getType(void) const;
		std::string const &getCharacterName(void) const;
	
		// Setters
		void	setCharacter(Character *character);
		
		// Other functions
		virtual AMateria *clone(void) const = 0;
		virtual void use(ICharacter &target);
		virtual void	dropToFloor(void);

		// Static functions
		static void cleanFloor(void);
};

#endif