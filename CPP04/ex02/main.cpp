#include "Ex02.hpp"
#include "Dog.hpp"
#include "Cat.hpp"
#include "WrongCat.hpp"

int main(void)
{
	// std::cout << BOLD "------------------SUBJECT TESTS------------------" RESET << std::endl;
	// std::cout << "--- CONSTRUCTION ---" RESET << std::endl;
	// const AAnimal	*j = new Dog();
	// const AAnimal	*i = new Cat();
	// std::cout << "--- MAKE SOUND ---" RESET << std::endl;
	// j->makeSound();
	// i->makeSound();
	// std::cout << "--- CLEAN UP ---" RESET << std::endl;
	// delete j;
	// delete i;

	std::cout << BOLD "------------------OWN TESTS FOR SHALLOW/DEEP COPIES ------------------" RESET << std::endl;
	std::cout << "--- DOG ---" RESET << std::endl;
	Dog dog1;
	Dog dog2(dog1);
	dog1.printBrainAddress();
	dog2.printBrainAddress();
	dog1 = Dog();
	dog1.printBrainAddress();
	std::cout << "--- CAT ---" RESET << std::endl;
	Cat cat1;
	Cat cat2(cat1);
	cat1.printBrainAddress();
	cat2.printBrainAddress();
	cat1 = Cat();
	cat1.printBrainAddress();

	std::cout << BOLD "------------------OWN TESTS WITH ARRAY OF POINTERS TO ANIMAL OBJECTS ------------------" RESET << std::endl;
	AAnimal	*arrayAAnimalPointers[4];
	std::cout << "--- CONSTRUCTION ---" RESET << std::endl;
	for (int i = 0; i < 2; i++)
	{
		arrayAAnimalPointers[i] = new Dog();
	}
	for (int i = 2; i < 4; i++)
	{
		arrayAAnimalPointers[i] = new Cat();
	}
	std::cout << "--- MAKE SOUND ---" RESET << std::endl;
	for (int i = 0; i < 4; i++)
	{
		arrayAAnimalPointers[i]->makeSound();
	}
	std::cout << "--- CLEAN UP ---" RESET << std::endl;
	for (int i = 0; i < 4; i++)
	{
		delete arrayAAnimalPointers[i];
	}
	
	std::cout << BOLD "------------------ CLEAN UP ------------------" RESET << std::endl;
	
	return (EXIT_SUCCESS);
}