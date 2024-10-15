#include "Fixed.hpp"
#include <iostream>

const int Fixed::_frac = 8;

Fixed::Fixed(void): _value(0)
{
	std::cout << "Default constructor called" << std::endl;
	return ;
}

Fixed::Fixed(const int value):_value(value << this->_frac)
{
	std::cout << "Int constructor called" << std::endl;
	return ;
}

Fixed::Fixed(const float value): _value(roundf(value * (1 << this->_frac)))
{
	std::cout << "Float constructor called" << std::endl;
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

Fixed::~Fixed(void)
{
	std::cout << "Destructor called" << std::endl;
	return ;
}

// int	Fixed::getRawBits(void) const 
// { 
// 		return (this->_value); 
// };

// void	Fixed::setRawBits(int const raw) 
// { 
// 		this->_value = raw; return ;
// };


// float	Fixed::toFloat(void) const // inline?
// {
// 	return (static_cast<float>(this->_value) / (1 << this->_frac));
// }

// int		Fixed::toInt(void) const // WIP: inline?
// {
// 	return (this->_value >> _frac);
// }

std::ostream &operator<<(std::ostream &out, Fixed const &obj)
{
	out << obj.toFloat() << std::flush;
	return (out);
}