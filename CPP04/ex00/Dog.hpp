#ifndef DOG_HPP
#define DOG_HPP

#include "Ex00.hpp"
#include "Animal.hpp"

class	Dog: public Animal
{
	public:
		// OCN 
		Dog(void);
		Dog(const Dog &obj);
		Dog &operator=(const Dog &obj);
		~Dog(void);
	// Other functions
		std::string getType(void) const;
		void	makeSound(void) const;

};

#endif
