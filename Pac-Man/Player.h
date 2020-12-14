#pragma once
#include "Map.h"
class Player
{
private:
	int x, y;
	int score;

public:
	Player();
	Player(int X, int Y, Map& M);
	int GetPX() const;
	int GetPY() const;
	int GetScore() const;
	void SetPlayerPosition(int X, int Y, Map& M);
};