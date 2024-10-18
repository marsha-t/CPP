#ifndef FIXED_HPP
# define FIXED_HPP

#include <iostream>

class	Fixed
{
	public:
		Fixed(void);
		Fixed(const Fixed &obj);
		Fixed &operator=(const Fixed &obj);
		~Fixed(void);
		int		getRawBits(void) const; 
		void	setRawBits(int const raw);
	private:	
		int	_value;
		static const int _frac;
};

#endif
