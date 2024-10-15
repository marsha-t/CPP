#include "Fixed.hpp"
#include <cstdlib>
#include <iostream>

int main()
{
	Fixed a;
	Fixed b( a );
	Fixed c;
	c = b;
	std::cout << "a value: " << a.getRawBits() << std::endl;
	std::cout << "b value: " << b.getRawBits() << std::endl;
	std::cout << "c value: " << c.getRawBits() << std::endl;
	a.setRawBits(2);
	b.setRawBits(4);
	c.setRawBits(6);
	std::cout << "a value: " << a.getRawBits() << std::endl;
	std::cout << "b value: " << b.getRawBits() << std::endl;
	std::cout << "c value: " << c.getRawBits() << std::endl;
	return (EXIT_SUCCESS);
}
