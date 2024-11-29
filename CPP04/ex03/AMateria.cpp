#include "AMateria.hpp"

AMateria::AMateria(std::string const &type): _type(type)
{
	std::cout << "AMateria string constructor called" << std::endl;
}

AMateria::~AMateria(void)
{

}

std::string const &AMateria::getType(void) const
{
	return (_type);
}


// AMateria *AMateria::clone(void) const
// {
// 	std::cout << "AMateria clone function called" << std::endl;
// 	return &(AMateria("Null"));
// }

// void	AMateria::use(ICharacter &target)
// {
// 	std::cout << ""
// }