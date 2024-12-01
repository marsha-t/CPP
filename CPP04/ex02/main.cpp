#include "Ex02.hpp"
#include "Dog.hpp"
#include "Cat.hpp"
#include "WrongCat.hpp"

void	subjectTests(void)
{
	std::cout << BOLD "------------------SUBJECT TESTS------------------" RESET << std::endl;
	std::cout << "--- CONSTRUCTION ---" RESET << std::endl;
	const AAnimal	*j = new Dog();
	const AAnimal	*i = new Cat();
	std::cout << "--- MAKE SOUND ---" RESET << std::endl;
	j->makeSound();
	i->makeSound();
	std::cout << "--- CLEAN UP ---" RESET << std::endl;
	delete j;
	delete i;
}

void	testDogCopy(void)
{
	std::cout << "--- CONSTRUCTION ---" RESET << std::endl;
	Dog dog1;
	dog1.setIdea("Idea 1");
	dog1.setIdea("Idea 2");
	dog1.setIdea("Idea 3");
	dog1.setIdea("Idea 4");
	dog1.setIdea("Idea 5");
	Dog dog2(dog1);
	std::cout << "--- PRINT ADDRESS ---" RESET << std::endl;
	dog1.printBrainAddress();
	dog1.printBrain();
	dog2.printBrainAddress();
	dog2.printBrain();
	std::cout << "--- COPY ASSIGNMENT ---" RESET << std::endl;
	dog1 = Dog();
	std::cout << "--- PRINT ADDRESS ---" RESET << std::endl;
	dog1.printBrainAddress();
	dog1.printBrain();
}

void	testCatCopy(void)
{
	std::cout << "--- CONSTRUCTION ---" RESET << std::endl;
	Cat cat1;
	cat1.setIdea("Idea 1");
	cat1.setIdea("Idea 2");
	cat1.setIdea("Idea 3");
	cat1.setIdea("Idea 4");
	cat1.setIdea("Idea 5");
	Cat cat2(cat1);
	std::cout << "--- PRINT ADDRESS ---" RESET << std::endl;
	cat1.printBrainAddress();
	cat1.printBrain();
	cat2.printBrainAddress();
	cat2.printBrain();
	std::cout << "--- COPY ASSIGNMENT ---" RESET << std::endl;
	cat1 = Cat();
	std::cout << "--- PRINT ADDRESS ---" RESET << std::endl;
	cat1.printBrainAddress();
	cat1.printBrain();
}

void	testArrayPointers(void)
{
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
}

// void	testArrayObjects(void)
// {
// 	std::cout << "--- CREATE ARRAY ---" RESET << std::endl;
// 	AAnimal	arrayAAnimalObjects[4];
// 	std::cout << "--- ASSIGN OBJECTS ---" RESET << std::endl;

// 	for (int i = 0; i < 2; i++)
// 	{
// 		arrayAAnimalObjects[i] = Dog();
// 	}
// 	for (int i = 2; i < 4; i++)
// 	{
// 		arrayAAnimalObjects[i] = Cat();
// 	}
// 	std::cout << "--- MAKE SOUND ---" RESET << std::endl;
// 	for (int i = 0; i < 4; i++)
// 	{
// 		arrayAAnimalObjects[i].makeSound();
// 	}
// }

int main(void)
{
	subjectTests();
	testDogCopy();
	testCatCopy();
	testArrayPointers();
	// testArrayObjects(); // not possible to run this 
	return (EXIT_SUCCESS);
}