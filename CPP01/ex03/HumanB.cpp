#include "HumanB.hpp"
#include "Weapon.hpp"
#include <iostream>
#include <string>

HumanB::HumanB(std::string name): _name(name), _weapon(0)
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
	if (!_weapon)
		std::cout << _name << " fails to attack since he has no weapon" << std::endl;
	else
		std::cout << _name << " attacks with their " << _weapon->getType() << std::endl;
	return ;
}

void	HumanB::setWeapon(Weapon &weapon)
{
	this->_weapon = &weapon;
	return ;
}
