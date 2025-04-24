#include "PmergeMe.hpp"

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
		PmergeMe	merge;
		merge.parse(argc, argv);
		merge.printBefore();
		if (merge.getSize() == 1)
		{
			merge.printAfter();
			return (0); 
		}
		merge.sort();
		// merge.checkSort();
		merge.printAfter();
	}
	catch (std::exception &e)
	{
		errorMsg(std::string("Exception: ") + e.what());
	}
}