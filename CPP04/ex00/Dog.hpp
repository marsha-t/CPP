#ifndef DOG_HPP
#define DOG_HPP

#include "Ex00.hpp"
#include "Animal.hpp"

class	Dog: public Animal
{
	public:
		// Constructor
		Dog(void);
		Dog(const Dog &obj);

		// Destructor
		~Dog(void);

		// Operator
		Dog &operator=(const Dog &obj);

		// Getter & Setter
		std::string getType(void) const;
		
		// Other functions
		void	makeSound(void) const;

};

#endif
