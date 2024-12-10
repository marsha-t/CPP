#include "Bureaucrat.hpp"
#include "AForm.hpp"

Bureaucrat::Bureaucrat(void): _name("Nameless"), _grade(150)
{
	debugMsg(RED "Bureaucrat default constructor called" RESET);
}

Bureaucrat::Bureaucrat(const std::string &name, unsigned int grade): _name(name), _grade(grade)
{
	debugMsg(RED "Bureaucrat string constructor called for " + name + RESET);
	if (grade < 1)
		throw GradeTooHighException();
	else if (grade > 150)
		throw GradeTooLowException();
}

Bureaucrat::Bureaucrat(const Bureaucrat &obj): _name(obj.getName()), _grade(obj.getGrade())
{
	debugMsg(RED "Bureaucrat copy constructor called" RESET);
}

Bureaucrat::~Bureaucrat(void)
{
	debugMsg(RED "Bureaucrat destructor called for " + _name + RESET);
}

Bureaucrat &Bureaucrat::operator=(const Bureaucrat &obj)
{
	debugMsg(RED "Bureaucrat copy assignment operator called" RESET);
	if (this != &obj)
	{
		_grade = obj.getGrade();
	}
	return (*this);
}

const std::string &Bureaucrat::getName(void) const
{
	return (_name);
}

unsigned int	Bureaucrat::getGrade(void) const
{
	return (_grade);
}

const char *Bureaucrat::GradeTooHighException::what(void) const throw()
{
	return RED "Grade is too high" RESET;
}


const char *Bureaucrat::GradeTooLowException::what(void) const throw()
{
	return RED "Grade is too low" RESET;
}

void	Bureaucrat::downgrade(void)
{
	if (_grade == 150)
		throw GradeTooLowException();
	_grade++;
}

void	Bureaucrat::upgrade(void)
{
	if (_grade == 1)
		throw GradeTooHighException();
	_grade--;
}

void	Bureaucrat::signForm(const AForm &form) const
{
	if (form.getSignStatus())
	{
		std::cout << RED "Form is already signed" RESET << std::endl;
	}
	else if (_grade <= form.getGradeToSign())
	{
		std::cout << RED << _name << " signed " << form.getName() << RESET << std::endl;
	}
	else
	{
		std::cout << RED << _name << " couldn't sign " << form.getName() << " because his/her grade is not high enough" << RESET << std::endl;
	}
}

std::ostream &operator<<(std::ostream &out, Bureaucrat const &obj)
{
	out << RED << obj.getName() << ", bureaucrat grade " << obj.getGrade() << RESET << std::flush;
	return (out);
}