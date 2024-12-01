#ifndef ANIMAL_HPP
#define ANIMAL_HPP

#include "Ex01.hpp"

class	Animal
{
	protected:
		std::string	type;
	public:
		// Constructor
		Animal(void);
		Animal(std::string inputType);
		Animal(const Animal &obj);
		
		// Destructor
		virtual ~Animal(void);
		
		// Operator
		Animal	&operator=(const Animal &obj);

		// Getter & Setter
		virtual std::string	getType(void) const;
		
		// Other functions
		virtual void	makeSound(void) const;
};

#endif
