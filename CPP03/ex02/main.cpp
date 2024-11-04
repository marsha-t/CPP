#include "ClapTrap.hpp"
#include "ScavTrap.hpp"
#include "FragTrap.hpp"
#include <cstdlib>

int	main(void)
{
	// ClapTrap a("A");
	// a.attack("something");
	// a.takeDamage(10);
	// a.beRepaired(1);
	// a.attack("a zombie");
	// a.takeDamage(2);

	// ScavTrap b("B");
	// b.guardGate();
	// b.guardGate();
	// b.attack("something");
	// b.takeDamage(100);
	// b.beRepaired(1);
	// b.attack("a zombie");
	// b.takeDamage(2);

	FragTrap c("C");
	c.highFivesGuys();
	c.attack("something");
	c.takeDamage(100);
	c.beRepaired(1);
	c.attack("a zombie");
	c.takeDamage(2);
	c.highFivesGuys();
	return (EXIT_SUCCESS);
}