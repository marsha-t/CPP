#include "Intern.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

Intern::Intern(void)
{
	debugMsg(CYAN "Intern default constructor called" RESET);
	successMsg(CYAN "Let me know which form you want: shrubbery creation, robotomy request or presidential pardon" RESET);
}

Intern::Intern(const Intern &obj)
{
	debugMsg(CYAN "Intern copy constructor called" RESET);
	(void)obj;
}

Intern::~Intern(void)
{
	debugMsg(CYAN "Intern destructor called" RESET);
}

Intern	&Intern::operator=(const Intern &obj)
{
	debugMsg(CYAN "Intern copy assignment operator called" RESET);
	(void)obj;
	return (*this);
}

AForm	*Intern::makeForm(std::string name, std::string target) const
{
	std::string	formNames[3] = {"shrubbery creation", "robotomy request", "presidential pardon"};
	int	i = 0;
	while (name != formNames[i] && i < 3)
		i++;
	switch (i)
	{
		case 0:
		{
			successMsg(CYAN "Intern creates ShrubberyCreationForm" RESET);
			return (new ShrubberyCreationForm(target));
		}
		case 1:
		{
			successMsg(CYAN "Intern creates RobotomyRequestForm" RESET);
			return (new RobotomyRequestForm(target));
		}
		case 2:
		{
			successMsg(CYAN "Intern creates PresidentialPardonForm" RESET);
			return (new PresidentialPardonForm(target));
		}
		default:
		{
			warningMsg(CYAN "Intern is confused" RESET);
			return (NULL);
		}
	}
}
