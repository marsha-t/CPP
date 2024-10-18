#include "Fixed.hpp"
#include <cstdlib>
#include <iostream>

int main(void) 
{
	Fixed a;
	Fixed const b( Fixed( 5.05f ) * Fixed( 2 ) );
	std::cout << "a: " << a << std::endl;
	std::cout << "a: " << ++a << std::endl;
	std::cout << "a: " << a << std::endl;
	std::cout << "a: " << a++ << std::endl;
	std::cout << "a: " << a << std::endl;
	std::cout << "b: " << b << std::endl;
	std::cout << "max: " << Fixed::max( a, b ) << std::endl;

	std::cout << "------Own tests------" << std::endl;
	Fixed c(2);
	std::cout << "2: " << c << std::endl;
	std::cout << "4: " << c + c << std::endl;
	std::cout << "0: " << c - c << std::endl;
	std::cout << "4: " << c * c<< std::endl;
	std::cout << "1: " << c / c << std::endl;
	std::cout << "2: " << c-- << std::endl;
	std::cout << "1.99609375: " << c << std::endl;
	std::cout << "1.9921875: " << --c << std::endl;
	std::cout << "1.9921875: " << c << std::endl;
	std::cout << "1.9921875: " << Fixed::min(c, c) << std::endl;
	try
	{
		std::cout << c / (c - c) << std::endl;
	}
	catch (const std::runtime_error &e)
	{
		std::cerr << "Error: " << e.what() << std::endl;
		return (EXIT_FAILURE);
	}

	return (EXIT_SUCCESS);
}
