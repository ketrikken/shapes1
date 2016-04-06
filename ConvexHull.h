#pragma once
#include "HelpFunctions.h"
typedef std::vector<int> VecInt;
typedef std::vector< Point > VecPoint;
class ConvexHull
{
public:
	static void Solve(VecInt & convex_hull, VecPoint & _points);
private:
	static void ConvexHullJarvis(VecInt & convex_hull, VecPoint & _points);
};