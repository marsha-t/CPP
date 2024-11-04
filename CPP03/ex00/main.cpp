#include "ClapTrap.hpp"
#include <cstdlib>

int	main(void)
{
	ClapTrap a("A");
	ClapTrap b("B");

	// A = B;
	a.attack("something");
	b.takeDamage(10);
	b.beRepaired(1);
	return (EXIT_SUCCESS);
}