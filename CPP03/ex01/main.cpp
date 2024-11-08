#include "ClapTrap.hpp"
#include "ScavTrap.hpp"
#include <cstdlib>

int	main(void)
{
	// ClapTrap a("A");
	// a.attack("something");
	// a.takeDamage(10);
	// a.beRepaired(1);
	// a.attack("a zombie");
	// a.takeDamage(2);

	ScavTrap b("B");
	b.guardGate();
	b.guardGate();
	b.attack("something");
	b.beRepaired(1);
	b.takeDamage(10);
	b.beRepaired(1);
	b.attack("a zombie");
	b.takeDamage(2);
	return (EXIT_SUCCESS);
}