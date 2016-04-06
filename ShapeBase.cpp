#include "ShapeBase.h"

void ShapeBase::SetColor(int r, int g, int b)
{
	_color.R = r;
	_color.G = g;
	_color.B = b;
}
void ShapeBase::TurnPoint(double n, Point & XY)
{
	double x1, y1;
	n = n * pi / 180;
	x1 = XY.X * cos(n) - XY.Y * sin(n);
	y1 = XY.X * sin(n) + XY.Y * cos(n);
	XY.X = x1;
	XY.Y = y1;
}
void ShapeBase::SetStandartColor()
{
	_color.R = 2;
	_color.G = 70;
	_color.B = 255;
}
