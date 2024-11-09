#ifndef FRAGTRAP_HPP
#define FRAGTRAP_HPP

#include "ClapTrap.hpp"
#include <string>

class FragTrap: public virtual ClapTrap
{
	public:
		// OCN
		FragTrap(void);
		FragTrap(std::string name);
		FragTrap(const FragTrap &obj);
		FragTrap	&operator=(const FragTrap &obj);
		~FragTrap(void);
		
		// Other functions
		void	highFivesGuys(void);
};

#endif
