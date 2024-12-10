#include "AForm.hpp"
#include "Bureaucrat.hpp"

AForm::AForm(void): _name("Unknown"), _signed(false), _gradeToSign(1), _gradeToExecute(1)
{
	debugMsg(GREEN "AForm default constructor called" RESET);
}
AForm::AForm(std::string name, unsigned int gradeToSign, unsigned int gradeToExecute): 
	_name(name), _signed(false), _gradeToSign(gradeToSign), _gradeToExecute(gradeToExecute)
{
	debugMsg(GREEN "AForm parameterised constructor called" RESET);
	if (gradeToSign < 1 || gradeToExecute < 1)
		throw GradeTooHighException();
	else if (gradeToSign > 150 || gradeToExecute > 150)
		throw GradeTooLowException();
}

AForm::AForm(const AForm &obj): \
	_name(obj.getName()), _signed(obj.getSignStatus()), _gradeToSign(obj.getGradeToSign()), _gradeToExecute(obj.getGradeToExecute())
{
	debugMsg(GREEN "AForm copy constructor called" RESET);
}

AForm::~AForm(void)
{
	debugMsg(GREEN "AForm destructor called" RESET);
}

AForm	&AForm::operator=(const AForm &obj)
{
	debugMsg(GREEN "AForm copy assignment operator called" RESET);
	if (this != &obj)
	{
		_signed = obj.getSignStatus();
	}
	return (*this);
}

const std::string 	&AForm::getName(void) const
{
	return (_name);
}
bool				AForm::getSignStatus(void) const
{
	return (_signed);
}
unsigned int	AForm::getGradeToSign(void) const
{
	return (_gradeToSign);
}
unsigned int	AForm::getGradeToExecute(void) const
{
	return (_gradeToExecute);
}

const char *AForm::GradeTooHighException::what(void) const throw()
{
	return GREEN "Grade is too high" RESET;
}

const char *AForm::GradeTooLowException::what(void) const throw()
{
	return GREEN "Grade is too low" RESET;
}

const char	*AForm::UnsignedForm::what(void) const throw()
{
	return GREEN "Form is unsigned" RESET;
}

void	AForm::beSigned(const Bureaucrat &signer)
{
	if (_signed == true)
		std::cout << GREEN "AForm is already signed" RESET << std::endl;
	else if (signer.getGrade() <= _gradeToSign)
	{
		_signed = true;
		std::cout << GREEN "AForm is signed!" RESET << std::endl;
	}
	else
	{
		throw GradeTooLowException();
	}
}

std::ostream &operator<<(std::ostream &out, const AForm &obj)
{
	out << GREEN << obj.getName() << " requires grade " << obj.getGradeToSign() << 
		" to sign and grade " << obj.getGradeToExecute() << " to execute and it is " << std::flush;
	if (obj.getSignStatus())
		out << "signed" << RESET << std::flush;
	else
		out << "not signed" << RESET << std::flush;
	return (out);
}

void	AForm::execute(Bureaucrat const &executor) const
{
	if (!getSignStatus())
		throw UnsignedForm();
	if (executor.getGrade() > getGradeToExecute())
		throw GradeTooLowException();
	executeAction();
}
