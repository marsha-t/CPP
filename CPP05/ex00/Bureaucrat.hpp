#ifndef BUREAUCRAT_HPP
#define BUREAUCRAT_HPP

#include <stdexcept>
#include <string>
#include <iostream>
#include <cstdlib>

// Utility functions
void	debugMsg(std::string msg);
void	warningMsg(std::string msg);

class Bureaucrat
{
	private:
		const std::string _name;
		unsigned int _grade;
	
	public:
		// Constructors
		Bureaucrat(void);
		Bureaucrat(const std::string &name, unsigned int grade);
		Bureaucrat(const Bureaucrat &obj);

		// Destructor
		~Bureaucrat(void);

		// Operator
		Bureaucrat &operator=(const Bureaucrat &obj);

		// Getters
		const std::string &getName(void) const;
		unsigned int	getGrade(void) const;

		// Exception classes
		class GradeTooHighException: public std::exception
		{
			public:
				virtual const char *what(void) const throw();
		};
		class GradeTooLowException: public std::exception
		{
			public:
				virtual const char *what(void) const throw();
		};

		// Other functions
		void	downgrade(void);
		void	upgrade(void);
};

std::ostream &operator<<(std::ostream &out, Bureaucrat const &obj);

#endif