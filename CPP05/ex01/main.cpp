#include "Bureaucrat.hpp"
#include "Form.hpp"

bool	debugOn = false;

void	debugMsg(std::string msg)
{
	if (debugOn)
		std::cout << msg << std::endl;
}

void	testConstruction()
{
	try
	{
		Form	form1("form1", 0, 1);
	}
	catch (std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}
	try
	{
		Form	form1("form1", 1, 0);
	}
	catch (std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}
	try
	{
		Form	form1("form1", 151, 1);
	}
	catch (std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}
	try
	{
		Form	form1("form1", 1, 151);
	}
	catch (std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}
}

void	testSignature(void)
{
	Form	form1("Form1", 5, 5);
	Bureaucrat	staff("Staff", 6);

	std::cout << form1 << std::endl;
	std::cout << staff << std::endl;
	try
	{
		staff.signForm(form1);
	}
	catch (std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}
	try
	{
		form1.beSigned(staff);
	}
	catch (std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}
	staff.upgrade();
	std::cout << staff << std::endl;
	staff.signForm(form1);
	form1.beSigned(staff);
	std::cout << form1 << std::endl;
	staff.signForm(form1);
	form1.beSigned(staff);
}

int	main(void)
{
	testConstruction();
	testSignature();
	return (EXIT_SUCCESS);	
}