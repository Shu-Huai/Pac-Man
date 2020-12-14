#pragma once
#include "Map.h"
class Ghost
{
private:
	int x, y;
	int O;

public:
	Ghost(int X, int Y, Map& M);
	int GetPX();
	int GetPY();
	void Ghostmove(Map& M);
};