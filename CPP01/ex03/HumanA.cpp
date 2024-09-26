#include "HumanA.hpp"
#include "Weapon.hpp"
#include <iostream>
#include <string>

HumanA::HumanA(std::string name, Weapon &weapon): _name(name), _weapon(weapon)
{
	std::cout << "HumanA (" << _name << ") has been constructed" << std::endl;
	return ;
}

HumanA::~HumanA(void)
{
	std::cout << "HumanA (" << _name << ") has been destroyed" << std::endl;
	return ;
}

void	HumanA::attack(void)
{
	std::cout << _name << " attacks with their " << _weapon.getType() << std::endl;
	return ;
}