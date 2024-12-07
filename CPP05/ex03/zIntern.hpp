/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lschrafs <lschrafs@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/07 11:39:14 by lschrafs          #+#    #+#             */
/*   Updated: 2022/10/07 14:21:05 by lschrafs         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INTERN_H
#define INTERN_H

#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"

class Intern {
 public:
	// Constructors
	Intern();
	Intern(const Intern &copy);

	// Destructor
	~Intern();

	// Overloads
	Intern &operator=(const Intern &other);

	// Functions
	AForm *makeForm(const std::string &name, const std::string &target);

 private:
 	typedef AForm* (*form_function)(std::string const & target);
	typedef struct { std::string description; form_function function; } form_pair;
};

#endif