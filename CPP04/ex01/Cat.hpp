#ifndef CAT_HPP
#define CAT_HPP

#include "Ex01.hpp"
#include "Animal.hpp"
#include "Brain.hpp"

class	Cat: public Animal
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
