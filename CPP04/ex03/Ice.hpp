#ifndef ICE_HPP
#define ICE_HPP

#include "Ex03.hpp"
#include "AMateria.hpp"

class Ice: public AMateria
{
	public:
		Ice(void);
		Ice(const Ice &obj);
		Ice &operator=(const Ice &obj);
		~Ice(void);
		Ice clone(const Ice &obj);
};

#endif