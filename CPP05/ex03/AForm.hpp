#ifndef AFORM_HPP
#define AFORM_HPP

#include <string>
#include <iostream>

# define RESET "\033[0m"
# define GREEN "\033[32m"

class Bureaucrat;

// Utility functions
void	debugMsg(std::string msg);
void	warningMsg(std::string msg);
void	successMsg(std::string msg);

class AForm
{
	private:
		const std::string	_name;
		bool				_signed;
		const unsigned int	_gradeToSign;
		const unsigned int	_gradeToExecute;
	public:
		// Constructors
		AForm(void);
		AForm(std::string name, unsigned int gradeToSign, unsigned int gradeToExecute);
		AForm(const AForm &obj);

		// Destructor
		virtual ~AForm(void);

		// Operator
		AForm &operator=(const AForm &obj);
		
		// Getters
		const std::string 	&getName(void) const;
		bool				getSignStatus(void) const;
		unsigned int	getGradeToSign(void) const;
		unsigned int	getGradeToExecute(void) const;
		
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
		class UnsignedForm: public std::exception
		{
			public:
				virtual const char	*what(void) const throw();
		};
		// Other Functions
		virtual void	beSigned(const Bureaucrat &signer);
		void	execute(Bureaucrat const &executor) const;

	protected:
		virtual void	executeAction(void) const = 0;

};

std::ostream &operator<<(std::ostream &out, const AForm &obj);

#endif