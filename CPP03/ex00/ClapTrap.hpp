#ifndef CLAPTRAP_HPP
#define CLAPTRAP_HPP

class ClapTrap
{
	private:
		std::string	_name;
		unsigned int	_hit_pts;
		unsigned int	_energy_pts;
		unsigned int	_attack_damage;
	public:
		// OCN
		ClapTrap(void);
		ClapTrap(std::string name);
		ClapTrap(const ClapTrap &obj);
		ClapTrap	&operator=(const ClapTrap &obj);
		~ClapTrap(void);

		// Other functions
		void	attack(const std::string &target);
		void	takeDamage(unsigned int amount);
		void	beRepaired(unsigned int amount);
};

#endif
