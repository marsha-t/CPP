#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

bool	debugOn = false;
bool	successOn = true;
bool	warningOn = true;

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

void	testShrubberyCreationForm(void)
{
	AForm	*shrub = new ShrubberyCreationForm("Shrub");
	Bureaucrat	*signer = new Bureaucrat("Signer", 145);
	signer->executeForm(*shrub);
	shrub->beSigned(*signer);
	Bureaucrat	*executor = new Bureaucrat("Executor", 138);
	try
	{
		shrub->execute(*executor);
	}
	catch (std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}
	executor->executeForm(*shrub);
	executor->upgrade();
	shrub->execute(*executor);
	executor->executeForm(*shrub);
	delete shrub;
	delete signer;
	delete executor;
}

void	testRobotomyRequestForm(void)
{
	AForm	*robot = new RobotomyRequestForm("Robot");
	Bureaucrat	*signer = new Bureaucrat("Signer", 72);
	signer->executeForm(*robot);
	robot->beSigned(*signer);
	Bureaucrat	*executor = new Bureaucrat("Executor", 46);
	try
	{
		robot->execute(*executor);
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << std::endl;
	}
	executor->executeForm(*robot);
	executor->upgrade();
	robot->execute(*executor);
	executor->executeForm(*robot);
	delete robot;
	delete signer;
	delete executor;
}

void	testPresidentialPardonForm(void)
{
	AForm	*criminal = new PresidentialPardonForm("Criminal");
	Bureaucrat	*signer = new Bureaucrat("Signer", 25);
	signer->executeForm(*criminal);
	criminal->beSigned(*signer);
	Bureaucrat	*executor = new Bureaucrat("Executor", 6);
	try
	{
		criminal->execute(*executor);
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << std::endl;
	}
	executor->executeForm(*criminal);
	executor->upgrade();
	criminal->execute(*executor);
	executor->executeForm(*criminal);
	delete criminal;
	delete signer;
	delete executor;
}

int	main(void)
{
	testShrubberyCreationForm();
	testRobotomyRequestForm();
	testPresidentialPardonForm();
	return (EXIT_SUCCESS);
}