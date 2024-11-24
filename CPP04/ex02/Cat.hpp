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
		// OCN
		Cat(void);
		Cat(const Cat &obj);
		Cat &operator=(const Cat &obj);
		~Cat(void);
	
		// Other functions
		std::string getType(void) const;
		void	printBrainAddress(void) const;
		void	makeSound(void) const;
};

#endif
