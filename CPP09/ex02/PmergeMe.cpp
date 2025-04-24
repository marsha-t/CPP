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

int	PmergeMe::getSize(void) const
{
	return (_size);
}

void	PmergeMe::parse(int argc, char **argv)
{
	if (argc < 2)
			throw std::runtime_error("Invalid number of arguments");
	for (int i = 1; i < argc; ++i)
	{
		std::string	arg(argv[i]);
		if (arg.empty())
			throw std::runtime_error("Empty input");
		for (size_t j = 0; j < arg.length(); ++j)
		{
			if (!std::isdigit(arg[j]))
				throw std::runtime_error("Non-digit character input");
		}
		long value = std::atol(argv[i]);
		if (value <= 0 || value > INT_MAX)
			throw std::runtime_error("Input is outside of range");
		for (size_t k = 0; k < _vector.size(); ++k)
		{
			if (_vector[k] == value)
				throw std::runtime_error("Duplicate input");
		}
		_vector.push_back(static_cast<int>(value));
		_deque.push_back(static_cast<int>(value));
	}
	_size = _vector.size();
}

void	PmergeMe::printBefore(void) const
{
	std::cout << "Before: ";
	for (std::vector<int>::const_iterator it = _vector.begin(); it != _vector.end(); ++it)
		std::cout << *it << " ";
	std::cout << std::endl;
}

void	PmergeMe::sort(void)
{
	clock_t	start = clock();
	sortVector(_vector);
	_vectorDuration = 1000000 * (clock() - start) / CLOCKS_PER_SEC; // document
	start = clock();
	sortDeque(_deque);
	_dequeDuration = 1000000 * (clock() - start) / CLOCKS_PER_SEC; // document
}

void	PmergeMe::sortVector(std::vector<int> &toSort)
{
	size_t	size = toSort.size();
	if (size <= 1)
		return ;
	std::vector<int>	mainChain;
	std::vector<int>	pending;

	for (size_t i = 0; i + 1 < size; i += 2)
	{
		const int	a = toSort[i];
		const int	b = toSort[i + 1];

		mainChain.push_back(a > b ? a : b);
		pending.push_back(a > b ? b : a);
	}
	if (size % 2 != 0)
		pending.push_back(toSort[size - 1]);
	sortVector(mainChain);
	for (size_t i = 0; i < pending.size(); ++i)
	{
		binaryInsertVector(mainChain, pending[i]);
	}
	toSort = mainChain;
}

void	PmergeMe::binaryInsertVector(std::vector<int> &vec, int toInsert)
{
	size_t	start = 0;
	size_t	end = vec.size();

	while (end > start)
	{
		size_t	mid = (start + end) / 2;
		if (vec[mid] < toInsert)
			start = mid + 1;
		else
			end = mid;
	}
	vec.insert(vec.begin() + start, toInsert);
}

void	PmergeMe::sortDeque(std::deque<int> &toSort)
{
	size_t	size = toSort.size();
	if (size <= 1)
		return ;
	std::deque<int>	mainChain;
	std::deque<int>	pending;

	for (size_t i = 0; i + 1 < size; i += 2)
	{
		const int	a = toSort[i];
		const int	b = toSort[i + 1];

		mainChain.push_back(a > b ? a : b);
		pending.push_back(a > b ? b : a);
	}
	if (size % 2 != 0)
		pending.push_back(toSort[size - 1]);
	sortDeque(mainChain);
	for (size_t i = 0; i < pending.size(); ++i)
	{
		binaryInsertDeque(mainChain, pending[i]);
	}
	toSort = mainChain;
}

void	PmergeMe::binaryInsertDeque(std::deque<int> &deq, int toInsert)
{
	size_t	start = 0;
	size_t	end = deq.size();

	while (end > start)
	{
		size_t	mid = (start + end) / 2;
		if (deq[mid] < toInsert)
			start = mid + 1;
		else
			end = mid;
	}
	deq.insert(deq.begin() + start, toInsert);
}

void	PmergeMe::checkSort(void) const
{
	if (_vector.size() != _deque.size())
		throw std::runtime_error("Sorting error: Wrong sizes across containers");
	for (size_t i = 0; i < _vector.size(); ++i)
	{
		if (_vector[i] != _deque[i])
			throw std::runtime_error("Sorting error: Containers have different sorted sequences");
	}
}

void	PmergeMe::printAfter(void) const
{
	std::cout << "After: " << std::flush;
	for (std::vector<int>::const_iterator it = _vector.begin(); it != _vector.end(); ++it)
		std::cout << *it << " ";
	std::cout << std::endl;
	std::cout << "Time to process a range of " << std::setw(5)
		<< _vector.size() << " elements with std::vector : " << std::fixed
		<< _vectorDuration << " us" << std::endl;
		std::cout << "Time to process a range of " << std::setw(5)
		<< _deque.size() << " elements with std::deque : " << std::fixed
		<< _dequeDuration << " us" << std::endl;	
}
