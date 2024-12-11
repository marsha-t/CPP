#include "RobotomyRequestForm.hpp"

RobotomyRequestForm::RobotomyRequestForm(void): AForm("Unknown", 72, 45)
{
	debugMsg(PURPLE "RobotomyCreationForm default constructor called" RESET);
}

RobotomyRequestForm::RobotomyRequestForm(std::string name): AForm(name, 72, 45)
{
	debugMsg(PURPLE "RobotomyCreationForm string constructor called" RESET);
}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyCreationForm &obj): AForm(obj.getName(), obj.getGradeToSign(), obj.getGradeToExecute())
{
	debugMsg(PURPLE "RobotomyCreationForm copy constructor called" RESET);
}

RobotomyCreationForm::~RobotomyCreationForm(void)
{
	debugMsg(PURPLE "RobotomyCreationForm destructor called" RESET);
}

RobotomyCreationForm	&RobotomyCreationForm::operator=(const RobotomyCreationForm &obj)
{
	debugMsg(PURPLE "RobotomyCreationForm copy assignment operator called" RESET);
	warningMsg(PURPLE "Copy assignment operator only returns original object");
	(void)obj;
	return (*this);
}

void	RobotomyCreationForm::executeAction(void) const
{
	std::srand(std::time(0));
	std::cout << "current time" << std::time(0) << std::endl;
	if (std::rand() % 2 == 0)
	{
		std::cout << PURPLE << getName() << RESET << std::endl;
	}
}