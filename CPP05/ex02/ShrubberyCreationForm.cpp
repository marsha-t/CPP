#include "ShrubberyCreationForm.hpp"

ShrubberyCreationForm::ShrubberyCreationForm(void): AForm("Unknown", 145, 137)
{
	debugMsg(YELLOW "ShrubberyCreationForm default constructor called" RESET);
}

ShrubberyCreationForm::ShrubberyCreationForm(std::string name): AForm(name, 145, 137)
{
	debugMsg(YELLOW "ShrubberyCreationForm string constructor called" RESET);
}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm &obj): AForm(obj)
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
	warningMsg(YELLOW "Copy assignment operator only returns original object");
	(void)obj;
	return (*this);
}

void	ShrubberyCreationForm::executeAction(void) const
{
	std::ofstream	outFile((getName() + "_shrubbery").c_str(),  std::ios::out | std::ios::trunc);

	if (!outFile.is_open())
	{
		warningMsg(YELLOW "File not opened successfully" RESET);
		return ;
	}
	outFile << "    *" << std::endl;
	outFile << "   ***" << std::endl;
	outFile << "  *****" << std::endl;
	outFile << " *******" << std::endl;
	outFile << "*********" << std::endl;
	outFile << "    |" << std::endl;
	successMsg(YELLOW + getName() + "_shrubbery created" RESET);
}
