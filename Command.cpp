#include "Command.h"

void Command::Tolower(std::string & s)
{
	for (std::string::iterator it = s.begin(); it != s.end(); ++it)
		(*it) = tolower(*it);
}
int Command::WhatCommand(std::string & s)
{
	Tolower(s);
	if (s.find("rotate") != s.npos)return Rotate;
	if (s.find("create") != s.npos) return ÑreateFigur;
	if (s.find("shift") != s.npos) return ShiftFigur;
	if (s.find("turn") != s.npos) return TurnFigur;
	if (s.find("draw") != s.npos) return DrawFigur;
	return Error;
}