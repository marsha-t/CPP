/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.hpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lschrafs <lschrafs@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/07 10:22:47 by lschrafs          #+#    #+#             */
/*   Updated: 2022/10/07 11:07:52 by lschrafs         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ROBOTOMY_REQUEST_FORM_H
#define ROBOTOMY_REQUEST_FORM_H

#include "AForm.hpp"

class RobotomyRequestForm : public AForm {
 public:
	// Constructors
	RobotomyRequestForm(std::string target);
	RobotomyRequestForm(const RobotomyRequestForm &copy);

	// Destructor
	~RobotomyRequestForm();
	
	// Functions
	virtual void execute(Bureaucrat const &executor) const;

 private:
	// Orthodox Canonical Form because of Norm
	RobotomyRequestForm();
	RobotomyRequestForm &operator=(const RobotomyRequestForm &other);
};

#endif