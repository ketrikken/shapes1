#pragma once
#include "IFigure.h"
#include <cassert>


class ShapeBase : public IFigure
{
public:
	ShapeBase(){}
protected:
	void SetColor(int r, int g, int b);
	void TurnPoint(double n, Point & XY);
	void SetStandartColor();
	Color _color;
};
