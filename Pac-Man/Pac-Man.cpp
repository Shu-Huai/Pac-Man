#include <iostream>
#include "conio.h"
#define W 0
#define B 1
#define K 2
#define P 3
#define G 4
using namespace std;
class MAP
{
protected:
	static int map[19][19];
public:
	MAP()
	{

	}
	void drawmap();
	int GetBeanNumber();
};
class Player :public MAP
{
private:
	int x, y;
public:
	Player(int X = 18, int Y = 9);
	int GetPX();
	int GetPY();
	void SetPlayerPosition(int X, int Y);
};
class Ghost :public MAP
{
private:
	int x, y;
public:
	Ghost(int X = 1, int Y = 1);
	int GetPX();
	int GetPY();
	void SetGhostPosition(int X, int Y);
};
int MAP::map[19][19] = {
	W, W, W, W, W, W, W, W, W, B, W, W, W, W, W, W, W, W, W,
	W, B, B, B, B, B, B, B, B, B, B, B, B, B, B, B, B, B, W,
	W, B, B, W, B, B, W, W, W, B, W, W, W, B, B, W, B, B, W,
	W, B, W, W, B, B, B, B, B, B, B, B, B, B, B, W, W, B, W,
	W, B, W, B, B, B, W, W, W, B, W, W, W, B, B, B, W, B, W,
	W, B, W, B, B, B, B, B, B, B, B, B, B, B, B, B, W, B, W,
	W, B, B, B, B, B, W, W, B, B, B, W, W, B, B, B, B, B, W,
	W, B, W, B, B, B, B, B, B, B, B, B, B, B, B, B, W, B, W,
	W, B, W, B, B, B, B, B, W, B, W, B, B, B, B, B, W, B, W,
	B, B, B, B, B, B, B, B, W, W, W, B, B, B, B, B, B, B, B,
	W, B, W, B, B, B, B, B, B, B, B, B, B, B, B, B, W, B, W,
	W, B, W, B, B, W, B, B, B, B, B, B, B, W, B, B, W, B, W,
	W, B, W, B, W, W, W, B, B, B, B, B, W, W, W, B, W, B, W,
	W, B, B, B, B, W, B, B, B, B, B, B, B, W, B, B, B, B, W,
	W, B, W, W, B, B, B, B, B, B, B, B, B, B, B, W, W, B, W,
	W, B, B, B, B, B, B, B, B, B, B, B, B, B, B, B, B, B, W,
	W, B, B, B, B, W, W, W, B, W, B, W, W, W, B, B, B, B, W,
	W, B, B, B, B, W, B, B, B, B, B, B, B, W, B, B, B, B, W,
	W, W, W, W, W, W, W, W, W, P, W, W, W, W, W, W, W, W, W,
};
Player::Player(int X, int Y) :MAP()
{
	x = X;
	y = Y;
}
int Player::GetPX()
{
	return x;
}
int Player::GetPY()
{
	return y;
}
void Player::SetPlayerPosition(int X, int Y)
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
	if (map[x][y] != W)
	{
		map[tempx][tempy] = K;
		map[x][y] = P;
	}
	else
	{
		x = tempx;
		y = tempy;
	}
}
Ghost::Ghost(int X, int Y) :MAP()
{
	x = X;
	y = Y;
	map[x][y] = G;
}
int Ghost::GetPX()
{
	return x;
}
int Ghost::GetPY()
{
	return y;
}
void Ghost::SetGhostPosition(int X, int Y)
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
	if (map[x][y] != W)
	{
		map[tempx][tempy] = B;
		map[x][y] = G;
	}
	else
	{
		x = tempx;
		y = tempy;
	}
}
void MAP::drawmap()
{
	system("cls");
	for (int i = 0; i < 19; i++)
	{
		for (int j = 0; j < 19; j++)
		{
			if (map[i][j] == 0)
			{
				cout << "□";
			}
			else if (map[i][j] == 1)
			{
				cout << "·";
			}
			else if (map[i][j] == 2)
			{
				cout << "  ";
			}
			else if (map[i][j] == 3)
			{
				cout << "★";
			}
			else if (map[i][j] == 4)
			{
				cout << "囧";
			}
		}
		cout << endl;
	}
}
int MAP::GetBeanNumber()
{
	int count = 0;
	for (int i = 0; i < 19; i++)
	{
		for (int j = 0; j < 19; j++)
		{
			if (map[i][j] == B)
			{
				count++;
			}
		}
	}
	return count;
}
int main()
{
	MAP first;
	Player PL;
	Ghost GH0(17, 1);
	Ghost GH1(17, 17);
	first.drawmap();
	while (first.GetBeanNumber() != 0)
	{
		char input = _getch();
		if (input == 'w')
		{
			PL.SetPlayerPosition(-1, 0);
			GH0.SetGhostPosition(1 - (rand() % (2 + 1)), 1 - (rand() % (2 + 1)));
			GH1.SetGhostPosition(1 - (rand() % (2 + 1)), 1 - (rand() % (2 + 1)));
			first.drawmap();
		}
		else if (input == 'a')
		{
			PL.SetPlayerPosition(0, -1);
			GH0.SetGhostPosition(1 - (rand() % (2 + 1)), 1 - (rand() % (2 + 1)));
			GH1.SetGhostPosition(1 - (rand() % (2 + 1)), 1 - (rand() % (2 + 1)));
			first.drawmap();
		}
		else if (input == 's')
		{
			PL.SetPlayerPosition(1, 0);
			GH0.SetGhostPosition(1 - (rand() % (2 + 1)), 1 - (rand() % (2 + 1)));
			GH1.SetGhostPosition(1 - (rand() % (2 + 1)), 1 - (rand() % (2 + 1)));
			first.drawmap();
		}
		else if (input == 'd')
		{
			PL.SetPlayerPosition(0, 1);
			GH0.SetGhostPosition(1 - (rand() % 3), 1 - (rand() % 3));
			GH1.SetGhostPosition(1 - (rand() % 3), 1 - (rand() % 3));
			first.drawmap();
		}
	}
	return 0;
}