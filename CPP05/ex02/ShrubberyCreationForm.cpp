#include "ShrubberyCreationForm.hpp"

ShrubberyCreationForm::ShrubberyCreationForm(void): AForm("Unknown", 145, 137)
{
	debugMsg(YELLOW "ShrubberyCreationForm default constructor called" RESET);
}

ShrubberyCreationForm::ShrubberyCreationForm(std::string name): AForm(name, 145, 137)
{
	debugMsg(YELLOW "ShrubberyCreationForm string constructor called" RESET);
}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm &obj): AForm(obj.getName(), obj.getGradeToSign(), obj.getGradeToExecute())
{
	debugMsg(YELLOW "ShrubberyCreationForm copy constructor called" RESET);
}

ShrubberyCreationForm::~ShrubberyCreationForm(void)
{
	debugMsg(YELLOW "ShrubberyCreationForm destructor called" RESET);
}

ShrubberyCreationForm	&ShrubberyCreationForm::operator=(const ShrubberyCreationForm &obj)
{
	debugMsg(YELLOW "ShrubberyCreationForm copy assignment operator called" RESET);
	if (this != &obj)
	{
		// _signed = obj.getSignStatus(); // impossible becuase private?
	}
	return (*this);
}
const char	*ShrubberyCreationForm::FileNotOpenedException::what(void) const throw()
{
	return YELLOW "File not opened" RESET;
}

void	ShrubberyCreationForm::executeAction(void) const
{
	std::ofstream	outFile(getName() + "_shrubbery",  std::ios::out | std::ios::trunc);
	if (!outFile.is_open())
	{
		throw FileNotOpenedException();
	}
	outFile << "    *" << std::endl;
	outFile << "   ***" << std::endl;
	outFile << "  *****" << std::endl;
	outFile << " *******" << std::endl;
	outFile << "*********" << std::endl;
	outFile << "    |" << std::endl;
	successMsg(YELLOW + getName() + "_shrubbery created" RESET);
}
