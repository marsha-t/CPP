#include "BitcoinExchange.hpp"

bool	debugOn = false;
bool	errorOn = true;

void	debugMsg(std::string msg)
{
	if (debugOn)
		std::cout << msg << std::endl;
}

void	errorMsg(std::string msg)
{
	if (errorOn)
		std::cerr << msg << std::endl;
}

int	main(int argc, char **argv)
{
	try
	{
		if (argc != 2)
			throw std::invalid_argument("Invalid number of arguments");
		BitcoinExchange	exchange;
		exchange.loadDatabase("data.csv");
		exchange.processInput(argv[1]);
	}
	catch (std::exception &e)
	{
		errorMsg(std::string("Exception: ") + e.what());
	}
	return (0);
}