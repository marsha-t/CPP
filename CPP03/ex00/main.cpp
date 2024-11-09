#include "ClapTrap.hpp"
#include <cstdlib>
#include <iostream>

int	main(void)
{
	std::cout << "----- Allocating on stack -----" << std::endl;
	ClapTrap a("A");
	a.attack("something");
	a.beRepaired(1);
	a.takeDamage(1);
	a.takeDamage(11);
	a.attack("a zombie");
	a.beRepaired(1);
	a.takeDamage(2);

	std::cout << "----- Allocating on heap -----" << std::endl;
	ClapTrap *a_ptr = new ClapTrap("A_HEAP");
	a_ptr->attack("something");
	a_ptr->beRepaired(1);
	a_ptr->takeDamage(1);
	a_ptr->takeDamage(11);
	a_ptr->attack("a zombie");
	a_ptr->beRepaired(1);
	a_ptr->takeDamage(2);
	delete a_ptr;
	return (EXIT_SUCCESS);
}
