#ifndef SPAN_HPP
#define SPAN_HPP

#include <vector>
#include <stdexcept>
#include <algorithm>
#include <limits>

class	Span
{
	public:
		// Constructor
		Span(unsigned int n);
		Span(const Span &obj);
		
		// Destructor
		~Span(void);
		
		// Operator
		Span &operator=(const Span &obj);
		
		// Other function
		void	addNumber(int num);
		unsigned int	shortestSpan(void);
		unsigned int	longestSpan(void);
		template <typename T>
		void	addNumber(T begin, T end)
		{
			if (std::distance(begin, end) + _vector.size() > _maxSize)
				throw std::overflow_error("Cannot add more numbers: Span is full");
			_vector.insert(_vector.end(), begin, end);
			_validShortestSpan = false;
		}
		unsigned int size(void) const;
		
	private:
		unsigned int		_maxSize;
		std::vector<int>	_vector;
		bool				_validShortestSpan;
		unsigned int		_shortestSpan;
		Span(void);
};

#endif