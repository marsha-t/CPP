#include "ClapTrap.hpp"
#include "ScavTrap.hpp"
#include <cstdlib>
#include <iostream>

int	main(void)
{
	std::cout << "----- Allocating on stack -----" << std::endl;
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
	// b.beRepaired(1);
	// b.takeDamage(10);
	// b.beRepaired(1);
	// b.attack("a zombie");
	// b.takeDamage(2);
	
	
	std::cout << "----- Allocating on heap -----" << std::endl;
	// ClapTrap *a_ptr = new ClapTrap("A_HEAP");
	// a_ptr->attack("something");
	// a_ptr->beRepaired(1);
	// a_ptr->takeDamage(1);
	// a_ptr->takeDamage(11);
	// a_ptr->attack("a zombie");
	// a_ptr->beRepaired(1);
	// a_ptr->takeDamage(2);
	// delete a_ptr;

	// ScavTrap *b_ptr = new ScavTrap("B_HEAP");
	// b_ptr->attack("something");
	// b_ptr->beRepaired(1);
	// b_ptr->takeDamage(1);
	// b_ptr->takeDamage(11);
	// b_ptr->attack("a zombie");
	// b_ptr->beRepaired(1);
	// b_ptr->takeDamage(2);
	// delete b_ptr;

	ClapTrap *c_ptr = new ScavTrap("C_HEAP");
	c_ptr->attack("something");
	c_ptr->beRepaired(1);
	c_ptr->takeDamage(1);
	c_ptr->takeDamage(11);
	c_ptr->attack("a zombie");
	c_ptr->beRepaired(1);
	c_ptr->takeDamage(2);
	delete c_ptr;

	return (EXIT_SUCCESS);
}