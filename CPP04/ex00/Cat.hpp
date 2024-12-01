#ifndef CAT_HPP
#define CAT_HPP

#include "Ex00.hpp"
#include "Animal.hpp"

class	Cat: public Animal
{
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
		
		// Other functions
		void	makeSound(void) const;
};

#endif
