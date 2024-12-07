/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lschrafs <lschrafs@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/06 11:25:09 by lschrafs          #+#    #+#             */
/*   Updated: 2022/10/07 10:05:43 by lschrafs         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AForm.hpp"

// Constructors

AForm::AForm() : name_(""), signed_(false), grade_sign_(1), grade_execute_(1) {}

AForm::AForm(std::string name, int grade_for_signing, int grade_for_execution)
    : name_(name),
      signed_(false),
      grade_sign_(grade_for_signing),
      grade_execute_(grade_for_execution) {
  if (grade_for_signing > 150 || grade_for_execution > 150) {
    this->~AForm();
    throw GradeTooLowException();
  }
  if (grade_for_signing < 1 || grade_for_execution < 1) {
    this->~AForm();
    throw GradeTooHighException();
  }
}

AForm::AForm(const AForm &copy)
    : name_(copy.getName()),
      signed_(copy.getSignedStatus()),
      grade_sign_(copy.getGradeSign()),
      grade_execute_(copy.getGradeExecute()) {}

// Destructor
AForm::~AForm() {}

// Getters & Setters
bool AForm::getSignedStatus() const { return this->signed_; }

std::string AForm::getName() const { return this->name_; }

int AForm::getGradeSign() const { return this->grade_sign_; }

int AForm::getGradeExecute() const { return this->grade_execute_; }

// Functions
void AForm::beSigned(const Bureaucrat &bureaucrat) {
  if (this->grade_sign_ < bureaucrat.getGrade()) throw GradeTooLowException();
  this->signed_ = true;
}

// Exceptions
const char *AForm::GradeTooHighException::what() const throw() {
  return "grade is too high!";
}

const char *AForm::GradeTooLowException::what() const throw() {
  return "grade is too low!";
}

const char *AForm::FormNotSigned::what() const throw() {
  return "form is not signed!";
}

std::ostream &operator<<(std::ostream &out, const AForm& form) {
  out << "Name: " << form.getName() << std::endl
			<< "Signed: " << (form.getSignedStatus() ? "yes" : "no") << std::endl
			<< "Grade required for signing: " << form.getGradeSign() << std::endl
			<< "Grade required for executing: " << form.getGradeExecute() << std::endl; 
  return out;
}