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
	std::size_t pos = 0;
	try
	{
		int	num = std::stoi(literal, &pos);
		if (pos == literal.length() || (pos == literal.length() - 1 && literal[pos] == 'f'))
		std::cout << "int: " << num << std::endl;
	}
	catch (const std::exception &e) 
	{
		std::cerr << "int: impossible" << std::endl;
	}
}
