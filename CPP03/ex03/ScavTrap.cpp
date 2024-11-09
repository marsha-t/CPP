#include "ScavTrap.hpp"
#include <iostream>

ScavTrap::ScavTrap(void): ClapTrap("untitled", 100, 50, 20), _isGateKeeper(false)
{
	std::cout << "ScavTrap default constructor called for " << this->_name << std::endl;
}

ScavTrap::ScavTrap(std::string name): ClapTrap(name, 100, 50, 20), _isGateKeeper(false)
{
	std::cout << "ScavTrap string constructor called for " << this->_name << std::endl;
}

ScavTrap::ScavTrap(const ScavTrap &obj): ClapTrap(obj), _isGateKeeper(obj._isGateKeeper)
{
	std::cout << "ScavTrap copy constructor called for " << this->_name << std::endl;
}

ScavTrap	&ScavTrap::operator=(const ScavTrap &obj)
{
	std::cout << "ScavTrap copy assignment operator called" << std::endl;
	if (this != &obj)
	{
		_name = obj._name;
		_hit_pts = obj._hit_pts;
		_energy_pts = obj._energy_pts;
		_attack_damage = obj._attack_damage;
		_isGateKeeper = obj._isGateKeeper;
	}
	return (*this);
}

ScavTrap::~ScavTrap(void)
{
	std::cout << "ScavTrap destructor called for " << this->_name << std::endl;
}

void	ScavTrap::attack(const std::string &target)
{
	if (this->_hit_pts == 0)
		std::cout << "ScavTrap " << this->_name << " is already dead and cannot attack" << std::endl;
	else if (this->_energy_pts == 0)
		std::cout << "ScavTrap " << this->_name << " has no energy to attack" << std::endl;
	else
	{
		std::cout << "ScavTrap " << this->_name << " attacks " + target + ", causing " << this->_attack_damage << " points of damage!" << std::endl;
		--this->_energy_pts;
	}
	return ;
}

void	ScavTrap::guardGate(void)
{
	if (this->_hit_pts == 0)
		std::cout << "ScavTrap " << this->_name << " is already dead and cannot guard gate" << std::endl;
	else if (this->_isGateKeeper == false)
	{
		this->_isGateKeeper = true;
		std::cout << "ScavTrap " << this->_name << " is in Gate Keeper mode" << std::endl;
	}
	else
		std::cout << "ScavTrap " << this->_name << " is already in Gate Keeper mode" << std::endl;
	return ;
}
