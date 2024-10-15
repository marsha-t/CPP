#include "Fixed.hpp"
#include <cstdlib>
#include <iostream>

int main( void ) 
{
	Fixed a;
	Fixed const b( Fixed( 5.05f ) * Fixed( 2 ) );
	std::cout << a << std::endl;
	std::cout << ++a << std::endl;
	std::cout << a << std::endl;
	std::cout << a++ << std::endl;
	std::cout << a << std::endl;
	std::cout << b << std::endl;
	// std::cout << Fixed::max( a, b ) << std::endl;

	std::cout << "------Own tests------" << std::endl;
	Fixed c(2);
	std::cout << c << std::endl;
	std::cout << c + c << std::endl;
	std::cout << c - c << std::endl;
	std::cout << c * c<< std::endl;
	std::cout << c / c << std::endl;
	// std::cout << c / (c - c) << std::endl;
	return (EXIT_SUCCESS);
}
