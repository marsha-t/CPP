#ifndef DOG_HPP
#define DOG_HPP

#include "Ex02.hpp"
#include "AAnimal.hpp"
#include "Brain.hpp"

class	Dog: public AAnimal
{
	private:
		Brain	*dogBrain;
	public:
		// OCN 
		Dog(void);
		Dog(const Dog &obj);
		Dog &operator=(const Dog &obj);
		~Dog(void);
	// Other functions
		std::string getType(void) const;
		void	printBrainAddress(void) const;
		void	makeSound(void) const;

};

#endif
