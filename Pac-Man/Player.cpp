#include <iostream>
#include "Player.h"
using namespace std;
Player::Player(int X, int Y, Map& M)
{
	x = X;
	y = Y;
	M.map[X][Y] = P;
	score = 0;
}
int Player::GetPX() const
{
	return x;
}
int Player::GetPY() const
{
	return y;
}
int Player::GetScore() const
{
	return score;
}
void Player::SetPlayerPosition(int X, int Y, Map& M)
{
	int tempx = x;
	int tempy = y;
	x += X;
	y += Y;
	if (x > 18)
	{
		x -= 19;
	}
	if (y > 18)
	{
		y -= 19;
	}
	if (x < 0)
	{
		x += 19;
	}
	if (y < 0)
	{
		y += 19;
	}
	if (M.map[x][y] != W)
	{
		if (M.map[x][y] == G)
		{
			M.map[tempx][tempy] = K;
			throw (int)0;
		}
		if (M.map[x][y] == B)
		{
			score++;
		}
		M.map[tempx][tempy] = K;
		M.map[x][y] = P;
	}
	else
	{
		x = tempx;
		y = tempy;
	}
}