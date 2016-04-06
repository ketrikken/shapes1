#pragma once

#include <string>
enum commands { ÑreateFigur = 0, ShiftFigur, TurnFigur, Rotate, Error, DrawFigur};

class Command
{
public:
	static void Tolower(std::string & s);
	static int WhatCommand(std::string & s);
};