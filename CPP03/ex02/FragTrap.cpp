#include "FragTrap.hpp"
#include <iostream>

FragTrap::FragTrap(void): ClapTrap("untitled", 100, 100, 30)
{
	std::cout << "FragTrap default constructor called" << std::endl;
}

FragTrap::FragTrap(std::string name): ClapTrap(name, 100, 100, 30)
{
	std::cout << "FragTrap string constructor called" << std::endl;
}

FragTrap::FragTrap(const FragTrap &obj): ClapTrap(obj)
{
	std::cout << "FragTrap copy constructor called" << std::endl;
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
	std::cout << "FragTrap destructor called" << std::endl;
}

void	FragTrap::attack(const std::string &target)
{
	if (this->_hit_pts == 0)
		std::cout << "FragTrap " << this->_name << " is already dead and cannot attack" << std::endl;
	else if (this->_energy_pts == 0)
		std::cout << "FragTrap " << this->_name << " has no energy to attack" << std::endl;
	else
	{
		std::cout << "FragTrap " << this->_name << " attacks " + target + ", causing " << this->_attack_damage << " points of damage!" << std::endl;
		--this->_energy_pts;
	}
	return ;
}

void	FragTrap::takeDamage(unsigned int amount)
{
	if (this->_hit_pts == 0)
		std::cout << "FragTrap " << this->_name << " is already dead and cannot take more damage" << std::endl;
	else if (this->_hit_pts <= amount)
	{
		this->_hit_pts = 0;
		std::cout << "FragTrap " << this->_name << " is dead" << std::endl;
	}
	else
	{
		this->_hit_pts -= amount;
		std::cout << "FragTrap " << this->_name << " takes " << amount << " damage!" << std::endl;
	}
	return ;
}

void	FragTrap::beRepaired(unsigned int amount)
{
	if (this->_hit_pts == 0)
	{
		std::cout << "FragTrap " << this->_name << " is already dead and cannot heal" << std::endl;
		return ;
	}
	this->_hit_pts += amount;
	std::cout << "FragTrap " << this->_name << " heals by " << amount << " point" << std::endl;
	return ;
}

void	FragTrap::highFivesGuys(void)
{
	if (this->_hit_pts == 0)
		std::cout << "FragTrap " << this->_name << " is already dead and cannot high five" << std::endl;
	else
		std::cout << "FragTrap " << this->_name << " high fives everyone who exists" << std::endl;
	return ;
}