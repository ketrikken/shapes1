#pragma once
#include "Color.h"
class ColorParametrs
{
public:
	Color ReadColorParametrs()
	{
		_rgb.R = 2, _rgb.G = 70, _rgb.B = 255;
		std::cin >> _flag;
		if (_flag)
		{
			std::cin >> _rgb;
		}
		return _rgb;
	}
	int GetFlag()
	{
		return _flag;
	}

private:
	int _flag;
	Color _rgb;

};