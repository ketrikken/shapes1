#pragma once
#include "ArgumentsCreator.h"
class HelpFunctions
{
	public:
		static bool IsInside(const Point & p1, const Point & p, const Point & p2)
		{
			return (p1.X <= p.X && p.X <= p2.X &&
				p1.Y <= p.Y && p.Y <= p2.Y);
		}
		static double OrientTriangl2(const Point & p1, const Point & p2, const Point & p3)
		{
			return p1.X * (p2.Y - p3.Y) + p2.X * (p3.Y - p1.Y) + p3.X * (p1.Y - p2.Y);
		}
		static double Dist(const Point & a, const Point & b)
		{
			return sqrt(0.0 + (a.X - b.X) * (a.X - b.X) + (a.Y - b.Y) * (a.Y - b.Y));
		}
};