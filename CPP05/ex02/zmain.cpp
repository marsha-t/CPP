/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lschrafs <lschrafs@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/06 09:04:49 by lschrafs          #+#    #+#             */
/*   Updated: 2022/10/07 11:32:49 by lschrafs         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AForm.hpp"
#include "Bureaucrat.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"

int main(void) {
  std::cout << "----- making some Bureaucrats -----" << std::endl << std::endl;

  Bureaucrat awesomeAlex("Alex", 1);
  Bureaucrat horribleHolly("Holly", 150);

  std::cout << awesomeAlex << std::endl << horribleHolly << std::endl;

  std::cout << std::endl
            << GREEN << "----- everything goes well -----" << std::endl
            << std::endl;

  ShrubberyCreationForm form_tree("Tree");
  RobotomyRequestForm form_robot("Bobby");
  PresidentialPardonForm form_pardon("Ted Bundy");

  std::cout << form_tree << std::endl
            << form_robot << std::endl
            << form_pardon << std::endl;

  awesomeAlex.signForm(form_tree);
  awesomeAlex.signForm(form_robot);
  awesomeAlex.signForm(form_pardon);

  std::cout << std::endl
            << form_tree << std::endl
            << form_robot << std::endl
            << form_pardon << std::endl;

  awesomeAlex.executeForm(form_tree);
  awesomeAlex.executeForm(form_robot);
  awesomeAlex.executeForm(form_pardon);

  std::cout << std::endl
            << YELLOW
            << "----- Forms not signed and then trying to execute -----"
            << std::endl
            << std::endl;

  ShrubberyCreationForm form_tree2("Tree");
  RobotomyRequestForm form_robot2("Bobby");
  PresidentialPardonForm form_pardon2("Ted Bundy");

  std::cout << form_tree2 << std::endl
            << form_robot2 << std::endl
            << form_pardon2 << std::endl;

  horribleHolly.signForm(form_tree2);
  horribleHolly.signForm(form_robot2);
  horribleHolly.signForm(form_pardon2);

  std::cout << std::endl
            << form_tree2 << std::endl
            << form_robot2 << std::endl
            << form_pardon2 << std::endl;

  awesomeAlex.executeForm(form_tree2);
  awesomeAlex.executeForm(form_robot2);
  awesomeAlex.executeForm(form_pardon2);

  std::cout << std::endl
            << BLUE
            << "----- Forms get signed but can't be executed because grade is "
               "too low -----"
            << std::endl
            << std::endl;

	ShrubberyCreationForm form_tree3("Tree");
  RobotomyRequestForm form_robot3("Bobby");
  PresidentialPardonForm form_pardon3("Ted Bundy");

  std::cout << form_tree3 << std::endl
            << form_robot3 << std::endl
            << form_pardon3 << std::endl;

  awesomeAlex.signForm(form_tree3);
  awesomeAlex.signForm(form_robot3);
  awesomeAlex.signForm(form_pardon3);

  std::cout << std::endl
            << form_tree3 << std::endl
            << form_robot3 << std::endl
            << form_pardon3 << std::endl;

  horribleHolly.executeForm(form_tree3);
  horribleHolly.executeForm(form_robot3);
  horribleHolly.executeForm(form_pardon3);
}