#ifndef SCALARCONVERTER_HPP
#define SCALARCONVERTER_HPP

#include "Ex00.hpp"

class ScalarConverter
{
	public:
		static void	convert(const std::string &literal);
	private:
		ScalarConverter(void);
		// OCN?

		static void	convertInt(const std::string &literal);
		static void	convertFloat(const std::string &literal);

};

#endif