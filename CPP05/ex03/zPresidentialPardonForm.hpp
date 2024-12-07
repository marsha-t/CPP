/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.hpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lschrafs <lschrafs@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/07 10:23:01 by lschrafs          #+#    #+#             */
/*   Updated: 2022/10/07 14:17:50 by lschrafs         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PRESIDENTIAL_PARDON_FORM_H
#define PRESIDENTIAL_PARDON_FORM_H

#include "AForm.hpp"

class PresidentialPardonForm : public AForm {
 public:
	// Constructors
	PresidentialPardonForm(const std::string &target);
	PresidentialPardonForm(const PresidentialPardonForm &copy);

	// Destructor
	~PresidentialPardonForm();
	
	// Functions
	virtual void execute(Bureaucrat const &executor) const;

 private:
	// Orthodox Canonical Form because of Norm
	PresidentialPardonForm();
	PresidentialPardonForm &operator=(const PresidentialPardonForm &other);
};

#endif