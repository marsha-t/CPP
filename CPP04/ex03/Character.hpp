#ifndef CHARACTER_HPP
#define CHARACTER_HPP

#include "Ex03.hpp"

class Character: public ICharacter
{
	private:
		AMateria *_slots[4];
		std::string	_name;
	public:
		// Constructor
		Character(void);
		Character(std::string name);
		Character(const Character &obj);
		
		// Destructor
		~Character(void);
		
		// Operator
		Character	&operator=(const Character &obj);

		// Getter & Setter
		std::string const &getName(void) const;
		
		// Other functions
		void	equip(AMateria *m);
		void	unequip(int idx);
		void	use(int idx, ICharacter &target);

		// Printing functions
		void	printMateria(void) const;
};

#endif