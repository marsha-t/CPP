#ifndef ITER_HPP
#define ITER_HPP

#include <cstdlib>
#include <iostream>

template <typename A, typename F>
void	iter(A *address, size_t len, F func)
{
	for (size_t i = 0; i < len; i++)
	{
		func(address[i]);
	}
}

template <typename T>
void	print(T element)
{
	std::cout << element << std::endl;
}

#endif