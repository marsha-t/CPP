#include "Ice.hpp"

Ice::Ice(void): AMateria("Ice")
{
	std::cout << "Ice default constructor called" << std::endl;
}

Ice::Ice(const Ice &obj): AMateria(obj.getType())
{
	std::cout << "Ice copy constructor called" << std::endl;
}

Ice	&Ice::operator=(const Ice &obj)
{
	std::cout << "Ice copy assignment operator called" << std::endl;
	if (this != &obj)
	{
		// _type = obj.getType();
	}	
	return (*this);
}

Ice::~Ice(void)
{
	std::cout << "Ice destructor called" << std::endl;
}

// AMateria	*Ice::clone(void)
// {
// 	return (&Ice(*this));
// }

// void	Ice::use(ICharacter &target)
// {

// }