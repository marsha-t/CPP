#include <iostream>
#include <string>
#include <cstdlib>
#include "Zombie.hpp"

# define BOLD "\033[1m"
# define RESET "\033[0m"

int	main(void)
{
	std::cout << BOLD "Zombie allocated on stack" RESET << std::endl;
	Zombie stack_zombie("stack zombie");
	stack_zombie.announce();
	std::cout << BOLD "Zombie allocated on heap" RESET << std::endl;
	Zombie *heap_zombie = newZombie("heap zombie");
	heap_zombie->announce();
	delete heap_zombie;
	std::cout << BOLD "Zombie allocated via randomchump" RESET << std::endl;
	randomChump("stack chump");
	return (EXIT_SUCCESS);
}