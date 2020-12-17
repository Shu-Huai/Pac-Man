#include <iostream>
#include "Player.h"
using namespace std;
Player::Player()
{
	_x = 0;
	_y = 0;
	_score = 0;
}
Player::Player(int X, int Y, Map& M)
{
	_x = X;
	_y = Y;
	M._map[X][Y] = P;
	_score = 0;
}
int Player::GetPX() const
{
	return _x;
}
int Player::GetPY() const
{
	return _y;
}
int Player::GetScore() const
{
	return _score;
}
void Player::SetPlayerPosition(int X, int Y, Map& M)
{
	int tempx = _x;
	int tempy = _y;
	_x += X;
	_y += Y;
	if (_x > 18)
	{
		_x -= 19;
	}
	if (_y > 18)
	{
		_y -= 19;
	}
	if (_x < 0)
	{
		_x += 19;
	}
	if (_y < 0)
	{
		_y += 19;
	}
	if (M._map[_x][_y] != W)
	{
		if (M._map[_x][_y] == G)
		{
			M._map[tempx][tempy] = K;
			throw (int)0;
		}
		if (M._map[_x][_y] == B)
		{
			_score++;
		}
		M._map[tempx][tempy] = K;
		M._map[_x][_y] = P;
	}
	else
	{
		_x = tempx;
		_y = tempy;
	}
}