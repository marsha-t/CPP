#ifndef MUTANTSTACK_HPP
#define MUTANTSTACK_HPP

#include <stack>

template <typename T, typename Container = std::deque<T> >
class MutantStack: public std::stack<T, Container>
{
	public:
		// Constructor
		MutantStack(void): std::stack<T, Container>() {}
		MutantStack(const MutantStack &obj): std::stack<T, Container>(obj) {}
		
		// Destructor
		~MutantStack(void) {}
		
		// Operator
		MutantStack	&operator=(const MutantStack &obj) 
		{ 
			if (this != &obj)
			{
				std::stack<T, Container>::operator=(obj);
			}
			return (*this);
		}

		// Iterators
		typedef typename std::stack<T, Container>::container_type::iterator iterator;
		iterator	begin(void) { return this->c.begin(); }
		iterator	end(void) { return this->c.end(); }
		typedef typename std::stack<T, Container>::container_type::const_iterator const_iterator;
		const_iterator	begin(void) const { return this->c.begin(); }
		const_iterator	end(void) const { return this->c.end(); }


	private:
};

#endif