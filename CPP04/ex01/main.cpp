#include "Ex01.hpp"
#include "Dog.hpp"
#include "Cat.hpp"
#include "WrongCat.hpp"

int main(void)
{
	std::cout << BOLD "------------------SUBJECT TESTS------------------" RESET << std::endl;
	std::cout << "--- CONSTRUCTION ---" RESET << std::endl;
	const Animal	*j = new Dog();
	const Animal	*i = new Cat();
	std::cout << "--- MAKE SOUND ---" RESET << std::endl;
	j->makeSound();
	i->makeSound();
	std::cout << "--- CLEAN UP ---" RESET << std::endl;
	delete j;
	delete i;

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
	Animal	*arrayAnimalPointers[4];
	std::cout << "--- CONSTRUCTION ---" RESET << std::endl;
	for (int i = 0; i < 2; i++)
	{
		arrayAnimalPointers[i] = new Dog();
	}
	for (int i = 2; i < 4; i++)
	{
		arrayAnimalPointers[i] = new Cat();
	}
	std::cout << "--- MAKE SOUND ---" RESET << std::endl;
	for (int i = 0; i < 4; i++)
	{
		arrayAnimalPointers[i]->makeSound();
	}
	std::cout << "--- CLEAN UP ---" RESET << std::endl;
	for (int i = 0; i < 4; i++)
	{
		delete arrayAnimalPointers[i];
	}

	std::cout << BOLD "------------------OWN TESTS WITH ARRAY OF ANIMAL OBJECTS ------------------" RESET << std::endl;
	std::cout << "--- CREATE ARRAY ---" RESET << std::endl;
	Animal	arrayAnimalObjects[4];
	std::cout << "--- ASSIGN OBJECTS ---" RESET << std::endl;

	for (int i = 0; i < 2; i++)
	{
		arrayAnimalObjects[i] = Dog();
	}
	for (int i = 2; i < 4; i++)
	{
		arrayAnimalObjects[i] = Cat();
	}
	std::cout << "--- MAKE SOUND ---" RESET << std::endl;
	for (int i = 0; i < 4; i++)
	{
		arrayAnimalObjects[i].makeSound();
	}
	
	std::cout << BOLD "------------------ CLEAN UP ------------------" RESET << std::endl;
	
	return (EXIT_SUCCESS);
}