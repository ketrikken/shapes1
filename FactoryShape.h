#pragma once
#include "Circle.h"
#include "Quadrangle.h"
#include "SefeReading.h"
#include <sstream>
enum Shape_ID { Circle_ID = 0, Quadrangle_ID };
class FactoryShape
{
public:
	static IFigure* CreateShape(const std::string & command)
	{
		std::istringstream ccin(command);
		std::string kindShape;
		ccin >> kindShape;
		int id = ReturnID(kindShape);

		switch (id)
		{
		case Circle_ID: return CreateCircle(ccin);
		case Quadrangle_ID: return CreateQuadrangle(ccin);
		default: return nullptr; 
		}


	}
private:
	static Shape_ID ReturnID(std::string kindShape)
	{
		if (kindShape == "circle") return Circle_ID;
		else if (kindShape == "quadrangle") return Quadrangle_ID;
	}

	static Circle* CreateCircle(std::istream& in)
	{
		
		double radius;
		if (!SafeReading::Read(in, radius)) return nullptr;

		Point center;
		if (!SafeReading::Read(in, center.X) && !!SafeReading::Read(in, center.Y)) return nullptr;
		

		return new Circle(center,radius);
	}

	static Quadrangle* CreateQuadrangle(std::istream& in)
	{
		

		int count;
		if (!SafeReading::Read(in, count)) return nullptr;

		std::vector<Point> mas;
		for (int i = 0; i < count; ++i)
		{
			Point vertex;
			in >> vertex;
			mas.push_back(vertex);
		}
		return new Quadrangle(mas);
	}
};