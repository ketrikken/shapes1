#pragma once
#include <iostream>
struct Color
{
	int R, G, B;
	Color(int r, int g, int b) : R(r), G(g), B(b) {};
	Color() {}
	void SetParametrs(int r, int g, int b);
	friend std::istream & operator>>(std::istream &is, Color & a);
};
