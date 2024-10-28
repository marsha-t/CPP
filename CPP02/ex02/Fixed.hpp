#ifndef FIXED_HPP
# define FIXED_HPP

#include <iostream>
#include <cmath>

class	Fixed
{
	public:
		// OCN
		Fixed(void);
		Fixed(const int value);
		Fixed(const float value);
		Fixed(const Fixed &obj);
		Fixed &operator=(const Fixed &obj);
		~Fixed(void);

		// Helper functions
		int		getRawBits(void) const;
		void	setRawBits(int const raw);
		float	toFloat(void) const;
		int		toInt(void) const;

		// Operators 
		bool	operator>(Fixed const &obj) const;
		bool	operator<(Fixed const &obj) const;
		bool	operator>=(Fixed const &obj) const;
		bool	operator<=(Fixed const &obj) const;
		bool	operator==(Fixed const &obj) const;
		bool	operator!=(Fixed const &obj) const;
		Fixed	&operator+=(Fixed const &obj);
		Fixed	&operator-=(Fixed const &obj);
		Fixed	&operator*=(Fixed const &obj);
		Fixed	&operator/=(Fixed const &obj);
		Fixed	operator+(Fixed const &obj) const;
		Fixed	operator-(Fixed const &obj) const;
		Fixed	operator*(Fixed const &obj) const;
		Fixed	operator/(Fixed const &obj) const;
		Fixed	&operator++(void);
		Fixed	operator++(int);
		Fixed	&operator--(void);
		Fixed	operator--(int);

		// Min/Max
		static Fixed &min(Fixed &obj1, Fixed &obj2);
		static const Fixed &min(Fixed const &obj1, Fixed const &obj2);
		static Fixed &max(Fixed &obj1, Fixed &obj2);
		static const Fixed &max(Fixed const &obj1, Fixed const &obj2);

	private:	
		int	_value;
		static const int _frac;
};


std::ostream &operator<<(std::ostream &out, Fixed const &obj);

#endif
