#pragma once
#include "ConvexHull.h"
#include <vector>
#include "ShapeBase.h"
#include "HelpFunctions.h"


class Quadrangle : public ShapeBase
{
public:
	Quadrangle(const std::vector<Point> & mas);
	
	void Shift(const Point & xy) override;
	void DrawShape(const Color & parametrs) override;
	void TurnShape(double n, Point XY) override;

private:
	Point Delta(Point & deltaXY);
	void Rebuild(){ ConvexHull::Solve(convex_hull, _points);}
	bool IsEmpty() { return _points.size(); }
	std::vector< Point > _points;
	std::vector<int> convex_hull;
	
};
