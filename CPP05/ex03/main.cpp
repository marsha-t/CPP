#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "Intern.hpp"

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

void	testIntern(void)
{
	Intern	*newIntern = new Intern();
	AForm	*SCF = newIntern->makeForm("shrubbery creation", "Shrub");
	AForm	*RRF = newIntern->makeForm("robotomy request", "Robot");
	AForm	*PPF = newIntern->makeForm("presidential pardon", "Criminal");
	AForm	*random = newIntern->makeForm("random", "Random");

	std::cout << *SCF << std::endl;
	std::cout << *RRF << std::endl;
	std::cout << *PPF << std::endl;
	if (!random)
		std::cout << "Null" << std::endl;

	delete newIntern;
	delete SCF;
	delete RRF;
	delete PPF;
}

int	main(void)
{
	testIntern();
	return (EXIT_SUCCESS);
}