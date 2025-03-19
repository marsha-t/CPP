#include "Span.hpp"

Span::Span(void): _maxSize(0) {}

Span::Span(unsigned int n): _maxSize(n) {}

Span::Span(const Span &obj): _maxSize(obj._maxSize), _vector(obj._vector), _validShortestSpan(obj._validShortestSpan), _shortestSpan(obj._shortestSpan) {}

Span::~Span(void) {}

Span	&Span::operator=(const Span &obj)
{
	if (this != &obj)
	{
		_maxSize = obj._maxSize;
		_vector = obj._vector;
		_validShortestSpan = obj._validShortestSpan;
		_shortestSpan = obj._shortestSpan;
	}
	return (*this);
}

void	Span::addNumber(int num)
{
	if (_vector.size() == _maxSize)
		throw std::overflow_error("Cannot add more numbers: Span is full");
	_vector.push_back(num);
	_validShortestSpan = false;
}

unsigned int	Span::shortestSpan(void)
{
	if (_vector.size() < 2)
		throw std::runtime_error("Not enough numbers to calculate span");
	else if (_validShortestSpan)
		return _shortestSpan;
	std::vector<int>	sorted = _vector;
	std::sort(sorted.begin(), sorted.end());
	unsigned int	min = std::numeric_limits<unsigned int>::max();
	for (std::vector<int>::const_iterator it = sorted.begin() + 1; it != sorted.end(); ++it)
	{
		unsigned int dif = std::abs(*(it - 1) - *it);
		if (dif < min)
			min = dif;
	}
	_validShortestSpan = true;
	_shortestSpan = min;
	return (min);
}

unsigned int	Span::longestSpan(void)
{
	if (_vector.size() < 2)
		throw std::runtime_error("Not enough numbers to calculate span");
	unsigned int	max = *std::max_element(_vector.begin(), _vector.end()) - *std::min_element(_vector.begin(), _vector.end());
	return (max);
}
