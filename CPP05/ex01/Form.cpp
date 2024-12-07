#include "Form.hpp"
#include "Bureaucrat.hpp"

Form::Form(void): _name("Unknown"), _signed(false), _gradeToSign(1), _gradeToExecute(1)
{
	debugMsg("Form default constructor called");
}
Form::Form(std::string name, unsigned int gradeToSign, unsigned int gradeToExecute): 
	_name(name), _signed(false), _gradeToSign(gradeToSign), _gradeToExecute(gradeToExecute)
{
	debugMsg("Form parameterised constructor called");
}

Form::Form(const Form &obj): \
	_name(obj.getName()), _signed(obj.getSignStatus()), _gradeToSign(obj.getGradeToSign()), _gradeToExecute(obj.getGradeToExecute())
{
	debugMsg("Form copy constructor called");
}

Form::~Form(void)
{
	debugMsg("Form destructor called");
}

Form	&Form::operator=(const Form &obj)
{
	debugMsg("Form copy assignment operator called");
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
const unsigned int	Form::getGradeToSign(void) const
{
	return (_gradeToSign);
}
const unsigned int	Form::getGradeToExecute(void) const
{
	return (_gradeToExecute);
}

const char *Form::GradeTooHighException::what(void) const throw()
{
	return ("Grade is too high");
}

const char *Form::GradeTooLowException::what(void) const throw()
{
	return ("Grade is too low");
}

void	Form::beSigned(const Bureaucrat &signer)
{
	if (_signed = true)
		std::cout << "Form is already signed" << std::endl;
	else if (signer.getGrade() <= _gradeToSign)
	{
		_signed = true;
		std::cout << "Form is signed!" << std::endl;
	}
	else
	{
		throw GradeTooLowException();
	}
}
