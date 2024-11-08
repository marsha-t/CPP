#ifndef SCAVTRAP_HPP
#define SCAVTRAP_HPP

#include "ClapTrap.hpp"
#include <string>

class ScavTrap: public ClapTrap
{
	private:
		bool	_isGateKeeper;
	public:
		// OCN
		ScavTrap(void);
		ScavTrap(std::string name);
		ScavTrap(const ScavTrap &obj);
		ScavTrap	&operator=(const ScavTrap &obj);
		~ScavTrap(void);
		
		// Other functions
		void	attack(const std::string &target);
		void	guardGate(void);
};

#endif
