#ifndef EASYFIND_HPP
#define EASYFIND_HPP

#include <algorithm>
#include <stdexcept>

template <typename T>
typename T::iterator	easyfind(T &container, int target)
{
	typename T::iterator	found = std::find(container.begin(), container.end(), target);
	if (found == container.end())
		throw std::runtime_error("Value not found in container");
	return found;
}

template <typename T>
typename T::const_iterator	easyfind(const T &container, int target)
{
	typename T::const_iterator	found = std::find(container.begin(), container.end(), target);
	if (found == container.end())
		throw std::runtime_error("Value not found in container");
	return found;
}

#endif
