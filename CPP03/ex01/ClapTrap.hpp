#ifndef CLAPTRAP_HPP
#define CLAPTRAP_HPP

#include <string>

class ClapTrap
{
	protected:
		std::string		_name;
		unsigned int	_hit_pts;
		unsigned int	_energy_pts;
		unsigned int	_attack_damage;
	public:
		// OCN
		ClapTrap(void);
		ClapTrap(std::string name);
		ClapTrap(std::string name, unsigned int hp, unsigned int ep, unsigned int ad);
		ClapTrap(const ClapTrap &obj);
		ClapTrap	&operator=(const ClapTrap &obj);
		~ClapTrap(void);
		
		// Other functions
		 void	attack(const std::string &target);
		void	takeDamage(unsigned int amount);
		void	beRepaired(unsigned int amount);
};

#endif
