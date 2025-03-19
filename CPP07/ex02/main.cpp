#include "Array.hpp"

#include <iostream>
#include <string>
#include <cstdlib>


void	testIntArray(void)
{
	std::cout << "--- EMPTY ARRAY ---" << std::endl;
	Array<int>	emptyArray;
	std::cout << "Size of empty array: " << emptyArray.size() <<std::endl;
	try
	{
		std::cout << emptyArray[0] << std::endl;
	}
	catch (std::exception &e)
	{
		std::cout << "Exception: " << e.what() << std::endl;
	}


	std::cout << "--- Int Array (5) ---" << std::endl;
	Array<int>	intArray(5);
	std::cout << "Size of int[5]: " << intArray.size() <<std::endl;
	for (unsigned int i = 0; i < intArray.size(); i++)
		std::cout << intArray[i] << " " << std::flush;
	
	intArray[2] = 2;
	std::cout << std::endl; 
	for (unsigned int i = 0; i < intArray.size(); i++)
		std::cout << intArray[i] << " " << std::flush;
	std::cout << std::endl; 

	try
	{
		intArray[5] = 2;
	}
	catch (std::exception &e)
	{
		std::cout << "Exception: " << e.what() << std::endl;
	}

		
	std::cout << "--- Copy ---" << std::endl;
	Array<int> copyIntArray(intArray);
	std::cout << "Size of copy: " << copyIntArray.size() <<std::endl;
	for (unsigned int i = 0; i < copyIntArray.size(); i++)
	{
		std::cout << copyIntArray[i] << " " << std::flush;
	}
	std::cout << std::endl;
	
	Array<int>	newIntArray(3);
	std::cout << "Size of newIntArray: " << newIntArray.size() << std::endl;
	for (unsigned int i = 0; i < newIntArray.size(); i++)
	{
		std::cout << newIntArray[i] << " " <<std::flush;
	}
	std::cout << std::endl;

	newIntArray = intArray; 
	std::cout << "Size of newIntArray: " << newIntArray.size() << std::endl;
	for (unsigned int i = 0; i < newIntArray.size(); i++)
	{
		std::cout << newIntArray[i] << " " <<std::flush;
	}
	std::cout << std::endl;
}

void	testStringArray(void)
{
	std::cout << "--- EMPTY ARRAY ---" << std::endl;
	Array<std::string>	emptyArray;
	std::cout << "Size of empty array: " << emptyArray.size() <<std::endl;
	try
	{
		std::cout << emptyArray[0] << std::endl;
	}
	catch (std::exception &e)
	{
		std::cout << "Exception: " << e.what() << std::endl;
	}


	std::cout << "--- String Array (5) ---" << std::endl;
	Array<std::string>	strArray(5);
	std::cout << "Size of str[5]: " << strArray.size() <<std::endl;
	for (unsigned int i = 0; i < strArray.size(); i++)
	{
		if (strArray[i] == "")
			std::cout << "_ " << std::flush;
	}
	
	strArray[2] = "a";
	std::cout << std::endl; 
	for (unsigned int i = 0; i < strArray.size(); i++)
	{
		if (strArray[i] == "")
			std::cout << "_ " << std::flush;
		else
			std::cout << strArray[i] << " " << std::flush;
	}
	std::cout << std::endl; 

	try
	{
		strArray[5] = 2;
	}
	catch (std::exception &e)
	{
		std::cout << "Exception: " << e.what() << std::endl;
	}

		
	std::cout << "--- Copy ---" << std::endl;
	Array<std::string> copyStrArray(strArray);
	std::cout << "Size of copy: " << copyStrArray.size() <<std::endl;
	for (unsigned int i = 0; i < copyStrArray.size(); i++)
	{
		if (strArray[i] == "")
			std::cout << "_ " << std::flush;
		else
			std::cout << copyStrArray[i] << " " << std::flush;
	}
	std::cout << std::endl;
	
	Array<std::string>	newStrArray(3);
	std::cout << "Size of newStrArray: " << newStrArray.size() << std::endl;
	for (unsigned int i = 0; i < newStrArray.size(); i++)
	{
		if (newStrArray[i] == "")
			std::cout << "_ " << std::flush;
		else
			std::cout << newStrArray[i] << " " <<std::flush;
	}
	std::cout << std::endl;

	newStrArray = strArray; 
	std::cout << "Size of newStrArray: " << newStrArray.size() << std::endl;
	for (unsigned int i = 0; i < newStrArray.size(); i++)
	{
		if (strArray[i] == "")
			std::cout << "_ " << std::flush;
		else
			std::cout << newStrArray[i] << " " <<std::flush;
	}
	std::cout << std::endl;
}

void	testConstArray(void)
{
	const Array<int> intArray(5);
	std::cout << "Size of int[5]: " << intArray.size() <<std::endl;
	for (unsigned int i = 0; i < intArray.size(); i++)
		std::cout << intArray[i] << " " << std::flush;
	std::cout << std::endl;
	// intArray[2] = 2;
}

int	main(int argc, char **argv)
{
	if (argc == 2)
	{
		int	test = std::atoi(argv[1]);
		if (test < 0 || test > 2)
			return (EXIT_FAILURE);
		switch (test)
		{
			case 0:
			{
				testIntArray();
				break ; 
			}
			case 1:
			{
				testStringArray();
				break ;
			}
			case 2:
			{
				testConstArray();
				break ;
			}
		}
		return (EXIT_SUCCESS);
	}
	return (EXIT_FAILURE);
}