#ifndef	ARRAY_HPP
#define ARRAY_HPP

#include <stdexcept>

template <typename T>
class	Array
{
	private:
		unsigned int	_size;
		T				*_arr;
	public:
		// Constructor
		Array<T>(void): _size(0), _arr(0) {}
		Array<T>(unsigned int n): _size(n), _arr(new T[n]()) {}
		Array<T>(const Array<T> &obj): _size(obj._size)
		{
			_arr = new T[_size];
			for (unsigned int i = 0; i < _size; ++i)
			{
				_arr[i] = obj._arr[i];
			}
		}

		// Destructor
		~Array<T>(void) { delete[] _arr; }

		// Operator
		Array<T>	&operator=(const Array<T> &obj)
		{
			if (this != &obj)
			{
				delete[] _arr;
				_size = obj._size;
				_arr = new T[_size];
				for (unsigned int i = 0; i < _size; ++i)
				{
					_arr[i] = obj._arr[i];
				}
			}
			return (*this);
		}
		T	&operator[](unsigned int index)
		{
			if (index < 0 || index >= _size)
				throw std::out_of_range ("Index is out of bounds");
			return (_arr[index]);
		}
		const T	&operator[](unsigned int index) const
		{
			if (index < 0 || index >= _size)
				throw std::out_of_range ("Index is out of bounds");
			return (_arr[index]);
		}
		// Other functions
		unsigned int	size(void) const { return (_size); }
	
};

#endif