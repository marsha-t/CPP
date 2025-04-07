#ifndef	PMERGE_HPP
#define PMERGE_HPP

#include <string>
#include <vector>
#include <deque>

void	debugMsg(std::string msg);
void	errorMsg(std::string msg);

class PmergeMe
{
	public:
		PmergeMe(void);
		PmergeMe(const PmergeMe &obj);
		PmergeMe &operator=(const PmergeMe &obj);
		~PmergeMe(void);

		void	parse(const &std::string);
		void	sort(void);
	private:
		std::vector<int>	_vector;
		std::deque<int>		_deque;
};

#endif