#include <iostream>
#include "Ghost.h"
using namespace std;
Ghost::Ghost()
{
	_x = 0;
	_y = 0;
	_originelem = 0;
}
Ghost::Ghost(int X, int Y, Map& M)
{
	_x = X;
	_y = Y;
	M._map[X][Y] = G;
	_originelem = 1;
}
int Ghost::GetPX()
{
	return _x;
}
int Ghost::GetPY()
{
	return _y;
}
void Ghost::Ghostmove(Map& M)
{
	int OriX = _x;
	int OriY = _y;
	int FinalX = 0;
	int FinalY = 0;
	int myrand = 0;
	bool mov = 0;
	while (mov == 0)
	{
		myrand = rand() % 4 + 1;
		switch (myrand)
		{
		case 1:
			FinalX = OriX + 1;
			FinalY = OriY;
			break;
		case 2:
			FinalX = OriX - 1;
			FinalY = OriY;
			break;
		case 3:
			FinalX = OriX;
			FinalY = OriY + 1;
			break;
		case 4:
			FinalX = OriX;
			FinalY = OriY - 1;
			break;
		}
		if (FinalX > 18)
		{
			FinalX -= 19;
		}
		if (FinalY > 18)
		{
			FinalY -= 19;
		}
		if (FinalX < 0)
		{
			FinalX += 19;
		}
		if (FinalY < 0)
		{
			FinalY += 19;
		}
		if (M._map[FinalX][FinalY] != W && M._map[FinalX][FinalY] != G)
		{
			M._map[_x][_y] = _originelem;
			_x = FinalX;
			_y = FinalY;
			_originelem = M._map[FinalX][FinalY];
			M._map[_x][_y] = G;
			if (_originelem == P)
			{
				throw int(0);
			}
			mov = 1;
		}
		else
		{
			_x = OriX;
			_y = OriY;
		}
	}
	mov = 0;
}

