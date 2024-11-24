#ifndef AANIMAL_HPP
#define AANIMAL_HPP

#include "Ex02.hpp"

class	AAnimal
{
	protected:
		std::string	type;
	public:
		// OCN 
		AAnimal(void);
		AAnimal(std::string inputType);
		AAnimal(const AAnimal &obj);
		AAnimal	&operator=(const AAnimal &obj);
		virtual ~AAnimal(void);

		// Other functions
		virtual std::string	getType(void) const;
		virtual void	makeSound(void) const = 0;
};

#endif
