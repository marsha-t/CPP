#ifndef CAT_HPP
#define CAT_HPP

#include "Ex00.hpp"
#include "Animal.hpp"

class	Cat: public Animal
{
	public:
		// OCN
		Cat(void);
		Cat(const Cat &obj);
		Cat &operator=(const Cat &obj);
		~Cat(void);
	
		// Other functions
		std::string getType(void) const;
		void	makeSound(void) const;
};

#endif
