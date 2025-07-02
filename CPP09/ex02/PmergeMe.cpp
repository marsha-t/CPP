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
	sort(_vector);
	_vectorDuration = 1000000 * (clock() - start) / CLOCKS_PER_SEC;
	start = clock();
	sort(_deque);
	_dequeDuration = 1000000 * (clock() - start) / CLOCKS_PER_SEC;
}

void	PmergeMe::sort(std::vector<int> &toSort)
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
	sort(mainChain);
	std::vector<size_t> order = getJacobsthalIndicesVector(pending.size());
	for (size_t i = 0; i < order.size(); ++i)
	{
		binaryInsert(mainChain, pending[order[i]]);
	}
	toSort = mainChain;
}

// Jacobsthal Sequence
// J(0) = 0 
// J(1) = 1
// J(n) = J(n - 1) + 2 x J(n - 2) for n >= 2
std::vector<size_t> PmergeMe::getJacobsthalIndicesVector(size_t n)
{
	std::vector<size_t> indices;
	std::vector<bool> usedIndices(n, false);

	size_t j0 = 0;
	size_t j1 = 1;

	while (j1 < n)
	{
		if (!usedIndices[j1])
		{
			indices.push_back(j1);
			usedIndices[j1] = true;
		}
		size_t next = j1 + 2 * j0;
		j0 = j1;
		j1 = next;
	}
	for (size_t i = 0; i < n; ++i)
	{
		if (!usedIndices[i])
			indices.push_back(i);
	}
	return (indices);
}

void	PmergeMe::binaryInsert(std::vector<int> &vec, int toInsert)
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

void	PmergeMe::sort(std::deque<int> &toSort)
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
	sort(mainChain);
	std::deque<size_t> order = getJacobsthalIndicesDeque(pending.size());
	for (size_t i = 0; i < pending.size(); ++i)
	{
		binaryInsert(mainChain, pending[order[i]]);
	}
	toSort = mainChain;
}

std::deque<size_t> PmergeMe::getJacobsthalIndicesDeque(size_t n)
{
	std::deque<size_t> indices;
	std::deque<bool> usedIndices(n, false);

	size_t j0 = 0;
	size_t j1 = 1;
	while (j1 < n)
	{
		if (!usedIndices[j1])
		{
			indices.push_back(j1);
			usedIndices[j1] = true;
		}
		size_t next = j1 + 2 * j0;
		j0 = j1;
		j1 = next;
	}
	for (size_t i = 0; i < n; ++i)
	{
		if (!usedIndices[i])
			indices.push_back(i);
	}
	return (indices);
}

void	PmergeMe::binaryInsert(std::deque<int> &deq, int toInsert)
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
