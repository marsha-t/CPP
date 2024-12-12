#include "RobotomyRequestForm.hpp"

RobotomyRequestForm::RobotomyRequestForm(void): AForm("Unknown", 72, 45)
{
	debugMsg(PURPLE "RobotomyCreationForm default constructor called" RESET);
}

RobotomyRequestForm::RobotomyRequestForm(std::string name): AForm(name, 72, 45)
{
	debugMsg(PURPLE "RobotomyCreationForm string constructor called" RESET);
}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm &obj): AForm(obj)
{
	debugMsg(PURPLE "RobotomyCreationForm copy constructor called" RESET);
}

RobotomyRequestForm::~RobotomyRequestForm(void)
{
	debugMsg(PURPLE "RobotomyCreationForm destructor called" RESET);
}

RobotomyRequestForm	&RobotomyRequestForm::operator=(const RobotomyRequestForm &obj)
{
	debugMsg(PURPLE "RobotomyCreationForm copy assignment operator called" RESET);
	warningMsg(PURPLE "Copy assignment operator only returns original object");
	(void)obj;
	return (*this);
}

void	RobotomyRequestForm::executeAction(void) const
{
	std::srand(std::time(0));
	if (std::rand() % 2 == 0)
	{
		std::cout << PURPLE << getName() << " was robotomized" RESET << std::endl;
	}
	else
	{
		std::cout << PURPLE << getName() << " failed to get robotomized" RESET << std::endl;
	}
}
