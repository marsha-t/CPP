#include "easyfind.hpp"

#include <iostream>
#include <vector>
#include <list>
#include <deque>

#define RED "\033[31m"
#define RESET "\033[0m"

void	testVector(int *arr, int *dupArr)
{
	std::cout << "Test Normal Vector" << std::endl;
	std::vector<int> myVector(arr, arr + 4);
	std::cout << *easyfind(myVector, 1) << std::endl;
	std::cout << *easyfind(myVector, 2) << std::endl;
	std::cout << *easyfind(myVector, 4) << std::endl;
	try
	{
		std::cout << *easyfind(myVector, 5) << std::endl;
	}
	catch (const std::exception &e)
	{
		std::cout << RED "Exception: " << e.what() << RESET << std::endl;
	}


	std::cout << "\nTest Const Vector" << std::endl;
	const std::vector<int> myConstVector(arr, arr + 4);
	std::cout << *easyfind(myConstVector, 1) << std::endl;
	std::cout << *easyfind(myConstVector, 2) << std::endl;
	std::cout << *easyfind(myConstVector, 4) << std::endl;
	try
	{
		std::cout << *easyfind(myConstVector, 5) << std::endl;
	}
	catch (const std::exception &e)
	{
		std::cout << RED "Exception: " << e.what() << RESET << std::endl;
	}

	std::cout << "\nTest Empty Vector" << std::endl;
	std::vector<int> myEmptyVector;
	try
	{
		std::cout << *easyfind(myEmptyVector, 1) << std::endl;
	}
	catch (const std::exception &e)
	{
		std::cout << RED "Exception: " << e.what() << RESET << std::endl;
	}

	std::cout << "\nTest Duplicated Vector" << std::endl;
	std::vector<int> myDupVector(dupArr, dupArr + 2);
	if (easyfind(myDupVector, 42) == myDupVector.begin())
		std::cout << "Found at beginning" << std::endl;
}

void	testList(int *arr, int *dupArr)
{
	std::cout << "Test Normal List" << std::endl;
	std::list<int>	myList(arr, arr + 4);
	std::cout << *easyfind(myList, 1) << std::endl;
	std::cout << *easyfind(myList, 2) << std::endl;
	std::cout << *easyfind(myList, 4) << std::endl;
	try
	{
		std::cout << *easyfind(myList, 5) << std::endl;
	}
	catch (const std::exception &e)
	{
		std::cout << RED "Exception: " << e.what() << RESET << std::endl;
	}

	std::cout << "\nTest Const List" << std::endl;
	const std::list<int>	myConstList(arr, arr + 4);
	std::cout << *easyfind(myConstList, 1) << std::endl;
	std::cout << *easyfind(myConstList, 2) << std::endl;
	std::cout << *easyfind(myConstList, 4) << std::endl;
	try
	{
		std::cout << *easyfind(myConstList, 5) << std::endl;
	}
	catch (const std::exception &e)
	{
		std::cout << RED "Exception: " << e.what() << RESET << std::endl;
	}
	
	std::cout << "\nTest Empty List" << std::endl;
	std::list<int>	myEmptyList;
	try
	{
		std::cout << *easyfind(myEmptyList, 1) << std::endl;
	}
	catch (const std::exception &e)
	{
		std::cout << RED "Exception: " << e.what() << RESET << std::endl;
	}

	std::cout << "\nTest Duplicated List" << std::endl;
	std::list<int> myDupList(dupArr, dupArr + 2);
	if (easyfind(myDupList, 42) == myDupList.begin())
		std::cout << "Found at beginning" << std::endl;
}

void	testDeque(int *arr, int *dupArr)
{
	std::cout << "Test Normal Deque" << std::endl;
	std::deque<int>	myDeque(arr, arr + 4);
	std::cout << *easyfind(myDeque, 1) << std::endl;
	std::cout << *easyfind(myDeque, 2) << std::endl;
	std::cout << *easyfind(myDeque, 4) << std::endl;
	try
	{
		std::cout << *easyfind(myDeque, 5) << std::endl;
	}
	catch (const std::exception &e)
	{
		std::cout << RED "Exception: " << e.what() << RESET << std::endl;
	}
	
	std::cout << "\nTest Const Deque" << std::endl;
	const std::deque<int>	myConstDeque(arr, arr + 4);
	std::cout << *easyfind(myConstDeque, 1) << std::endl;
	std::cout << *easyfind(myConstDeque, 2) << std::endl;
	std::cout << *easyfind(myConstDeque, 4) << std::endl;
	try
	{
		std::cout << *easyfind(myConstDeque, 5) << std::endl;
	}
	catch (const std::exception &e)
	{
		std::cout << RED "Exception: " << e.what() << RESET << std::endl;
	}

	std::cout << "\nTest Empty Deque" << std::endl;
	std::deque<int>	myEmptyDeque;
	try
	{
		std::cout << *easyfind(myEmptyDeque, 1) << std::endl;
	}
	catch (const std::exception &e)
	{
		std::cout << RED "Exception: " << e.what() << RESET << std::endl;
	}

	std::cout << "\nTest Duplicated Deque" << std::endl;
	std::deque<int> myDupDeque(dupArr, dupArr + 2);
	if (easyfind(myDupDeque, 42) == myDupDeque.begin())
		std::cout << "Found at beginning" << std::endl;
}

int	main(int argc, char **argv)
{
	if (argc == 2)
	{
		int	test = std::atoi(argv[1]);
		if (test < 0 || test > 2)
			return (1);
		int	arr[] = {1, 2, 3, 4};
		int dupArr[] = {42, 42};
		switch (test)
		{
			case 0:
				testVector(arr, dupArr);
				break ;
			case 1:
				testList(arr, dupArr);
				break ;
			case 2:
				testDeque(arr, dupArr);
				break ;
		}
		return (0);
	}
	return (1);
}

