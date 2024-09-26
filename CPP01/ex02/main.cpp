#include <string>
#include <iostream>
#include <cstdlib>
#include <iomanip>

int	main(void)
{
	std::string message = "HI THIS IS BRAIN";
	std::string *stringPTR = &message;
	std::string &stringREF = message;
	int	N = 31;

	std::cout << std::setw(N) << std::left << "Memory of string: " << &message << std::endl;
	std::cout << std::setw(N) << "Memory held by stringPTR:" << stringPTR << std::endl;
	std::cout << std::setw(N) << "Memory held by stringREF:" << &stringREF << std::endl;
	std::cout << std::setw(N) << "Value of stringPTR:" << message << std::endl;
	std::cout << std::setw(N) << "Value pointed to by stringPTR:" << *stringPTR << std::endl;
	std::cout << std::setw(N) << "Value pointed to by stringREF:" << stringREF << std::endl;

	return (EXIT_SUCCESS);
}