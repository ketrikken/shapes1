#pragma once
#include <Windows.h>
#include <cmath>
#include <iostream>
#include "ColorParametrs.h"
#include <vector>
#include "Point.h"

const double pi = 3.1415926535;

class IFigure
{
public:
	virtual ~IFigure(){}
	
	virtual void Shift(const Point & xy) = 0;//сдвинуть
	virtual void DrawShape(const Color & parametrs) = 0;//нарисовать фигуру
	virtual void TurnShape(double n, Point XY) = 0;//повернуть 
protected:
	
};
