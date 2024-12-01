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
		// Constructor
		Dog(void);
		Dog(const Dog &obj);

		// Destructor
		~Dog(void);

		// Operator
		Dog &operator=(const Dog &obj);

		// Getter & Setter
		std::string getType(void) const;
		void	setIdea(std::string idea);
		std::string	getIdea(unsigned int index) const;
	
		// Other functions
		void	printBrainAddress(void) const;
		void	printBrain(void) const;
		void	makeSound(void) const;

};

#endif
