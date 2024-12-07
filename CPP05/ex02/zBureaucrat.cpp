/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lschrafs <lschrafs@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/06 09:43:43 by lschrafs          #+#    #+#             */
/*   Updated: 2022/10/07 10:39:52 by lschrafs         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

// Constructors
Bureaucrat::Bureaucrat() {}

Bureaucrat::Bureaucrat(std::string name, int grade) : name_(name) {
  if (grade < 1) throw GradeTooHighException();
  if (grade > 150) throw GradeTooLowException();
  this->grade_ = grade;
}

Bureaucrat::Bureaucrat(const Bureaucrat &copy) : name_(copy.getName()) {
  this->grade_ = copy.getGrade();
}

// Destructor
Bureaucrat::~Bureaucrat() {}

// Operators
Bureaucrat &Bureaucrat::operator=(const Bureaucrat &) { return *this; }

// Getters & Setters
std::string Bureaucrat::getName(void) const { return this->name_; }

int Bureaucrat::getGrade(void) const { return this->grade_; }

void Bureaucrat::setGrade(int grade) {
  if (grade < 1) throw GradeTooHighException();
  if (grade > 150) throw GradeTooLowException();
  this->grade_ = grade;
}

// Functions
void Bureaucrat::incrementGrade(void) {
  if (this->grade_ == 1) throw GradeTooHighException();
  this->grade_--;
  std::cout << this->name_ << "was promoted to grade " << this->grade_
            << std::endl;
}

void Bureaucrat::decrementGrade(void) {
  if (this->grade_ == 150) throw GradeTooLowException();
  this->grade_++;
  std::cout << this->name_ << "was demoted to grade " << this->grade_
            << std::endl;
}

void Bureaucrat::signForm(AForm &form) {
  try {
    form.beSigned(*this);
  } catch (std::exception &e) {
    std::cout << this->name_ << " couldn't sign " << form.getName()
              << " because " << e.what() << std::endl;
    return;
  }
	std::cout << this->name_ << " signed " << form.getName() << std::endl;
}

void Bureaucrat::executeForm(AForm const &form) {
	try {
    form.execute(*this);
  } catch (std::exception &e) {
    std::cout << this->name_ << " couldn't execute " << form.getName()
              << " because " << e.what() << std::endl;
    return;
  }
	std::cout << this->name_ << " executed " << form.getName() << std::endl;
}

std::ostream &operator<<(std::ostream &out, const Bureaucrat &b) {
  out << b.getName() << ", bureaucrat grade " << b.getGrade() << ".";
  return out;
}

const char *Bureaucrat::GradeTooHighException::what() const throw() {
  return "Grade too high!";
}

const char *Bureaucrat::GradeTooLowException::what() const throw() {
  return "Grade too low!";
}
