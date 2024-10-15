#ifndef FIXED_HPP
# define FIXED_HPP

#include <iostream>
#include <cmath>

class	Fixed
{
	public:
		Fixed(void);
		Fixed(const int value);
		Fixed(const float value);
		Fixed(const Fixed& obj);
		Fixed &operator=(const Fixed& obj);
		~Fixed(void);
		int		getRawBits(void) const { return (this->_value); };
		void	setRawBits(int const raw) { this->_value = raw; return ;};
		float	toFloat(void) const { return (static_cast<float>(this->_value) / (1 << this->_frac)); };
		int		toInt(void) const { return (this->_value >> _frac); };
	private:	
		int	_value;
		static const int _frac;
};

std::ostream &operator<<(std::ostream &out, Fixed const &obj);

#endif
