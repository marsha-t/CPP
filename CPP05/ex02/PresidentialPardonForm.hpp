#ifndef PRESIDENTIALPARDONFORM_HPP
#define PRESIDENTIALPARDONFORM_HPP

#include "AForm.hpp"

# define RESET "\033[0m"
# define BLUE "\033[34m"

class PresidentialPardonForm: public AForm
{
	public:
		// Constructors
		PresidentialPardonForm(void);
		PresidentialPardonForm(std::string name);
		PresidentialPardonForm(const PresidentialPardonForm &obj);

		// Destructors
		~PresidentialPardonForm(void);

		// Operators
		PresidentialPardonForm	&operator=(const PresidentialPardonForm &obj);

		// Other functions
		virtual void	executeAction(void) const;
};

#endif