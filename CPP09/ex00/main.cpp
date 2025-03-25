#include "BitcoinExchange.hpp"
#include <iostream>

void	debugMsg(std::string msg)
{
	std::cout << msg << std::endl;
}

int	main(int argc, char **argv)
{
	if (argc != 3)
	{
		std::cerr << "Invalid number of arguments" << std::endl;
		return (1);
	}
	BitcoinExchange	exchange;
	exchange.loadDatabase(argv[1]);
	// read csv
	// validate date format & exchange rate
	// store in map
	// read request file
	// search for value
	// print found value

}