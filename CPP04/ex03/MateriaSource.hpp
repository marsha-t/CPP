#ifndef MATERIASOURCE_HPP
#define MATERIASOURCE_HPP

#include "Ex03.hpp"

class MateriaSource: public IMateriaSource
{
	private:
		AMateria	*_memory[4];
		std::string	_name;
	public:
		// Constructor
		MateriaSource(void);
		MateriaSource(std::string name);
		MateriaSource(const MateriaSource &obj);

		// Destructor
		~MateriaSource(void);

		// Operator
		MateriaSource	&operator=(const MateriaSource &obj);

		// Getter
		std::string const &getName(void) const;
		
		// Setter
		void	setName(std::string name);

		// Other functions
		void learnMateria(AMateria *newMateria);
		AMateria* createMateria(std::string const &type);

};

#endif