#include "Bureaucrat.hpp"

bool	debugOn = false;

void	debugMsg(std::string msg)
{
	if (debugOn)
		std::cout << msg << std::endl;
}

int	main(void)
{
	return (EXIT_SUCCESS);	
}