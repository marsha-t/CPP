#ifndef WRONGANIMAL_HPP
#define WRONGANIMAL_HPP

#include "Ex02.hpp"

class WrongAnimal
{
	protected:
		std::string	type;
	public:
		// OCN
		WrongAnimal(void);
		WrongAnimal(std::string inputType);
		WrongAnimal(const WrongAnimal &obj);
		WrongAnimal &operator=(const WrongAnimal &obj);
		virtual ~WrongAnimal(void);

		// Other functions
		virtual std::string	getType(void) const;
		void	makeSound(void) const;
};

#endif