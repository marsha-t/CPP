#include "ClapTrap.hpp"
#include <iostream>

ClapTrap::ClapTrap(void): _name("Untitled"), _hit_pts(10), _energy_pts(10), _attack_damage(0)
{
	std::cout << "ClapTrap default constructor called for " << this->_name << std::endl;
}

ClapTrap::ClapTrap(std::string name): _name(name), _hit_pts(10), _energy_pts(10), _attack_damage(0)
{
	std::cout << "ClapTrap string constructor called for " << this->_name << std::endl;
}

ClapTrap::ClapTrap(const ClapTrap &obj): _name(obj._name), _hit_pts(obj._hit_pts), _energy_pts(obj._energy_pts), _attack_damage(obj._attack_damage)

{
	std::cout << "ClapTrap copy constructor called for " << this->_name << std::endl;
}

ClapTrap	&ClapTrap::operator=(const ClapTrap &obj)
{
	std::cout << "ClapTrap copy assignment operator called " << std::endl;
	if (this != &obj)
	{
		_name = obj._name;
		_hit_pts = obj._hit_pts;
		_energy_pts = obj._energy_pts;
		_attack_damage = obj._attack_damage;
	}
	return (*this);
}

ClapTrap::~ClapTrap(void)
{
	std::cout << "ClapTrap destructor called for " << this->_name << std::endl;
}

void	ClapTrap::attack(const std::string &target)
{
	if (this->_hit_pts == 0)
		std::cout << "ClapTrap " << this->_name << " is already dead and cannot attack" << std::endl;
	else if (this->_energy_pts == 0)
		std::cout << "ClapTrap " << this->_name << " has no energy to attack" << std::endl;
	else
	{
		std::cout << "ClapTrap " << this->_name << " attacks " + target + ", causing " << this->_attack_damage << " points of damage!" << std::endl;
		--this->_energy_pts;
	}
	return ;
}

void	ClapTrap::takeDamage(unsigned int amount)
{
	if (this->_hit_pts == 0)
		std::cout << "ClapTrap " << this->_name << " is already dead and cannot take more damage" << std::endl;
	else if (this->_hit_pts <= amount)
	{
		this->_hit_pts = 0;
		std::cout << "ClapTrap " << this->_name << " is dead" << std::endl;
	}
	else
	{
		this->_hit_pts -= amount;
		std::cout << "ClapTrap " << this->_name << " takes " << amount << " damage!" << std::endl;
	}
	return ;
}

void	ClapTrap::beRepaired(unsigned int amount)
{
	if (this->_hit_pts == 0)
	{
		std::cout << "ClapTrap " << this->_name << " is already dead and cannot heal" << std::endl;
		return ;
	}
	this->_hit_pts += amount;
	std::cout << "ClapTrap " << this->_name << " heals by " << amount << " point" << std::endl;
	return ;
}
