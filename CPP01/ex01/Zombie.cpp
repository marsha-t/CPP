#include "Zombie.hpp"
#include <iostream>

Zombie::Zombie(void)
{
	std::cout << "A zombie has been created" << std::endl;
	return ;
}

Zombie::~Zombie(void)
{
	std::cout << this->_name << " has been destroyed" << std::endl;
	return ;
}

void	Zombie::announce(void)
{
	std::cout << this->_name << ": BraiiiiiiinnnzzzZ..." << std::endl;
	return ;
}

void	Zombie::setName(std::string name)
{
	this->_name = name;
	return ;
}
