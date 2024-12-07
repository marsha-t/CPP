/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lschrafs <lschrafs@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/07 10:22:29 by lschrafs          #+#    #+#             */
/*   Updated: 2022/10/07 11:16:28 by lschrafs         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ShrubberyCreationForm.hpp"
#include <fstream>

// Constructors
ShrubberyCreationForm::ShrubberyCreationForm(std::string target)
    : AForm(target, 145, 137) {}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm &copy)
    : AForm(copy) {
  this->~ShrubberyCreationForm();
  new (this) ShrubberyCreationForm(copy.getName());
}

// Destructor
ShrubberyCreationForm::~ShrubberyCreationForm() {}

// Functions
void ShrubberyCreationForm::execute(Bureaucrat const &executor) const {
	if (this->getSignedStatus() != true)
    throw FormNotSigned();
	
  if (this->getGradeExecute() < executor.getGrade())
    throw GradeTooLowException();

  std::ofstream outfile;
  outfile.open(this->getName() + (std::string) "_shrubbery");
  outfile

      << "               ,@@@@@@@," << std::endl
      << "       ,,,.   ,@@@@@@/@@,  .oo8888o." << std::endl
      << "    ,&%%&%&&%,@@@@@/@@@@@@,8888\\88/8o" << std::endl
      << "   ,%&\\%&&%&&%,@@@\\@@@/@@@88\\88888/88'" << std::endl
      << "   %&&%&%&/%&&%@@\\@@/ /@@@88888\\88888'" << std::endl
      << "   %&&%/ %&%%&&@@\\ V /@@' `88\\8 `/88'" << std::endl
      << "   `&%\\ ` /%&'    |.|        \\ '|8'" << std::endl
      << "       |o|        | |         | |" << std::endl
      << "       |.|        | |         | |" << std::endl
      << "    \\/ ._\\//_/__/  ,\\_//__\\/.  \\_//__/_" << std::endl;
}
