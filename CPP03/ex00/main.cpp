#include "ClapTrap.hpp"
#include <cstdlib>
#include <iostream>

int	main(void)
{
	std::cout << "----- Allocating on stack -----" << std::endl;
	ClapTrap	aStack("aStack");
	aStack.attack("something");
	aStack.beRepaired(1);
	aStack.takeDamage(1);
	aStack.takeDamage(11);
	aStack.attack("a zombie");
	aStack.beRepaired(1);
	aStack.takeDamage(2);

	std::cout << "----- Allocating on heap -----" << std::endl;
	ClapTrap	*aHeapPtr = new ClapTrap("aHeap");
	aHeapPtr->attack("something");
	aHeapPtr->beRepaired(1);
	aHeapPtr->takeDamage(1);
	aHeapPtr->takeDamage(11);
	aHeapPtr->attack("a zombie");
	aHeapPtr->beRepaired(1);
	aHeapPtr->takeDamage(2);
	delete aHeapPtr;
	return (EXIT_SUCCESS);
}
