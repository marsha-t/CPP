#include "ClapTrap.hpp"
#include <iostream>

ClapTrap::ClapTrap(void): _hit_pts(10), _energy_pts(10), _attack_damage(0)
{
	std::cout << "Default constructor called" << std::endl;
	return ;
}

ClapTrap::ClapTrap(std::string name): _name(name), _hit_pts(10), _energy_pts(10), _attack_damage(0)
{
	std::cout << "String constructor called" << std::endl;
	return ;
}

ClapTrap::ClapTrap(const ClapTrap &obj): _name(obj._name), _hit_pts(obj._hit_pts), _energy_pts(obj._energy_pts), _attack_damage(obj._damage)
{
	std::cout << "Copy constructor called" << std::endl;
	return ;
}

// ClapTrap	&ClapTrap::operator=(const ClapTrap &obj) // WIP
// {
// 
// }

ClapTrap::ClapTrap(void)
{
	std::cout << "Destructor called" << std::endl;
	return ;
}

void	ClapTrap::attack(const std::string &target)
{
	if (this->_energy_pts == 0)
	{
		std::cout << "ClapTrap " << this->_name << " has no energy to attack" << std::endl;
	}
	else
	{
		std::cout << "ClapTrap " << this->_name << " attacks " + target + ", causing " << this->_attack_damage << "points of damage!" << std::endl;
		--this->_energy_pts;
	}
	return ;
}

void	ClapTrap::takeDamage(unsigned int amount)
{
	if (_hit_pts <= amount)
	{
		std::cout << "ClapTrap " << this->_name << " is dead" << std::endl;
	}
	else
	{
		_hit_pts -= amount;
		std::cout << "ClapTrap " << this->_name << " takes" << amount << "damage!" << std::endl;
		
	}
	return ;
}

void	ClapTrap::beRepaired(unsigned int amount);

