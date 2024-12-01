#ifndef AANIMAL_HPP
#define AANIMAL_HPP

#include "Ex02.hpp"

class	AAnimal
{
	protected:
		std::string	type;
	public:
		// Constructor
		AAnimal(void);
		AAnimal(std::string inputType);
		AAnimal(const AAnimal &obj);

		// Destructor
		virtual ~AAnimal(void);

		// Operator
		AAnimal	&operator=(const AAnimal &obj);

		// Getter & Setter
		virtual std::string	getType(void) const;
		
		// Other functions
		virtual void	makeSound(void) const = 0;
};

#endif
