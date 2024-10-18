#include "Point.hpp"
#include <iostream>

Point::Point(void): x(0), y(0)
{
	// std::cout << "Point constructor called" << std::endl;
	return ;
}

Point::Point(const float x_val, const float y_val): x(x_val), y(y_val)
{
	// std::cout << "Point constructor with given floats called" << std::endl;
	return ;
}

Point::Point(const Point &obj): x(obj.x), y(obj.y)
{
	// std::cout << "Point copy constructor called" << std::endl;
	return ;
}

Point &Point::operator=(const Point &obj) // HOW?
{
	std::cout << "Point copy assignment operator called" << std::endl;
	if (this != &obj)
	{
		std::cout << "Casting away const to reassign" << std::endl;
		// static_cast<Fixed>(this->x) = obj.getX();
		// (Fixed)(this->x) = obj.getX();
		std::cout << "inside:" << this->x << obj.getX() << std::endl;
		// static_cast<Fixed>(this->y) = obj.getY();
		// (Fixed)(this->y) = obj.getY();
		std::cout << "inside:" << this->y << obj.getY() << std::endl;
	}
	return (*this);
}

Point::~Point(void)
{
	// std::cout << "Point destructor called" << std::endl;
	return ;
}

const Fixed	Point::getX(void) const
{
	return (this->x);
}

const Fixed	Point::getY(void) const
{
	return (this->y);
}
