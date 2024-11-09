#include "DiamondTrap.hpp"
#include <iostream>

DiamondTrap::DiamondTrap(void): ClapTrap("Untitled_clap_name", 100, 50, 30), ScavTrap(), FragTrap(), _name("Untitled")
{
	std::cout << "DiamondTrap default constructor called for " << this->_name << std::endl;
}

DiamondTrap::DiamondTrap(std::string name): ClapTrap(name + "_clap_name", 100, 50, 30), ScavTrap(), FragTrap(), _name(name)
{
	std::cout << "DiamondTrap string constructor called for " << this->_name << std::endl;
}

DiamondTrap::DiamondTrap(const DiamondTrap &obj): ClapTrap(obj._name + "_clap_name", 100, 50, 30), ScavTrap(), FragTrap(),_name(obj._name)
{
	std::cout << "DiamondTrap copy constructor called for " << this->_name << std::endl;
}

DiamondTrap	&DiamondTrap::operator=(const DiamondTrap &obj)
{
	std::cout << "DiamondTrap copy assignment operator called" << std::endl;
	if (this != &obj)
	{
		_name = obj._name;
		_hit_pts = obj._hit_pts;
		_energy_pts = obj._energy_pts;
		_attack_damage = obj._attack_damage;
	}
	return (*this);
}

DiamondTrap::~DiamondTrap(void)
{
	std::cout << "DiamondTrap destructor called for " << this->_name << std::endl;
}

void	DiamondTrap::attack(const std::string &target)
{
	ScavTrap::attack(target);
	return ;
}

void	DiamondTrap::whoAmI(void)
{
	std::cout << "I am " << this->_name << " and also " << ClapTrap::_name << std::endl;
	return ;
}