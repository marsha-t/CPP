#include "Fixed.hpp"
#include "Point.hpp"
#include <cstdlib>
#include <iostream>

int main(void) 
{
	Point	a(0, 0);
	Point	b(4, 0);
	Point	c(0, 4);

	Point	outside(5, 1);
	Point	inside(1, 1);
	Point	collinear(2, 0);

	std::cout << std::boolalpha << "Outside point is found to be inside: " << bsp(a, b, c, outside) << std::endl;
	std::cout << std::boolalpha << "Inside point is found to be inside: " << bsp(a, b, c, inside) << std::endl;
	std::cout << std::boolalpha << "Collinear point is found to be inside: " << bsp(a, b, c, collinear) << std::endl;

	Point	temp;
	std::cout << temp.getX() << ", " << temp.getY() << std::endl;
	temp = outside;
	std::cout << temp.getX() << ", " << temp.getY() << std::endl;
	return (EXIT_SUCCESS);
}
