#include "Interpreter.h"

bool Interpreter::FindName(const std::string& name) const 
{
	auto itFigure = _figurs.find(name);
	if (itFigure == _figurs.end())
		return 0;
	return 1;
}
void Interpreter::Start()
{
	std::ofstream error("error_file.txt");
	FILE *file = freopen("input_file.txt", "r", stdin);
	while (!feof(file))
	{
		std::string strCommand;
		if (SafeReading().Read(strCommand))
		{
			int command = Command::WhatCommand(strCommand);
			switch (command)
			{
			case Rotate:
			{
				CaseRotate();
				break;
			}
			case —reateFigur:
			{
				Case—reateFigur();
				break;
			}
			case TurnFigur:
			{
				CaseTurnFigur();
				break;
			}
			case ShiftFigur:
			{
				CaseShiftFigur();
				break;
			}
			case DrawFigur:
			{
				CaseDrawFigur();
				break;
			}
			case Error:
			{
				printError("Error");
				break;
			}
			default:
				std::cout << "magic error" << std::endl;
			}
		}
	}

}
void Interpreter::printError(std::string s)
{
	freopen("error_file.txt", "a", stdout);
	std::cout << s << std::endl;
}
void Flag(const int flag, int& i, int & j, int &k)
{
	i = j = k = 0;
	switch (flag)
	{
	case 1:
		i = 1;
		break;
	case 2:
		j = 1;
		break;
	case 3:
		k = 1;
		break;
	case 4:
		i = 1, j = 1, k = 1;
	case 5:
		break;
	default:
		break;
	}
}
void Interpreter::CaseRotate()
{
	std::string name;
	if (SafeReading().Read(name))
	{
		if (!FindName(name))
		{
			printError("not founded");
			return;
		}
		int first, last, step;
		if (SafeReading().Read(first) && SafeReading().Read(last) && SafeReading().Read(step))
		{
			Point XY;
			if (SafeReading().Read(XY.X) && SafeReading().Read(XY.Y))
			{
				ColorParametrs colorParametrs;
				Color tempColor = colorParametrs.ReadColorParametrs();
				int flag = colorParametrs.GetFlag();
				int iR, jG, kB;
				Flag(flag, iR, jG, kB);
				auto itFigure = _figurs[name];
				for (int i = first; i < last; i += step)
				{
					itFigure->TurnShape(i, XY);
					tempColor.SetParametrs(tempColor.R+ iR*i, tempColor.G + jG * i, tempColor.B + kB * i);
					itFigure->DrawShape(tempColor);
				}
				return;	
			}
		}
	}
	printError("reading error");
	return;
}

void Interpreter::Case—reateFigur()
{

	std::string name;
	std::cin >> name;
	std::string command;
	std::getline(std::cin, command);
	auto temp = FactoryShape::CreateShape(command);
	if (temp != nullptr)
	{
		_figurs[name] = temp;
	}
	else
	{
		printError("error create");
	}

}
void Interpreter::CaseTurnFigur()
{
	std::string name;
	if (SafeReading().Read(name))
	{
		if (!FindName(name))
		{
			printError(name + "not founded");
			return;
		}
		double degrees;
		if (SafeReading().Read(degrees))
		{
			Point XY;
			if (SafeReading().Read(XY.X) && SafeReading().Read(XY.Y))
			{
				auto itFigure = _figurs[name];
				itFigure->TurnShape(degrees, XY);
				return;
			}
		}
	}
	printError("not turn figur");
}
void Interpreter::CaseShiftFigur()
	{
		std::string name;
		if (SafeReading().Read(name))
		{
			if (!FindName(name))
			{
				printError(name + "not founded");
				return;
			}
			Point XY;
			if (SafeReading().Read(XY.X) && SafeReading().Read(XY.Y))
			{
				auto itFigure = _figurs[name];
				itFigure->Shift(XY);
				return;
			}
		}
		printError("not shift figur");
	}
void Interpreter::CaseDrawFigur()
{
	std::string name;
	if (SafeReading().Read(name))
	{
		if (!FindName(name))
		{
			printError(name + "not founded");
			return;
		}
		Color tempColor = ColorParametrs().ReadColorParametrs();
		auto itFigure = _figurs[name];
		itFigure->DrawShape(tempColor);
		return;
		
	}
	printError("not draw figur");
}