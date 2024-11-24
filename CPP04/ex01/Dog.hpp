#ifndef DOG_HPP
#define DOG_HPP

#include "Ex01.hpp"
#include "Animal.hpp"
#include "Brain.hpp"

class	Dog: public Animal
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
