#include "Point.hpp"
#include <iostream>
/**
 * @brief Checks whether p3 is left/right/collinear with p1-p2 edge
 * 
 * @param p1 1st point of edge
 * @param p2 2nd point of edge
 * @param p3 point to be checked
 * @return float (sign of orientation: positive if to the left, negative if right, 0 if collinear)
 */
static float	triangleOrientation(Point const p1, Point const p2, Point const p3)
{
	return ((p1.getX() - p3.getX()) * (p2.getY() - p3.getY()) - (p2.getX() - p3.getX()) * (p1.getY() - p3.getY())).toFloat();
}

/**
 * @brief Checks whether point is inside triangle
 * 
 * @param a 1st point of triangle
 * @param b 2nd point of triangle
 * @param c 3rd point of triangle
 * @param point Point to verify if inside triangle
 * @return true if point inside triangle
 * @return false otherwise
 */
bool bsp(Point const a, Point const b, Point const c, Point const point)
{
	float	s_ab, s_bc, s_ca;
	bool	neg, pos, coll;

	s_ab = triangleOrientation(a, b, point);
	s_bc = triangleOrientation(b, c, point);
	s_ca = triangleOrientation(c, a, point);

	neg = ((s_ab < 0) || (s_bc < 0) || (s_ca < 0));
    pos = ((s_ab > 0) || (s_bc > 0) || (s_ca > 0));
	coll = ((s_ab == 0) || (s_bc == 0) || (s_ca == 0));

	return (!(neg && pos) && !(neg && coll) && !(pos && coll));
}
