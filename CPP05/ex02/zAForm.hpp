/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lschrafs <lschrafs@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/06 11:25:14 by lschrafs          #+#    #+#             */
/*   Updated: 2022/10/06 11:52:35 by lschrafs         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AFORM_H
#define AFORM_H

#include "Bureaucrat.hpp"

class Bureaucrat;

class AForm {
 public:
	// Destructor
	virtual ~AForm();

	// Getters & Setters
	bool getSignedStatus() const;
	std::string getName() const;
	int getGradeSign() const;
	int getGradeExecute() const;

	// Functions
	void beSigned(const Bureaucrat &bureaucrat);
	virtual void execute(Bureaucrat const &executor) const = 0;

	// Exceptions
	class GradeTooHighException : public std::exception {
	 public:
		virtual const char *what() const throw();
	};
	
  class GradeTooLowException: public std::exception {
	 public:
		virtual const char *what() const throw();
	};

	class FormNotSigned : public std::exception {
	 public:
		virtual const char *what() const throw();
	};

 protected: 
	// Orthodox Canonical Form for Norm. Don't make sense for abstract classes
	AForm();
	AForm(std::string name, int grade_for_signing, int grade_for_execution);
	AForm(const AForm &copy);
	AForm &operator=(const AForm &);

 private:
	
	const std::string name_;
	bool signed_;
	const int grade_sign_;
	const int grade_execute_;
};

std::ostream& operator<<(std::ostream& out, const AForm& AForm);

#endif