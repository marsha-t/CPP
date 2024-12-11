#ifndef ROBOTOMYREQUESTFORM_HPP
#define ROBOTOMYREQUESTFORM_HPP

#include "AForm.hpp"
#include <cstdlib>
#include <ctime>

# define RESET "\033[0m"
# define PURPLE "\033[35m"

class RobotomyRequestForm: public AForm
{
	public:
		// Constructors
		RobotomyRequestForm(void);
		RobotomyRequestForm(std::string name);
		RobotomyRequestForm(const RobotomyRequestForm &obj);

		// Destructors
		~RobotomyRequestForm(void);

		// Operators
		RobotomyRequestForm	&operator=(const RobotomyRequestForm &obj);

		// Other functions
		virtual void	executeAction(void) const;
};

#endif