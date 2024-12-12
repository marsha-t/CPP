#include "PresidentialPardonForm.hpp"

PresidentialPardonForm::PresidentialPardonForm(void): AForm("Unknown", 25, 5)
{
	debugMsg(BLUE "PresidentialPardonForm default constructor called " RESET);
}

PresidentialPardonForm::PresidentialPardonForm(std::string name): AForm(name, 25, 5)
{
	debugMsg(BLUE "PresidentialPardonForm string constructor called " RESET);
}

PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm &obj): AForm(obj)
{
	debugMsg(BLUE "PresidentialPardonForm copy constructor called " RESET);
}

PresidentialPardonForm::~PresidentialPardonForm(void)
{
	debugMsg(BLUE "PresidentialPardonForm destructor called " RESET);
}

PresidentialPardonForm	&PresidentialPardonForm::operator=(const PresidentialPardonForm &obj)
{
	debugMsg(BLUE "PresidentialPardonForm copy assignment operator called " RESET);
	warningMsg(BLUE "Copy assignment operator only returns original object");
	(void)obj;
	return (*this);
}

void	PresidentialPardonForm::executeAction(void) const
{
	std::cout << BLUE << getName() << " has been pardoned by Zaphod Beeblebrox" RESET << std::endl;
}