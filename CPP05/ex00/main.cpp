#include "Bureaucrat.hpp"

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

void	testConstruction(void)
{
	try
	{
		Bureaucrat b1("testGrade0", 0);
	}
	catch (std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}
	try
	{
		Bureaucrat b1("testGrade151", 151);
	}
	catch (std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}
}

void	testCopy(void)
{
	Bureaucrat original("original", 80);
	Bureaucrat replace("replace", 30);
	std::cout << original << std::endl;
	std::cout << replace << std::endl;

	original = replace;
	std::cout << original << std::endl;
	std::cout << replace << std::endl;
}

void	testDowngrade(void)
{
	std::cout << "--------- Test downgrade ---------" << std::endl;
	Bureaucrat b1("staff", 149);
	std::cout << "Original grade: " << b1.getGrade() << std::endl;
	b1.downgrade();
	std::cout << "Grade after 1st downgrade: " << b1.getGrade() << std::endl;
	try
	{
		b1.downgrade();
	}
	catch (std::exception &e)
	{
		std::cout << e.what() << std::endl;
		std::cout << "Grade after 2nd downgrade: " << b1.getGrade() << std::endl;
	}
}

void	testUpgrade(void)
{
	std::cout << "--------- Test upgrade ---------" << std::endl;
	Bureaucrat b2("boss", 2);
	std::cout << "Original grade: " << b2.getGrade() << std::endl;
	b2.upgrade();
	std::cout << "Grade after 1st upgrade: " << b2.getGrade() << std::endl;
	try
	{
		b2.upgrade();
		
	}
	catch (std::exception &e)
	{
		std::cout << e.what() << std::endl;
		std::cout << "Grade after 2nd upgrade: " << b2.getGrade() << std::endl;
	}
}

int	main(void)
{
	testConstruction();
	testCopy();
	testDowngrade();
	testUpgrade();
	return (EXIT_SUCCESS);	
}