#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat(void): _name("Nameless"), _grade(150)
{
	debugMsg("Bureaucrat default constructor called");
}

Bureaucrat::Bureaucrat(const std::string &name, unsigned int grade): _name(name), _grade(grade)
{
	debugMsg("Bureaucrat string constructor called for " + name);
	if (grade < 1)
		throw GradeTooHighException();
	else if (grade > 150)
		throw GradeTooLowException();
}

Bureaucrat::Bureaucrat(const Bureaucrat &obj): _name(obj.getName()), _grade(obj.getGrade())
{
	debugMsg("Bureaucrat copy constructor called");
}

Bureaucrat::~Bureaucrat(void)
{
	debugMsg("Bureaucrat destructor called for " + _name);
}

Bureaucrat &Bureaucrat::operator=(const Bureaucrat &obj)
{
	debugMsg("Bureaucrat copy assignment operator called");
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
	return "Grade is too high";
}

const char *Bureaucrat::GradeTooLowException::what(void) const throw()
{
	return "Grade is too low";
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

std::ostream &operator<<(std::ostream &out, Bureaucrat const &obj)
{
	out << obj.getName() << ", bureaucrat grade " << obj.getGrade() << std::flush;
	return (out);
}