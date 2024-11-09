#ifndef DIAMONDTRAP_HPP
#define DIAMONDTRAP_HPP

#include "ScavTrap.hpp"
#include "FragTrap.hpp"
#include <string>

class DiamondTrap: public ScavTrap, public FragTrap
{
	public:
		// OCN
		DiamondTrap(void);
		DiamondTrap(std::string name);
		DiamondTrap(const FragTrap &obj);
		DiamondTrap	&operator=(const DiamondTrap &obj);
		~DiamondTrap(void);
		
		// Other functions
		void	whoAmI(void);
	private: 
		std::string		_name;
		std::string		_ctName;
};

#endif
