#ifndef POINT_HPP
#define POINT_HPP

#include "Fixed.hpp"

class Point
{
	public:
		// OCN
		Point(void);
		Point(const float x_val, const float y_val);
		Point(const Point &obj);
		Point &operator=(const Point &obj);
		~Point(void);

		// Getter
		const Fixed	getX(void) const;
		const Fixed	getY(void) const;
	private:
		const Fixed x;
		const Fixed y;
};

bool bsp(Point const a, Point const b, Point const c, Point const point);

#endif
