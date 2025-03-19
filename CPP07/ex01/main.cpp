#include "iter.hpp"

void	testNormalCases(void)
{
	std::cout << "C String" << std::endl;
	char cString[] = "abc";
	iter(cString, 3, ::print<char>);

	std::cout << "\nInt Array" << std::endl;
	int	intArray[] = {40, 41, 42, 43, 44};
	iter(intArray, 5, ::print<int>);

	std::cout << "\nFloat Array" << std::endl;
	float	floatArray[] = {1.1, 2.2, 3.3, 4.4};
	iter(floatArray, 4, ::print<float>); 

	std::cout << "\nArray of Strings" << std::endl;
	std::string	words[] = {"Hello", "World", "!"};
	iter(words, 3, ::print<std::string>);
}

void	testEmptyArrays(void)
{
	std::cout << "C String" << std::endl;
	char cString[] = "";
	iter(cString, 0, ::print<char>);

	std::cout << "\nInt Array" << std::endl;
	int	intArray[] = {};
	iter(intArray, 0, ::print<int>);

	std::cout << "\nFloat Array" << std::endl;
	float	floatArray[] = {};
	iter(floatArray, 0, ::print<float>); 

	std::cout << "\nArray of Strings" << std::endl;
	std::string	words[] = {};
	iter(words, 0, ::print<std::string>);
}

void	testsingleElement(void)
{
	std::cout << "C String" << std::endl;
	char cString[] = "a";
	iter(cString, 1, ::print<char>);

	std::cout << "\nInt Array" << std::endl;
	int	intArray[] = {42};
	iter(intArray, 1, ::print<int>);

	std::cout << "\nFloat Array" << std::endl;
	float	floatArray[] = {42.5};
	iter(floatArray, 1, ::print<float>); 

	std::cout << "\nArray of Strings" << std::endl;
	std::string	words[] = {"Hello"};
	iter(words, 1, ::print<std::string>);
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
				testNormalCases();
				break ;
			}
			case 1:
			{
				testEmptyArrays();	
				break ;
			}
			case 2:
			{
				testsingleElement();
				break ;
			}
		}
		return (EXIT_SUCCESS);
	}
	return (EXIT_FAILURE);
}
