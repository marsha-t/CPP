#ifndef SHRUBBERYCREATIONFORM_HPP
#define SHRUBBERYCREATIONFORM_HPP

#include <fstream>
#include "AForm.hpp"

# define RESET "\033[0m"
# define YELLOW "\033[33m"

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
		
		// Other Functions
		virtual void	executeAction(void) const;
};

#endif