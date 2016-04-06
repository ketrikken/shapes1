#include "ConvexHull.h"

void ConvexHull::Solve(VecInt & convex_hull, VecPoint & _points)
{
	ConvexHullJarvis(convex_hull, _points);
	double P = 0;
	for (size_t i = 0; i<convex_hull.size() - 1; i++)
		P += HelpFunctions::Dist(_points[convex_hull[i]], _points[convex_hull[i + 1]]);
}
void ConvexHull::ConvexHullJarvis(VecInt & convex_hull, VecPoint & _points)
{
	// находим самую левую из самых нижних
	int base = 0;
	for (int i = 1; i < _points.size(); i++)
	{
		if (_points[i].Y < _points[base].Y)
			base = i;
		else
			if (_points[i].Y == _points[base].Y &&
				_points[i].X <  _points[base].X)
				base = i;
	}
	// эта точка точно входит в выпуклую оболочку
	convex_hull.push_back(base);

	int first = base;
	int cur = base;
	do
	{
		int next = (cur + 1) % _points.size();
		for (int i = 0; i < _points.size(); i++)
		{
			int sign = HelpFunctions::OrientTriangl2(_points[cur], _points[next], _points[i]);
			if (sign < 0) // обход выпуклой оболочки против часовой стрелки
				next = i;
			else if (sign == 0)
			{
				if (HelpFunctions::IsInside(_points[cur], _points[next], _points[i]))
					next = i;
			}
		}
		cur = next;
		convex_hull.push_back(next);
	} while (cur != first);
}