#include "Harl.hpp"
#include <cstdlib>
#include <iostream>

int	main(int argc, char **argv)
{
	Harl	h_instance;

	if (argc != 2)
	{
		std::cout << "Unclear complaint: wrong number of arguments" << std::endl;
	}
	else
	{
		h_instance.complain(argv[1]);
	}
	return (EXIT_SUCCESS);
}