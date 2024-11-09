#include "FragTrap.hpp"
#include <iostream>

FragTrap::FragTrap(void): ClapTrap("Untitled", 100, 100, 30)
{
	std::cout << "FragTrap default constructor called for " << this->_name << std::endl;
}

FragTrap::FragTrap(std::string name): ClapTrap(name, 100, 100, 30)
{
	std::cout << "FragTrap string constructor called for " << this->_name << std::endl;
}

FragTrap::FragTrap(const FragTrap &obj): ClapTrap(obj)
{
	std::cout << "FragTrap copy constructor called for " << this->_name << std::endl;
}

FragTrap	&FragTrap::operator=(const FragTrap &obj)
{
	std::cout << "FragTrap copy assignment operator called" << std::endl;
	if (this != &obj)
	{
		_name = obj._name;
		_hit_pts = obj._hit_pts;
		_energy_pts = obj._energy_pts;
		_attack_damage = obj._attack_damage;
	}
	return (*this);
}

FragTrap::~FragTrap(void)
{
	std::cout << "FragTrap destructor called for " << this->_name << std::endl;
}

void	FragTrap::highFivesGuys(void)
{
	if (this->_hit_pts == 0)
		std::cout << "FragTrap " << this->_name << " is already dead and cannot high five" << std::endl;
	else
		std::cout << "FragTrap " << this->_name << " high fives everyone who exists" << std::endl;
	return ;
}
