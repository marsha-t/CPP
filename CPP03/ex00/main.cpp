#include "ClapTrap.hpp"
#include <cstdlib>

int	main(void)
{
	ClapTrap a("A");
	a.attack("something");
	a.beRepaired(1);
	a.takeDamage(1);
	a.takeDamage(11);
	a.attack("a zombie");
	a.beRepaired(1);
	a.takeDamage(2);
	return (EXIT_SUCCESS);
}
