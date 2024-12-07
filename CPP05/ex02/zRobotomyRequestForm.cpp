/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.cpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lschrafs <lschrafs@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/07 10:22:42 by lschrafs          #+#    #+#             */
/*   Updated: 2022/10/07 11:31:26 by lschrafs         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RobotomyRequestForm.hpp"

// Constructors
RobotomyRequestForm::RobotomyRequestForm(std::string target)
    : AForm(target, 72, 45) {}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm &copy)
    : AForm(copy) {
  this->~RobotomyRequestForm();
  new (this) RobotomyRequestForm(copy.getName());
}

// Destructor
RobotomyRequestForm::~RobotomyRequestForm() {}

// Functions
void RobotomyRequestForm::execute(Bureaucrat const &executor) const {
	if (this->getSignedStatus() != true)
    throw FormNotSigned();

  if (this->getGradeExecute() < executor.getGrade())
    throw GradeTooLowException();
  std::cout << "* Drilling noises *" << std::endl
            << this->getName()
            << " has been successfully robotomized 50% of the time!"
            << std::endl;
}
