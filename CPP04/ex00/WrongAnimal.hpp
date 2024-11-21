#ifndef WRONGANIMAL_HPP
#define WRONGANIMAL_HPP

#include "Ex00.hpp"

class WrongAnimal
{
	protected:
		std::string	type;
	public:
		// OCN
		WrongAnimal(void);
		WrongAnimal(const WrongAnimal &obj);
		WrongAnimal &operator=(const WrongAnimal &obj);
		virtual ~WrongAnimal(void);

		// Other functions
		virtual std::string	getType(void) const;
		void	makeSound(void) const;
};

#endif