#include "Fixed.hpp"
#include <cstdlib>
#include <iostream>

int main(void) 
{
	std::cout << "a: " << std::flush;
	Fixed a;
	std::cout << "b: " << std::flush;
	Fixed const b( 10 );
	std::cout << "c: " << std::flush;
	Fixed const c( 42.42f );
	std::cout << "d: " << std::flush;
	Fixed const d( b );
	std::cout << "a: " << std::flush;
	a = Fixed( 1234.4321f );
	std::cout << "a is " << a << std::endl;
	std::cout << "b is " << b << std::endl;
	std::cout << "c is " << c << std::endl;
	std::cout << "d is " << d << std::endl;
	std::cout << "a is " << a.toInt() << " as integer" << std::endl;
	std::cout << "b is " << b.toInt() << " as integer" << std::endl;
	std::cout << "c is " << c.toInt() << " as integer" << std::endl;
	std::cout << "d is " << d.toInt() << " as integer" << std::endl;
	return (EXIT_SUCCESS);
}
