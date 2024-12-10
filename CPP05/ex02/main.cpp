#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"

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
	executor->upgrade();
	shrub->execute(*executor);
	delete shrub;
	delete signer;
	delete executor;
}

int	main(void)
{
	testShrubberyCreationForm();
	return (EXIT_SUCCESS);
}