#ifndef WRONGANIMAL_HPP
#define WRONGANIMAL_HPP

#include "Ex01.hpp"

class WrongAnimal
{
	protected:
		std::string	type;
	public:
		// Constructor
		WrongAnimal(void);
		WrongAnimal(std::string inputType);
		WrongAnimal(const WrongAnimal &obj);

		// Destructor
		virtual ~WrongAnimal(void);

		// Operator
		WrongAnimal &operator=(const WrongAnimal &obj);

		// Getter & Setter
		virtual std::string	getType(void) const;
		
		// Other functions
		void	makeSound(void) const;
};

#endif