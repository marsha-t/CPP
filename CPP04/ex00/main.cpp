#include "Ex00.hpp"
#include "Dog.hpp"
#include "Cat.hpp"
#include "WrongCat.hpp"

int main(void)
{
	std::cout << BOLD "------------------SUBJECT TESTS------------------" RESET << std::endl;
	const Animal *meta = new Animal();
	const Animal *j = new Dog();
	const Animal *i = new Cat();

	std::cout << j->getType() << std::endl;
	std::cout << i->getType() << std::endl;
	j->makeSound();
	i->makeSound();

	std::cout << BOLD "------------------OWN TESTS FOR CORRECT ANIMALS ------------------" RESET << std::endl;
	std::cout << meta->getType() << std::endl;
	meta->makeSound();

	std::cout << BOLD "------------------OWN TESTS FOR WRONG ANIMALS ------------------" RESET << std::endl;
	const WrongAnimal *wrongmeta = new WrongAnimal();
	const WrongAnimal *k = new WrongCat();
	std::cout << wrongmeta->getType() << std::endl;
	std::cout << k->getType() << std::endl;
	wrongmeta->makeSound();
	k->makeSound();
	std::cout << BOLD "------------------ CLEAN UP ------------------" RESET << std::endl;
	
	delete meta;
	delete i;
	delete j;
	return (EXIT_SUCCESS);
}