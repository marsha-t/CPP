#ifndef BRAIN_HPP
#define BRAIN_HPP

#include "Ex01.hpp"

class Brain
{
	private:
		std::string	_ideas[100];
		unsigned int	_nextIdeaIndex;

	public:
		// Constructors
		Brain(void);
		Brain(const Brain &obj);
		
		// Destructors
		~Brain(void);
		
		// Operators
		Brain	&operator=(const Brain &obj);

		// Getters & Setters
		unsigned int	getNextIdeaIndex(void) const;
		void	setNextIdeaIndex(unsigned int newIndex);
		std::string	getIdea(unsigned int index) const;
		void	setIdea(std::string idea);
};

#endif