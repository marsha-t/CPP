#include "ShrubberyCreationForm.hpp"

ShrubberyCreationForm::ShrubberyCreationForm(void): AForm("Unknown", 145, 137)
{
	debugMsg("ShrubberyCreationForm default constructor called");
}

ShrubberyCreationForm::ShrubberyCreationForm(std::string name): AForm(name, 145, 137)
{
	debugMsg("ShrubberyCreationForm string constructor called");
}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm &obj): AForm(obj.getName(), obj.getGradeToSign(), obj.getGradeToExecute())
{
	debugMsg("ShrubberyCreationForm copy constructor called");
}

ShrubberyCreationForm::~ShrubberyCreationForm(void)
{
	debugMsg("ShrubberyCreationForm destructor called");
}

ShrubberyCreationForm	&ShrubberyCreationForm::operator=(const ShrubberyCreationForm &obj)
{
	debugMsg("ShrubberyCreationForm copy assignment operator called");
	if (this != &obj)
	{
		_signed = obj.getSignStatus(); // impossible becuase private?
	}
	return (*this);
}

void	ShrubberyCreationForm::executeAction(void) const
{
	std::ofstream	outFile();

}


std::ofstream	output_file(input[3].c_str(), std::ios::out | std::ios::trunc);
	if (!output_file.is_open())
	{
		input_file.close();
		std::cerr << "Error opening " << input[0] << std::endl;
		return (EXIT_FAILURE);
	}