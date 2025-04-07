#include "PmergeMe.hpp"

PmergeMe::PmergeMe(void) 
{
	debugMsg("PmergeMe initialised");
}

PmergeMe::PmergeMe(const PmergeMe &obj) 
{
	debugMsg("PmergeMe initialised via copy");
	_vector = obj._vector;
	_deque = obj._deque;
}

PmergeMe &PmergeMe::operator=(const PmergeMe &obj)
{
	if (this != &obj)
	{
		debugMsg("PmergeMe copied via assignment");
		_vector = obj._vector;
		_deque = obj._deque;
	}
	return (*this);
}

PmergeMe::~PmergeMe(void) 
{
	debugMsg("PmergeMe destroyed");
}

void	PmergeMe::parse(const &std::string)
{
	std::istringstream	sequence()
}

// void	PmergeMe::sort(void)
// {

// }
