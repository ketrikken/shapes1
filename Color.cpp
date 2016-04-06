#include "Color.h"

std::istream & operator>>(std::istream &is, Color & a)
{
	is >> a.R;
	is >> a.G;
	is >> a.B;
	return is;
}
void Color::SetParametrs(int r, int g, int b)
{
	R = r % 256;
	G = g % 256;
	B = b % 256;
}