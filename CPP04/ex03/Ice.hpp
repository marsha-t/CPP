#ifndef ICE_HPP
#define ICE_HPP

#include "Ex03.hpp"

class Ice: public AMateria
{
	public:
		// Constructor
		Ice(void);
		Ice(const Ice &obj);

		// Destructor
		~Ice(void);

		// Operator
		Ice &operator=(const Ice &obj);

		// Other functions
		AMateria *clone(void) const;
		void	use(ICharacter &target);
		void	dropToFloor(void);
};

#endif