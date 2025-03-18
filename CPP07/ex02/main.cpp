#include "Array.tpp"
#include "Array.hpp"

#include <iostream>
#include <string>
#include <cstdlib>


void	testIntArray(void)
{
	// int	*a = new int();
	// std::cout << *a << std::endl;
	Array<int>	emptyArray;
	std::cout << "Size of empty array: " << emptyArray.size() <<std::endl;

	Array<int>	intArray(5);
	std::cout << intArray.size() <<std::endl;
	intArray[2] = 2;
	std::cout << intArray[2] << std::endl;
	try
	{
		intArray[5] = 2;
	}
	catch (std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}
}

void	testStringArray(void)
{

}

int	main(void)
{
	testIntArray();
	testStringArray();	
	return (EXIT_SUCCESS);
}