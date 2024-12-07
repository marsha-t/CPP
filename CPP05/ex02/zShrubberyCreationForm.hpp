/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.hpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lschrafs <lschrafs@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/07 10:22:25 by lschrafs          #+#    #+#             */
/*   Updated: 2022/10/07 10:37:20 by lschrafs         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SHRUBBERY_CREATION_FORM_H
#define SHRUBBERY_CREATION_FORM_H

#include "AForm.hpp"

class ShrubberyCreationForm : public AForm {
 public:
	// Constructors
	ShrubberyCreationForm(std::string target);
	ShrubberyCreationForm(const ShrubberyCreationForm &copy);

	// Destructor
	~ShrubberyCreationForm();
	
	// Functions
	virtual void execute(Bureaucrat const &executor) const;

 private:
	// Orthodox Canonical Form because of Norm
	ShrubberyCreationForm();
	ShrubberyCreationForm &operator=(const ShrubberyCreationForm &other);
};

#endif