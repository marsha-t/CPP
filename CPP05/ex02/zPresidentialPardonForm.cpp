/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.cpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lschrafs <lschrafs@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/07 10:23:05 by lschrafs          #+#    #+#             */
/*   Updated: 2022/10/07 11:31:37 by lschrafs         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PresidentialPardonForm.hpp"

// Constructors
PresidentialPardonForm::PresidentialPardonForm(std::string target)
    : AForm(target, 25, 5) {}

PresidentialPardonForm::PresidentialPardonForm(
    const PresidentialPardonForm &copy)
    : AForm(copy) {
  this->~PresidentialPardonForm();
  new (this) PresidentialPardonForm(copy.getName());
}

// Destructor
PresidentialPardonForm::~PresidentialPardonForm() {}

// Functions
void PresidentialPardonForm::execute(Bureaucrat const &executor) const {
	if (this->getSignedStatus() != true)
    throw FormNotSigned();
	
  if (this->getGradeExecute() < executor.getGrade())
    throw GradeTooLowException();
  std::cout << this->getName() << " has been pardoned by Zaphod Beeblebrox."
            << std::endl;
}
