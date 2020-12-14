#include <iostream>
#include "Ghost.h"
using namespace std;
Ghost::Ghost()
{
	x = 0;
	y = 0;
	O = 0;
}
Ghost::Ghost(int X, int Y, Map& M)
{
	x = X;
	y = Y;
	M.map[X][Y] = G;
	O = 1;
}
int Ghost::GetPX()
{
	return x;
}
int Ghost::GetPY()
{
	return y;
}
void Ghost::Ghostmove(Map& M)
{
	int OriX = x;
	int OriY = y;
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
		if (M.map[FinalX][FinalY] != W && M.map[FinalX][FinalY] != G)
		{
			M.map[x][y] = O;
			x = FinalX;
			y = FinalY;
			O = M.map[FinalX][FinalY];
			M.map[x][y] = G;
			if (O == P)
			{
				throw int(0);
			}
			mov = 1;
		}
		else
		{
			x = OriX;
			y = OriY;
		}
	}
	mov = 0;
}