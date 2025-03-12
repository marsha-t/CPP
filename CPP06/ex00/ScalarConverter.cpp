#include "ScalarConverter.hpp"

void	ScalarConverter::convert(const std::string &literal)
{
	if (pseudoLiteral(literal))
		return ;
	
	double	d;
	if (literal.length() == 1 && !isdigit(literal[0]))
		d = static_cast<double>(literal[0]);
	else
	{
		char	*end;
		d = std::strtod(literal.c_str(), &end);
		if (!(*end == '\0' || (*end == 'f' && *(end + 1) == '\0')))
		{
			std::cout << "char: invalid\nint: invalid\nfloat: invalid\ndouble: invalid" << std::endl;
			return ; 
		}
	}
	convertChar(d);
	convertInt(d);
	convertFloat(d);
	convertDouble(d);
}

bool	ScalarConverter::pseudoLiteral(const std::string &literal)
{
	if (literal == "nan" || literal == "nanf") 
	{
        std::cout << "char: impossible\nint: impossible\nfloat: nanf\ndouble: nan" << std::endl;
        return (true);
    }
	else if (literal == "inf" || literal == "+inf" || literal == "+inff")
	{
		std::cout << "char: impossible\nint: impossible\nfloat: +inff\ndouble: +inf" << std::endl;
		return (true);
	}
	else if (literal == "-inf" || literal == "-inff")
	{
		std::cout << "char: impossible\nint: impossible\nfloat: -inff\ndouble: -inf" << std::endl;
		return (true);
	}
	return (false);
}

void	ScalarConverter::convertChar(double d)
{
	char c = static_cast<char>(d);
	if (d >= 0 && d <= 127 && d == c)
	{
		if (isprint(c))
			std::cout << "char: '" << c << "'" << std::endl;
		else
			std::cout << "char: Non displayable" << std::endl;
	}
	else
		std::cout << "char: impossible" << std::endl;
}

void	ScalarConverter::convertInt(double d)
{
	if (d >= std::numeric_limits<int>::min() && d <= std::numeric_limits<int>::max())
		std::cout << "int: " << static_cast<int>(d) << std::endl;
	else
		std::cout << "int: impossible" <<std::endl;
}

void	ScalarConverter::convertFloat(double d)
{
	if (d >= -std::numeric_limits<float>::max() && d <= std::numeric_limits<float>::max())
	{
		std::cout << std::fixed << std::setprecision(1);
		std::cout << "float: " <<  static_cast<float>(d) << "f" << std::endl;
	}
	else if (d < -std::numeric_limits<float>::max())
		std::cout << "float: -inff"	<< std::endl;
	else if (d > std::numeric_limits<float>::max())
		std::cout << "float: +inff"	<< std::endl;
	else if (isnan(d))
		std::cout << "float: nanf" << std::endl;
	else
		std::cout << d <<"float: impossible" << std::endl;
}
void	ScalarConverter::convertDouble(double d)
{
	if (d > std::numeric_limits<double>::max())
		std::cout << "double: +inf" << std::endl;
	else if (d < -std::numeric_limits<double>::max())
		std::cout << "double: -inf" << std::endl;
	else
	{
		std::cout << std::fixed << std::setprecision(1);
		std::cout << "double: " << d << std::endl;
	}
}

ScalarConverter::ScalarConverter(void) {}
ScalarConverter::ScalarConverter(const ScalarConverter &obj) 
{
	(void) obj;
}
ScalarConverter::~ScalarConverter(void) {}
ScalarConverter	&ScalarConverter::operator=(const ScalarConverter &obj) 
{ 
	(void) obj;
	return (*this);
}