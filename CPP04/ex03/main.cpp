#include "Ex03.hpp"
#include "Ice.hpp"
#include "Cure.hpp"
#include "Character.hpp"
#include "MateriaSource.hpp"

bool	debugOn = false;
bool	warningOn = true;
bool	successOn = true;

void	debugMsg(std::string msg)
{
	if (debugOn)
		std::cout << msg << std::endl;
}

void	warningMsg(std::string msg)
{
	if (warningOn)
		std::cout << msg << std::endl;
}

void	successMsg(std::string msg)
{
	if (successOn)
		std::cout << msg << std::endl;
}

void	subjectTests(void)
{
	IMateriaSource* src = new MateriaSource();
	src->learnMateria(new Ice());
	src->learnMateria(new Cure());
	ICharacter* me = new Character("me");
	AMateria* tmp;
	tmp = src->createMateria("ice");
	me->equip(tmp);
	tmp = src->createMateria("cure");
	me->equip(tmp);
	ICharacter* bob = new Character("bob");
	me->use(0, *bob);
	me->use(1, *bob);
	delete bob;
	delete me;
	delete src;
}

void	modifiedSubjectTests(void)
{
	IMateriaSource* src = new MateriaSource();
	src->learnMateria(new Ice());
	src->learnMateria(new Cure());
	src->learnMateria(new Ice());
	src->learnMateria(new Ice());
	src->learnMateria(new Ice());
	ICharacter* me = new Character("me");
	AMateria* tmp;
	tmp = src->createMateria("ice");
	me->equip(tmp);
	tmp = src->createMateria("cure");
	me->equip(tmp);
	tmp = src->createMateria("ice");
	me->equip(tmp);
	tmp = src->createMateria("ice");
	me->equip(tmp);
	tmp = src->createMateria("ice");
	me->equip(tmp);
	tmp = src->createMateria("random");
	ICharacter* bob = new Character("bob");
	me->use(0, *bob);
	me->use(1, *bob);
	me->use(5, *bob);
	me->unequip(-1);
	me->unequip(0);
	me->unequip(1);
	me->unequip(2);
	me->unequip(3);
	me->unequip(4);
	AMateria::cleanFloor();
	delete bob;
	delete me;
	delete src;
}
void	useCharacterPtr(void)
{
	AMateria* tmp;
	IMateriaSource* src = new MateriaSource();
	src->learnMateria(new Ice());
	src->learnMateria(new Cure());
	Character *you = new Character("you");
	tmp = src->createMateria("ice");
	you->equip(tmp);
	tmp = src->createMateria("cure");
	you->equip(tmp);
	tmp = src->createMateria("ice");
	you->equip(tmp);
	tmp = src->createMateria("ice");
	you->equip(tmp);
	you->printMateria();
	delete you;
	delete src;
}

int	main(void)
{
	subjectTests();
	modifiedSubjectTests();
	useCharacterPtr();
	return (EXIT_SUCCESS);
}