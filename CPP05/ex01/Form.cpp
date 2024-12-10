#include "Form.hpp"
#include "Bureaucrat.hpp"

Form::Form(void): _name("Unknown"), _signed(false), _gradeToSign(1), _gradeToExecute(1)
{
	debugMsg(GREEN "Form default constructor called" RESET);
}
Form::Form(std::string name, unsigned int gradeToSign, unsigned int gradeToExecute): 
	_name(name), _signed(false), _gradeToSign(gradeToSign), _gradeToExecute(gradeToExecute)
{
	debugMsg(GREEN "Form parameterised constructor called" RESET);
	if (gradeToSign < 1 || gradeToExecute < 1)
		throw GradeTooHighException();
	else if (gradeToSign > 150 || gradeToExecute > 150)
		throw GradeTooLowException();
}

Form::Form(const Form &obj): \
	_name(obj.getName()), _signed(obj.getSignStatus()), _gradeToSign(obj.getGradeToSign()), _gradeToExecute(obj.getGradeToExecute())
{
	debugMsg(GREEN "Form copy constructor called" RESET);
}

Form::~Form(void)
{
	debugMsg(GREEN "Form destructor called" RESET);
}

Form	&Form::operator=(const Form &obj)
{
	debugMsg(GREEN "Form copy assignment operator called" RESET);
	if (this != &obj)
	{
		_signed = obj.getSignStatus();
	}
	return (*this);
}

const std::string 	&Form::getName(void) const
{
	return (_name);
}
bool				Form::getSignStatus(void) const
{
	return (_signed);
}
unsigned int	Form::getGradeToSign(void) const
{
	return (_gradeToSign);
}
unsigned int	Form::getGradeToExecute(void) const
{
	return (_gradeToExecute);
}

const char *Form::GradeTooHighException::what(void) const throw()
{
	return GREEN "Grade is too high" RESET;
}

const char *Form::GradeTooLowException::what(void) const throw()
{
	return GREEN "Grade is too low" RESET;
}

void	Form::beSigned(const Bureaucrat &signer)
{
	if (_signed == true)
		warningMsg(GREEN "Form is already signed" RESET);
		// std::cout << GREEN "Form is already signed" RESET << std::endl;
	else if (signer.getGrade() <= _gradeToSign)
	{
		_signed = true;
		successMsg(GREEN "Form is signed!" RESET);
		// std::cout << GREEN "Form is signed!" RESET << std::endl;
	}
	else
	{
		throw GradeTooLowException();
	}
}

std::ostream &operator<<(std::ostream &out, const Form &obj)
{
	out << GREEN << obj.getName() << " requires grade " << obj.getGradeToSign() << 
		" to sign and grade " << obj.getGradeToExecute() << " to execute and it is " << std::flush;
	if (obj.getSignStatus())
		out << "signed" << RESET << std::flush;
	else
		out << "not signed" << RESET << std::flush;
	return (out);
}
