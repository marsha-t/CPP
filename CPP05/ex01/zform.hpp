
#ifndef FORM_H
#define FORM_H

#include "Bureaucrat.hpp"

class Bureaucrat;

class Form {
 public:
	// Constructors
	Form(std::string name, int grade_for_signing, int grade_for_execution);
	Form(const Form &copy);

	// Destructor
	~Form();

	// Getters & Setters
	bool getSignedStatus() const;
	std::string getName() const;
	int getGradeSign() const;
	int getGradeExecute() const;

	// Functions
	void beSigned(const Bureaucrat &bureaucrat);

	// Exceptions
	class GradeTooHighException : public std::exception {
	 public:
		virtual const char *what() const throw();
	};
	
  class GradeTooLowException: public std::exception {
	 public:
		virtual const char *what() const throw();
	};

 private:
	Form();
	Form &operator=(const Form &);
	
	const std::string name_;
	bool signed_;
	const int grade_sign_;
	const int grade_execute_;
};

std::ostream& operator<<(std::ostream& out, const Form& form);

#endif