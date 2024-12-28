#include "ScalarConverter.hpp"

ScalarConverter::ScalarConverter(void) {}

void	ScalarConverter::convert(const std::string &literal) 
{
	// convertChar(literal);
	convertInt(literal);
	// convertFloat(literal);
	// convertDouble(literal);
}

void	ScalarConverter::convertInt(const std::string &literal)
{
	std::stringstream	ss(literal);
	double					doubleNum;

	if (ss >> doubleNum)
	{
		if (ss.eof())
		{
			if (doubleNum >= INT_MIN && doubleNum <= INT_MAX)
				std::cout << "int: " << static_cast<int>(doubleNum) << std::endl;
			else
				std::cout << "int: impossible" << std::endl;
			return;
		}
		std::string remaining;
		ss >> remaining;
		if (remaining == "f" && doubleNum >= INT_MIN && doubleNum <= INT_MAX)
		{
			std::cout << "int: " << static_cast<int>(doubleNum) << std::endl;
			return;
		}
		std::cout << "int: impossible" << std::endl;
		return;
	}
	std::cout << "int: impossible" << std::endl;
}
