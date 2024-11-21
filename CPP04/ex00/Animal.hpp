#ifndef ANIMAL_HPP
#define ANIMAL_HPP

#include "Ex00.hpp"

class	Animal
{
	protected:
		std::string	type;
	public:
		// OCN 
		Animal(void);
		Animal(std::string inputType);
		Animal(const Animal &obj);
		Animal	&operator=(const Animal &obj);
		virtual ~Animal(void);

		// Other functions
		virtual std::string	getType(void) const;
		virtual void	makeSound(void) const;
};

#endif
