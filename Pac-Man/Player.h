#pragma once
#include "Map.h"
class Player
{
protected:
	int _x, _y;
	int _score;

public:
	Player();
	Player(int X, int Y, Map& M);
	int GetPX() const;
	int GetPY() const;
	int GetScore() const;
	void SetPlayerPosition(int X, int Y, Map& M);
};