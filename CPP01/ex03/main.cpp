#include "Weapon.hpp"
#include "HumanA.hpp"
#include "HumanB.hpp"
#include <cstdlib>
#include <iostream>

int	main(void)
{
	{
		std::cout << "---------------------------- Scenario 1 ---------------------------- "<< std::endl;
		Weapon club = Weapon("crude spiked club");
		HumanA bob("Bob", club);
		bob.attack();
		club.setType("some other type of club");
		bob.attack();
	}
	{
		std::cout << "---------------------------- Scenario 2 ---------------------------- "<< std::endl;
		Weapon club = Weapon("crude spiked club");
		HumanB jim("Jim");
		jim.setWeapon(club);
		jim.attack();
		club.setType("some other type of club");
		jim.attack();
	}
	{
		std::cout << "---------------------------- Scenario 3 ---------------------------- "<< std::endl;
		Weapon club = Weapon("crude spiked club");
		HumanA bob("Bob", club);
		bob.attack();
		Weapon axe = Weapon("axe");
		bob.setWeapon(axe);
		bob.attack();
	}
	{
		std::cout << "---------------------------- Scenario 4 ---------------------------- "<< std::endl;
		HumanB jim("Jim");
		jim.attack();
		Weapon club = Weapon("crude spiked club");
		jim.setWeapon(club);
		jim.attack();
	}
	return (EXIT_SUCCESS);
}
