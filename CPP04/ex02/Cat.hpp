#ifndef CAT_HPP
#define CAT_HPP

#include "Ex02.hpp"
#include "AAnimal.hpp"
#include "Brain.hpp"

class	Cat: public AAnimal
{
	private:
		Brain *catBrain;
	public:
		// Constructor
		Cat(void);
		Cat(const Cat &obj);

		// Destructor
		~Cat(void);

		// Operator
		Cat &operator=(const Cat &obj);

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
