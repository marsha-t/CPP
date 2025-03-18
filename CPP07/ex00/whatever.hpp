#ifndef WHATEVER_HPP
#define WHATEVER_HPP

#include <iostream>
#include <cstdlib>

template <typename T>
void	swap(T &x, T &y)
{
	T temp = x;
	x = y;
	y = temp;
}

template <typename T>
T const &min(T const &x, T const &y)
{
	return ((x <= y ? x : y));
}

template <typename T>
T const &max(T const &x, T const &y)
{
	return ((x >= y ? x : y));
}

class	testClass
{
	public:
		// Constructors
		testClass(void);
		testClass(int value);
		testClass(const testClass &obj);

		// Destructor
		~testClass(void);

		// Operators
		testClass	&operator=(const testClass &obj);
		bool	operator>(const testClass &obj) const;
		bool	operator<(const testClass &obj) const;
		bool	operator>=(const testClass &obj) const;
		bool	operator<=(const testClass &obj) const;

		// Getters
		int	getValue(void) const;

	private:
		int _value;
};

#endif