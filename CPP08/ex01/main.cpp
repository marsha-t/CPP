#include "Span.hpp"
#include <cstdlib>
#include <iostream>
#include <ctime>
#include <list>

#define RED "\033[31m"
#define RESET "\033[0m"

#define MAXSIZE 10000

void	testOverflow(Span &mySpan)
{
	try
	{
		mySpan.addNumber(1);
	}
	catch (const std::exception &e)
	{
		std::cout << RED "Exception: " << e.what() << RESET << std::endl;
	}
}

void	testSpan(Span &mySpan)
{
	try
	{
		std::cout << "Shortest: " << mySpan.shortestSpan() << std::endl;
	}
	catch (const std::exception &e)
	{
		std::cout << RED "Exception: " << e.what() << RESET << std::endl;
	}
	try
	{
		std::cout << "Longest: " << mySpan.longestSpan() << std::endl;
	}
	catch (const std::exception &e)
	{
		std::cout << RED "Exception: " << e.what() << RESET << std::endl;
	}
}

int	main(int argc, char **argv)
{
	if (argc < 2)
		return (1);
	
	int	test = std::atoi(argv[1]);
	if (test < 0 || test > 6)
		return (1);

	Span mySpan(MAXSIZE);
	std::cout << "Max Size: " << MAXSIZE << std::endl;
	std::srand(std::time(0));
	switch (test)
	{
		case 0:
			break ;
		case 1:
			mySpan.addNumber(10);
			break ;
		case 2:
			mySpan.addNumber(10);
			mySpan.addNumber(3);
			break ;
		case 3:
			mySpan.addNumber(10);
			mySpan.addNumber(3);
			mySpan.addNumber(5);
			break ;

		// case 3:
		// 	mySpan.addNumber(5);
		// 	// fall through
		// case 2:
		// 	mySpan.addNumber(3);
		// 	// fall through
		// case 1:
		// 	mySpan.addNumber(10);
		// 	break ;
		case 4:
		{
			std::vector<int>	myVector;
			for (int i = 0; i < MAXSIZE; i++)
			{
				myVector.push_back(rand());
			}
			mySpan.addNumber(myVector.begin(), myVector.end());
			testOverflow(mySpan);
			break;
		}
		case 5:
		{
			std::list<int>	myList;
			for (int i = 0; i < MAXSIZE; i++)
			{
				myList.push_front(rand());
			}
			mySpan.addNumber(myList.begin(), myList.end());
			testOverflow(mySpan);
			break;
		}
		case 6:
		{
			int	myArray[MAXSIZE];
			for (int i = 0; i < MAXSIZE; i++)
			{
				myArray[i] = rand();
			}
			mySpan.addNumber(myArray, myArray + MAXSIZE);
			testOverflow(mySpan);
			break;
		}
	}
	testSpan(mySpan);
	return (0);	
}

