/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lschrafs <lschrafs@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/06 09:04:49 by lschrafs          #+#    #+#             */
/*   Updated: 2022/10/07 14:35:07 by lschrafs         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AForm.hpp"
#include "Bureaucrat.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "Intern.hpp"

int main(void) {
	Intern worthless_intern;
  AForm *form_shrubbery = NULL;
	AForm *form_robotomy = NULL;
	AForm *form_pardon = NULL;
	AForm *form_invalid = NULL;

	form_shrubbery = worthless_intern.makeForm("shrubbery creation", "tree");
	form_robotomy = worthless_intern.makeForm("robotomy request", "some innocent guy");
	form_pardon = worthless_intern.makeForm("presidential pardon", "Jeffrey Dahmer");
	form_invalid = worthless_intern.makeForm("world domination request", "World");

	std::cout << std::endl
						<< *form_shrubbery << std::endl
						<< *form_robotomy << std::endl
						<< *form_pardon << std::endl;
	
	if (form_invalid == NULL)
		std::cout << "Form is null" << std::endl;

	Bureaucrat michael_scott("Michael Scott", 1);
	std::cout << RED << std::endl << michael_scott << std::endl << std::endl; 
	michael_scott.signForm(*form_pardon);
	std::cout << std::endl << *form_pardon << std::endl; 
	michael_scott.executeForm(*form_pardon);

	delete form_shrubbery;
	delete form_robotomy;
	delete form_pardon;
}