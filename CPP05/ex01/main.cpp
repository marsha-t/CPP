#include "Bureaucrat.hpp"
#include "Form.hpp"

bool	debugOn = true;
bool	successOn = true;
bool	warningOn = true;

void	debugMsg(std::string msg)
{
	if (debugOn)
		std::cout << msg << std::endl;
}

void	successMsg(std::string msg)
{
	if (successOn)
		std::cout << msg << std::endl;
}

void	warningMsg(std::string msg)
{
	if (warningOn)
		std::cout << msg << std::endl;
}

void	testConstruction()
{
	Form	form1("form0", 1, 1);
	std::cout << form1 << std::endl;
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

void	testCopy(void)
{
	Form	form1("Form1", 5, 5);
	Bureaucrat	boss("Boss", 1);
	Form	form2("Form2", 10, 10);
	form1.beSigned(boss);
	std::cout << "Before:" << std::endl << form1 << std::endl << form2 << std::endl;
	form1 = form2;
	std::cout << "After:" << std::endl << form1 << std::endl << form2 << std::endl;
}

void	testSignature(void)
{
	Form	form1("Form1", 5, 5);
	Bureaucrat	staff("Staff", 6);

	std::cout << form1 << std::endl;
	std::cout << staff << std::endl;
	staff.signForm(form1);
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
	testCopy();
	testSignature();
	return (EXIT_SUCCESS);	
}