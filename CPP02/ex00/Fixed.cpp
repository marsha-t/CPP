#include "Fixed.hpp"
#include <iostream>

const int Fixed::_frac = 8;

Fixed::Fixed(void): _value(0)
{
	std::cout << "Default constructor called" << std::endl;
	return ;
}

Fixed::Fixed(const Fixed& obj): _value(obj._value)
{
	std::cout << "Copy constructor called" << std::endl;
	return ;
}

Fixed &Fixed::operator=(const Fixed &obj)
{
	std::cout << "Copy assignment operator called" << std::endl;
	if (this != &obj)
		this->_value = obj._value;
	return (*this);
}

int	Fixed::getRawBits(void) const 
{ 
		return (this->_value); 
};

void	Fixed::setRawBits(int const raw) 
{ 
		this->_value = raw; return ;
};

Fixed::~Fixed(void)
{
	std::cout << "Destructor called" << std::endl;
	return ;
}
