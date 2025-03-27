#include "BitcoinExchange.hpp"
#include <iostream>

bool debugOn = false;

void	debugMsg(std::string msg)
{
	if (debugOn)
		std::cout << msg << std::endl;
}

void	errorMsg(std::string msg)
{
	std::cerr << msg << std::endl;
}

int	main(int argc, char **argv)
{
	if (argc != 2)
	{
		errorMsg("Invalid number of arguments");
		return (1);
	}
	BitcoinExchange	exchange;
	if (!exchange.loadDatabase("data.csv"))
		return (1);
	// exchange.printDatabase();
	if (!exchange.processInput(argv[1]))
		return (1);
	return (0);
}