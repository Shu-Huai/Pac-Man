#pragma once
#include "Map.h"
class Ghost
{
private:
	int _x, _y;
	int _originelem;

public:
	Ghost();
	Ghost(int X, int Y, Map& M);
	int GetPX();
	int GetPY();
	void Ghostmove(Map& M);
};