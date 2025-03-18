#ifndef ARRAY_HPP
#define ARRAY_HPP

#include <stdexcept>

template <typename T>
Array<T>::Array(const Array<T> &obj): _n(obj.size()), _arr(new T[obj.size()]) 
{
	for (int i = 0; i < _n; i++)
	{
		_arr[i] = obj[i];
	}
}

template <typename T>
Array<T>	&Array<T>::operator=(const Array<T> &obj)
{
	if (this != &obj)
	{
		delete _arr;
		_n = obj.size();
		_arr = new T[_n];
	}
	return (*this);
}

template <typename T>
T	&Array<T>::operator[](unsigned int index)
{
	if (index >= _n)
		throw std::out_of_range("Index is out of bounds");
	return _arr[index];
}

#endif