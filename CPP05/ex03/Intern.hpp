#ifndef INTERN_HPP
#define INTERN_HPP

# define RESET "\033[0m"
# define CYAN "\033[36m"

#include <string>
#include "AForm.hpp"

void	debugMsg(std::string msg);
void	warningMsg(std::string msg);
void	successMsg(std::string msg);

class Intern
{
	public:
		// Constructor
		Intern(void);
		Intern(const Intern &obj);
		
		// Destructor
		~Intern(void);
		
		// Operator
		Intern	&operator=(const Intern &obj);
		
		// Other functions
		AForm	*makeForm(std::string name, std::string target) const;
		
};

#endif