#include <cstdlib>
#include "Harl.hpp"

int	main(void)
{
	Harl	h_instance;

	h_instance.complain("DEBUG");
	h_instance.complain("INFO");
	h_instance.complain("WARNING");
	h_instance.complain("ERROR");
	h_instance.complain("OI");
	return (EXIT_SUCCESS);
}
