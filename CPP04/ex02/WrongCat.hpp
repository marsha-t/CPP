#ifndef WRONGCAT_HPP
#define WRONGCAT_HPP

#include "Ex02.hpp"
#include "WrongAnimal.hpp"

class WrongCat: public WrongAnimal
{
	public:
		// Constructor
		WrongCat(void);
		WrongCat(const WrongCat &obj);
		
		// Destructor
		~WrongCat(void);
		
		// Operator
		WrongCat &operator=(const WrongCat &obj);

		// Getter & Setter
		std::string getType(void) const;

		// Other functions
		void	makeSound(void) const;

};

#endif