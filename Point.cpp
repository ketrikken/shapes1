#include "Point.h"

void Point::operator +=(Point a)
{
	X += a.X;
	Y += a.Y;
}
void Point::operator -=(Point a)
{
	X -= a.X;
	Y -= a.Y;
}
bool Point::operator != (const Point & a)
{
	return !(a.X == X && a.Y == Y);
}

std::istream & operator>>(std::istream &is, Point & a)
{
	int aa, ba;
	is >> aa;
	is >> ba;
	a.X = aa;
	a.Y = ba;
	return is;
}