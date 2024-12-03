#ifndef CURE_HPP
#define CURE_HPP

#include "Ex03.hpp"

class Cure: public AMateria
{
	public:
		// Constructor
		Cure(void);
		Cure(const Cure &obj);

		// Destructor
		~Cure(void);

		// Operator
		Cure &operator=(const Cure &obj);

		// Other functions
		AMateria *clone(void) const;
		void use(ICharacter &target);
		void	dropToFloor(void);

};

#endif