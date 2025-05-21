#include "iter.hpp"

void	testNormalAndConstCases(void)
{
	std::cout << "C String" << std::endl;
	char cString[] = "abc";
	iter(cString, 3, ::print<char>);

	std::cout << "\nConst C String" << std::endl;
	const char constCString[] = "abc";
	iter(constCString, 3, ::print<char>);

	std::cout << "\nInt Array" << std::endl;
	int	intArray[] = {40, 41, 42, 43, 44};
	iter(intArray, 5, ::print<int>);
	
	std::cout << "\nConst Int Array" << std::endl;
	int constIntArray[] = {40, 41, 42, 43, 44};
	iter(constIntArray, 5, ::print<int>);

	std::cout << "\nFloat Array" << std::endl;
	float	floatArray[] = {1.1, 2.2, 3.3, 4.4};
	iter(floatArray, 4, ::print<float>); 
	
	std::cout << "\nConst Float Array" << std::endl;
	float	constFloatArray[] = {1.1, 2.2, 3.3, 4.4};
	iter(constFloatArray, 4, ::print<float>); 

	std::cout << "\nArray of Strings" << std::endl;
	std::string	words[] = {"Hello", "World", "!"};
	iter(words, 3, ::print<std::string>);
	
	std::cout << "\nConst Array of Strings" << std::endl;
	const std::string	constWords[] = {"Hello", "World", "!"};
	iter(constWords, 3, ::print<std::string>);
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

void	testSingleElement(void)
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

void	testAddOneFunc(void)
{
	std::cout << "\nInt Array (Before)" << std::endl;
	int	intArray[] = {40, 41, 42, 43, 44};
	iter(intArray, 5, ::print<int>);
	iter(intArray, 5, ::addOne<int>);
	std::cout << "\nInt Array (After)" << std::endl;
	iter(intArray, 5, ::print<int>);


	std::cout << "\nFloat Array (Before)" << std::endl;
	float	floatArray[] = {1.1, 2.2, 3.3, 4.4};
	iter(floatArray, 4, ::print<float>); 
	iter(floatArray, 4, ::addOne<float>); 
	std::cout << "\nFloat Array (After)" << std::endl;
	iter(floatArray, 4, ::print<float>); 
}

int	main(int argc, char **argv)
{
	if (argc == 2)
	{
		int	test = std::atoi(argv[1]);
		if (test < 0 || test > 3)
			return (EXIT_FAILURE);
		switch (test)
		{
			case 0:
			{
				testNormalAndConstCases();
				break ;
			}
			case 1:
			{
				testEmptyArrays();	
				break ;
			}
			case 2:
			{
				testSingleElement();
				break ;
			}
			case 3:
			{
				testAddOneFunc();
				break ;
			}
		}
		return (EXIT_SUCCESS);
	}
	return (EXIT_FAILURE);
}
