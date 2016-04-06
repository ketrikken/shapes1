#pragma once
#include <sstream>
class SafeReading
{
public:
	template< class T >
	static bool Read(std::istream& in, T& res)
	{
		std::string s;
		in >> s;

		std::istringstream sin(s);
		if (!(sin >> res))
		{
			return 0;
		}

		if (!sin.eof()) return 0;

		return 1;
	}
	template< class T >
	static bool Read(T& res)
	{
		std::string s;
		std::cin >> s;

		std::istringstream sin(s);
		if (!(sin >> res))
		{
			return 0;
		}

		if (!sin.eof()) return 0;

		return 1;
	}

	template< class T >
	static void ReadWhile(T& n)
	{
		while (!Read(n)) {}
	}
private:
	
};