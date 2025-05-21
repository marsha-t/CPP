#ifndef ITER_HPP
#define ITER_HPP

#include <cstdlib>
#include <iostream>

template <typename T, typename F>
void	iter(T *address, size_t len, F func)
{
	for (size_t i = 0; i < len; i++)
	{
		func(address[i]);
	}
}

template <typename T>
void	print(const T &element)
{
	std::cout << element << std::endl;
}

template <typename T>
void	addOne(T &element)
{
	element += 1;
}

#endif