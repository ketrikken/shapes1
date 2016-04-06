#pragma once
#include <iostream>

struct Point
{
	friend std::istream & operator>>(std::istream &is, Point & a);
	void operator +=(Point a);
	void operator -=(Point a);
	bool operator != (const Point & a);
	double X, Y;
	Point() : X(0), Y(0) {};
	Point(int x, int y) : X(x), Y(y) {};
};
