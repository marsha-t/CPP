#include "HumanB.hpp"
#include "Weapon.hpp"
#include <iostream>
#include <string>

HumanB::HumanB(std::string name): _name(name)
{
	std::cout << "HumanB (" << _name << ") has been constructed" << std::endl;
	return ;
}

HumanB::~HumanB(void)
{
	std::cout << "HumanB (" << _name << ") has been destroyed" << std::endl;
	return ;
}

void	HumanB::attack(void)
{
	std::cout << _name << " attacks with their " << _weapon->getType() << std::endl;
	return ;
}

void	HumanB::setWeapon(Weapon &weapon)
{
	this->_weapon = &weapon;
	return ;
}