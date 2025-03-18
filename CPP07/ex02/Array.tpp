#ifndef	ARRAY_TPP
#define ARRAY_TPP

template <typename T>
class	Array
{
	public:
		// Constructors
		Array<T>(void): _n(0), _arr(0) {}
		Array<T>(unsigned int n): _n(n), _arr(new T[_n]) {}
		Array<T>(const Array<T> &obj);
		
		// Destructor
		~Array<T>(void) {}

		// Operator
		Array<T>	&operator=(const Array<T> &obj);
		T	&operator[](unsigned int index);

		// Other functions
		unsigned int	size(void) const { return _n; };

	private:
		unsigned int	_n;
		T				*_arr;
};

#endif