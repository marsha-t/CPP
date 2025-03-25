#include "BitcoinExchange.hpp"

BitcoinExchange::BitcoinExchange(void) 
{
	debugMsg("BitcoinExchange initialised");
}

BitcoinExchange::BitcoinExchange(const BitcoinExchange &obj)
{
	debugMsg("BitcoinExchange initalised via copy");
	// deep copy
}

BitcoinExchange::~BitcoinExchange(void) 
{
	debugMsg("BitcoinExchange destroyed");
}

BitcoinExchange	&BitcoinExchange::operator=(const BitcoinExchange &obj)
{
	if (this != &obj)
	{
		// deal with copy
	}
	return (*this);
}

bool	BitcoinExchange::loadDatabase(std::string const &filename)
{
	std::ifstream database(filename);
	if (!database.is_open())
	{
		std::cerr << "Error opening " << filename << std::endl;
		return (false);
	}
}

double	BitcoinExchange::getRate(std::string const &date) const
{

}