#include "ClapTrap.hpp"
#include "ScavTrap.hpp"
#include "FragTrap.hpp"
#include <cstdlib>
#include <iostream>

int	main(void)
{
	std::cout << std::endl << "----- Allocating on stack -----" << std::endl;
	// ClapTrap	aStack("aStack");
	// aStack.attack("something");
	// aStack.beRepaired(1);
	// aStack.takeDamage(1);
	// std::cout << std::endl << "--------------------------" << std::endl;

	// ScavTrap	bStack("bStack");
	// bStack.guardGate();
	// bStack.guardGate();
	// bStack.attack("something");
	// bStack.beRepaired(1);
	// bStack.takeDamage(10);
	// std::cout << std::endl << "--------------------------" << std::endl;
	
	FragTrap	cStack("cStack");
	cStack.highFivesGuys();
	cStack.attack("something");
	cStack.takeDamage(100);
	cStack.beRepaired(1);
	cStack.attack("a zombie");
	cStack.takeDamage(2);
	cStack.highFivesGuys();
	
	std::cout << std::endl << "----- Allocating on heap -----" << std::endl;
	// ClapTrap	*aHeapPtr = new ClapTrap("aHeap");
	// aHeapPtr->attack("something");
	// aHeapPtr->beRepaired(1);
	// aHeapPtr->takeDamage(1);
	// delete aHeapPtr;
	// std::cout << std::endl << "--------------------------" << std::endl;

	// ScavTrap	*bHeapPtr = new ScavTrap("bHeap");
	// bHeapPtr->guardGate();
	// bHeapPtr->guardGate();
	// bHeapPtr->attack("something");
	// bHeapPtr->beRepaired(1);
	// bHeapPtr->takeDamage(10);
	// delete bHeapPtr;
	// std::cout << std::endl << "--------------------------" << std::endl;

	// ClapTrap	*bHeapBasePtr = new ScavTrap("bHeapBase");
	// bHeapBasePtr->attack("something");
	// bHeapBasePtr->beRepaired(1);
	// bHeapBasePtr->takeDamage(1);
	// delete bHeapBasePtr;
	// std::cout << std::endl << "--------------------------" << std::endl;

	FragTrap	*cHeapPtr = new FragTrap("cHeap");
	cHeapPtr->highFivesGuys();
	cHeapPtr->attack("something");
	cHeapPtr->takeDamage(100);
	cHeapPtr->beRepaired(1);
	cHeapPtr->attack("a zombie");
	cHeapPtr->takeDamage(2);
	cHeapPtr->highFivesGuys();
	delete cHeapPtr;
	std::cout << std::endl << "--------------------------" << std::endl;

	ClapTrap	*cHeapBasePtr = new FragTrap("cHeapBase");
	cHeapBasePtr->attack("something");
	cHeapBasePtr->beRepaired(1);
	cHeapBasePtr->takeDamage(1);
	delete cHeapBasePtr;	
	std::cout << std::endl << "--------------------------" << std::endl;
	
	return (EXIT_SUCCESS);
}