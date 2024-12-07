/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lschrafs <lschrafs@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/07 11:44:07 by lschrafs          #+#    #+#             */
/*   Updated: 2022/10/07 14:27:53 by lschrafs         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Intern.hpp"

// Constructors
Intern::Intern() {}

Intern::Intern(const Intern &copy) { (void)copy; }

// Destructor
Intern::~Intern() {}

// Overloads
Intern &Intern::operator=(const Intern &other) {
  (void)other;
  return *this;
}

// Functions

static AForm*	createPresidentialPardonForm(const std::string &target) { return (new PresidentialPardonForm(target)); }
static AForm*	createRobotomyRequestForm(const std::string &target) { return (new RobotomyRequestForm(target)); }
static AForm*	createShrubberyCreationForm(const std::string &target) { return (new ShrubberyCreationForm(target)); }

AForm *Intern::makeForm(const std::string &name, const std::string &target) {
  form_pair form_table[3] = {
		{ "presidential pardon", &createPresidentialPardonForm },
		{ "robotomy request", &createRobotomyRequestForm },
		{ "shrubbery creation", &createShrubberyCreationForm }
	};
	
	for (int i = 0; i < 3; i++) {
		if (form_table[i].description == name) {
			std::cout << "Intern creates " << name << std::endl;
			return (form_table[i].function(target));
		}
	}
	std::cout << "Intern couldn't create " << name << std::endl;
	return NULL;
}