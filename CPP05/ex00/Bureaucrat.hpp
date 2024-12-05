#ifndef BUREAUCRAT_HPP
#define BUREAUCRAT_HPP

#include <stdexcept>
#include <string>
#include <cstdlib>

class Bureaucrat: public std::exception
{
	private:
		const std::string _name;
		unsigned int _grade;
	
	public:
		// Constructors
		Bureaucrat(void);

		// Getters
		const std::string &getName(void) const;
		unsigned int	getGrade(void) const;

		// Other functions
		void	downgrade(void);
		void	upgrade(void);
};

std::ostream &operator<<(std::ostream &out, Bureaucrat const &obj);

#endif