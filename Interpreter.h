#pragma once
#include "FactoryShape.h"
#include "Command.h"
#include "ArgumentsCreator.h"
#include "SefeReading.h"
#include <fstream> 
#include <map>



class Interpreter
{
public:
	void Start();

private:

	static void printError(std::string s);
	void CaseRotate();
	void Case—reateFigur();
	void CaseTurnFigur();
	void CaseShiftFigur();
	void CaseDrawFigur();
	bool FindName(const std::string& name) const;
	std::map<std::string, IFigure*> _figurs;
};
