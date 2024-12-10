#ifndef SHRUBBERYCREATIONFORM_HPP
#define SHRUBBERYCREATIONFORM_HPP

#include <fstream>
#include "AForm.hpp"
class ShrubberyCreationForm: public AForm
{
	public:
		// Constructors
		ShrubberyCreationForm(void);
		ShrubberyCreationForm(std::string name);
		ShrubberyCreationForm(const ShrubberyCreationForm &obj);

		// Destructors
		~ShrubberyCreationForm(void);

		// Operators
		ShrubberyCreationForm	&operator=(const ShrubberyCreationForm &obj);
		
		// Other Operators
		virtual void	executeAction(void) const;

};

#endif