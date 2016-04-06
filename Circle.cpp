#include "Circle.h"

void Circle::DrawShape(const Color & parametrs)
{
	
	for (int i = 0; i < 360; i++)
	{
		//Перевод из градусов в радианы
		double a = i * pi / 180;
		//Вычисляем координаты
		double x = _radius * cos(a);
		double y = _radius * sin(a);

		HDC hDC = GetDC(GetConsoleWindow());
		HPEN Pen = CreatePen(PS_SOLID, 2, RGB(parametrs.G, parametrs.G, parametrs.B));
		SelectObject(hDC, Pen);

		MoveToEx(hDC, x + _centre.X, y + _centre.Y, NULL);
		LineTo(hDC, x + _centre.X, y + _centre.Y);
	}
}
void Circle::Shift(const Point & xy)
{
	_centre += xy;
}
void Circle::TurnShape(double n, Point XY)
{
	Point delta;
	delta.X = 0.0 - XY.X;
	delta.Y = 0.0 - XY.Y;
	_centre += delta;
	TurnPoint(n, _centre);
	_centre -= delta;
}
Circle::Circle(Point p, int r)
{
	_centre = p; _radius = r;
	SetStandartColor();

}


