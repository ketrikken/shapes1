#pragma once
#include "ShapeBase.h"


class Circle : public ShapeBase
{
public:
	Circle(Point p, int r);
	void DrawShape(const Color & parametrs) override;
	void Shift(const Point & xy) override;
	void TurnShape(double n, Point XY)override;
private:
	void StandartParametrs(Point XY, int rad) { _centre = XY; _radius = rad; }
	double _radius;
	Point _centre;
};

