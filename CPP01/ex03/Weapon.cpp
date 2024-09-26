#include "Weapon.hpp"
#include <string>

Weapon::Weapon(std::string type): _type(type)
{
	return ;
}

Weapon::~Weapon(void)
{
	return ;
}

const std::string	&Weapon::getType(void)
{
	const std::string	&type = this->_type;
	return (type);
}

void	Weapon::setType(std::string type)
{
	this->_type = type;
	return ;
}