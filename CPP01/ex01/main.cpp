#include "Zombie.hpp"
#include <cstdlib>

int	main(void)
{
	int	num = 5;
	Zombie *horde = zombieHorde(num, "zzz");

	for (int i = 0; i < num; i++)
	{
		horde[i].announce();
	}
	delete [] horde;
	return (EXIT_SUCCESS);
}