#include "easyfind.hpp"

#include <iostream>
#include <vector>
#include <list>
#include <deque>

#define RED "\033[31m"
#define RESET "\033[0m"

void	testVector(int *arr)
{
	std::vector<int> myVector(arr, arr + 4);
	std::cout << *easyfind(myVector, 2) << std::endl;
	try
	{
		std::cout << *easyfind(myVector, 5) << std::endl;
	}
	catch (const std::exception &e)
	{
		std::cout << RED "Exception: " << e.what() << RESET << std::endl;
	}
}

void	testList(int *arr)
{
	std::list<int>	myList(arr, arr + 4);
	std::cout << *easyfind(myList, 2) << std::endl;
	try
	{
		std::cout << *easyfind(myList, 5) << std::endl;
	}
	catch (const std::exception &e)
	{
		std::cout << RED "Exception: " << e.what() << RESET << std::endl;
	}
}

void	testDeque(int *arr)
{
	std::deque<int>	myDeque(arr, arr + 4);
	std::cout << *easyfind(myDeque, 2) << std::endl;
	try
	{
		std::cout << *easyfind(myDeque, 5) << std::endl;
	}
	catch (const std::exception &e)
	{
		std::cout << RED "Exception: " << e.what() << RESET << std::endl;
	}
}

int	main(int argc, char **argv)
{
	if (argc == 2)
	{
		int	test = atoi(argv[1]);
		int	arr[] = {1, 2, 3, 4};
		switch (test)
		{
			case 0:
			{
				testVector(arr);
				break ;
			}
			case 1:
			{
				testList(arr);
				break ;
			}
			case 2:
			{
				testDeque(arr);
				break ;
			}
		}
	}
	return (0);
}
