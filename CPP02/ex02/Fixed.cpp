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

Fixed::Fixed(const Fixed &obj): _value(obj._value)
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

int	Fixed::getRawBits(void) const 
{ 
	return (this->_value); 
};

void	Fixed::setRawBits(int const raw) 
{ 
	this->_value = raw; 
	return ;
};

float	Fixed::toFloat(void) const
{
	return (static_cast<float>(this->_value) / (1 << this->_frac));
}

int		Fixed::toInt(void) const
{
	return (this->_value >>this-> _frac);
}

bool	Fixed::operator>(Fixed const &obj) const
{
	return (this->_value > obj._value);
}

bool	Fixed::operator<(Fixed const &obj) const
{
	return (this->_value < obj._value);
}

bool	Fixed::operator<=(Fixed const &obj) const
{
	return (!(*this > obj));
}

bool	Fixed::operator>=(Fixed const &obj) const
{
	return (!(*this < obj));
}

bool	Fixed::operator==(Fixed const &obj) const
{
	return (this->_value == obj._value);
}

bool	Fixed::operator!=(Fixed const &obj) const
{
	return (!(*this == obj));
}

Fixed	&Fixed::operator+=(Fixed const &obj)
{
	this->_value += obj._value;
	return (*this);
}

Fixed	Fixed::operator+(Fixed const &obj) const
{
	Fixed	temp = *this;
	temp += obj;
	return (temp);
}

Fixed	&Fixed::operator-=(Fixed const &obj)
{
	this->_value -= obj._value;
	return (*this);
}

Fixed	Fixed::operator-(Fixed const &obj) const
{
	Fixed	temp = *this;
	temp -= obj;
	return (temp);
}

Fixed	&Fixed::operator*=(Fixed const &obj)
{
	float	result = this->toFloat() * obj.toFloat();
	this->_value = roundf(result * (1 << this->_frac));
	return (*this);
}

Fixed	Fixed::operator*(Fixed const &obj) const
{
	Fixed	temp = *this;
	temp *= obj;
	return (temp);
}

Fixed	&Fixed::operator/=(Fixed const &obj)
{
	if (obj._value == 0)
		throw::std::runtime_error("Fixed point arithmetic: Division by zero");
	float	result = this->toFloat() / obj.toFloat();
	this->_value = roundf(result * (1 << this->_frac));
	return (*this);
}

Fixed	Fixed::operator/(Fixed const &obj) const
{
	Fixed	temp = *this;
	temp /= obj;
	return (temp);
}

Fixed	&Fixed::operator++(void)
{
	++this->_value;
	return (*this);
}

Fixed	Fixed::operator++(int)
{
	Fixed	ori = *this;
	++this->_value;
	return (ori);
}

Fixed	&Fixed::operator--(void)
{
	--this->_value;
	return (*this);
}

Fixed	Fixed::operator--(int)
{
	Fixed	ori = *this;
	--this->_value;
	return (ori);
}

std::ostream &operator<<(std::ostream &out, Fixed const &obj)
{
	out << obj.toFloat() << std::flush;
	return (out);
}

Fixed &Fixed::min(Fixed &obj1, Fixed &obj2)
{
	return ((obj1._value <= obj2._value) ? obj1 : obj2);
}
const Fixed &Fixed::min(Fixed const &obj1, Fixed const &obj2)
{
	return ((obj1._value <= obj2._value) ? obj1 : obj2);
}

Fixed &Fixed::max(Fixed &obj1, Fixed &obj2)
{
	return ((obj1._value >= obj2._value) ? obj1 : obj2);
}

const Fixed &Fixed::max(Fixed const &obj1, Fixed const &obj2)
{
	return ((obj1._value >= obj2._value) ? obj1 : obj2);
}

