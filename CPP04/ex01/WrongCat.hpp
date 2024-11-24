#ifndef WRONGCAT_HPP
#define WRONGCAT_HPP

#include "Ex01.hpp"
#include "WrongAnimal.hpp"

class WrongCat: public WrongAnimal
{
	public:
		// OCN
		WrongCat(void);
		WrongCat(const WrongCat &obj);
		WrongCat &operator=(const WrongCat &obj);
		~WrongCat(void);

		// Other functions
		std::string getType(void) const;
};

#endif