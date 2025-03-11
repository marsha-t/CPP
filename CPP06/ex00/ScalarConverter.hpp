#ifndef SCALARCONVERTER_HPP
#define SCALARCONVERTER_HPP

#include "Ex00.hpp"

class ScalarConverter
{
	public:
		static void	convert(const std::string &literal);
	private:
		// OCN
		ScalarConverter(void);
		ScalarConverter(const ScalarConverter &obj);
		~ScalarConverter(void);
		ScalarConverter &operator=(const ScalarConverter &obj);

		// Helper functions
		static bool	pseudoLiteral(const std::string &literal);
		static void	convertChar(double d);
		static void	convertInt(double d);
		static void	convertFloat(double d);
		static void	convertDouble(double d);


};

#endif