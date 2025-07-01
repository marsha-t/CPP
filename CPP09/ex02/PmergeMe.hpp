#ifndef	PMERGE_HPP
#define PMERGE_HPP

#include <string>
#include <vector>
#include <deque>
#include <ctime>
#include <iostream>
#include <cstdlib>
#include <climits>
#include <iomanip>

void	debugMsg(std::string msg);

class PmergeMe
{
	public:
		PmergeMe(void);
		PmergeMe(const PmergeMe &obj);
		PmergeMe &operator=(const PmergeMe &obj);
		~PmergeMe(void);

		int	getSize(void) const;
		void	parse(int argc, char **argv);
		void	printBefore(void) const;
		void	sort(void);
		void	checkSort(void) const;
		void	printAfter(void) const;
	
	private:
		std::vector<int>	_vector;
		std::deque<int>		_deque;
		int					_size;
		double				_vectorDuration;
		double				_dequeDuration;
		void	sortVector(std::vector<int> &toSort);
		void	sortDeque(std::deque<int> &toSort);
		void	binaryInsertVector(std::vector<int> &vec, int toInsert);
		void	binaryInsertDeque(std::deque<int> &vec, int toInsert);

};

#endif