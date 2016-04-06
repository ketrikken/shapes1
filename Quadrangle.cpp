#include "Quadrangle.h"


Quadrangle::Quadrangle(const std::vector<Point> & mas)
{

	_points = mas;
	ConvexHull::Solve(convex_hull, _points);
	SetStandartColor();
}
void Quadrangle::Shift(const Point & xy)
{
	for (int i = 0; i < _points.size(); ++i)
		_points[i] += xy;
}
void Quadrangle::DrawShape(const Color & parametrs)
{
	HDC hDC = GetDC(GetConsoleWindow());
	HPEN Pen = CreatePen(PS_SOLID, 2, RGB(parametrs.R, parametrs.G, parametrs.B));
	SelectObject(hDC, Pen);

	int n = convex_hull.size();
	for (int i = 0; i < convex_hull.size(); ++i)
	{
		MoveToEx(hDC, _points[convex_hull[i]].X, _points[convex_hull[i]].Y, NULL);
		LineTo(hDC, _points[convex_hull[(i + 1) % n]].X, _points[convex_hull[(i + 1) % n]].Y);
	}
}
void Quadrangle::TurnShape(double n, Point XY)
{
	Point delta;
	delta = Delta(XY);
	for (int i = 0; i < convex_hull.size() - 1; ++i)
	{
		TurnPoint(n, _points[convex_hull[i]]);
	}
	for (int i = 0; i < convex_hull.size() - 1; ++i)
	{
		_points[convex_hull[i]] -= delta;
	}

}

Point Quadrangle::Delta(Point & deltaXY)
{
	Point delta;
	delta.X = 0.0 - deltaXY.X;
	delta.Y = 0.0 - deltaXY.Y;
	for (int i = 0; i < convex_hull.size() - 1; ++i)
	{
		_points[convex_hull[i]] += delta;
	}
	return delta;
}