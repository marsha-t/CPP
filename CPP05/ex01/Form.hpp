#ifndef FORM_HPP
#define FORM_HPP

#include <string>

class Bureaucrat;

class Form
{
	private:
		const std::string	_name;
		bool				_signed;
		const unsigned int	_gradeToSign;
		const unsigned int	_gradeToExecute;
	public:
		// Constructors
		Form(void);
		Form(std::string name, unsigned int gradeToSign, unsigned int gradeToExecute);
		Form(const Form &obj);

		// Destructor
		~Form(void);

		// Operator
		Form &operator=(const Form &obj);
		
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
		// Other Functions
		void	beSigned(const Bureaucrat &signer);
};

std::ostream &operator<<(std::ostream &out, const Form &obj);

#endif