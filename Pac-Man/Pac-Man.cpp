#include <iostream>
#include <Windows.h>
#include <conio.h>
#define W 0
#define B 1
#define K 2
#define P 3
#define G 4
using namespace std;
class MAP
{
protected:
	int map[19][19] = {
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

public:
	MAP()
	{
	}
	void DrawMap(int score);
	void SetMap(int X, int Y, int condition);
	int GetMap(int X, int Y);
	int GetBeanNumber();
};
class Player
{
private:
	int x, y;
	int score;

public:
	Player(int X, int Y, MAP& M);
	int GetPX() const;
	int GetPY() const;
	int GetScore() const;
	void SetPlayerPosition(int X, int Y, MAP& M);
};
class Ghost
{
private:
	int x, y;

public:
	Ghost(int X, int Y, MAP& M);
	int GetPX();
	int GetPY();
	void Ghostmove(MAP& M);
};
void MAP::SetMap(int X, int Y, int condition)
{
	map[X][Y] = condition;
}
int MAP::GetMap(int X, int Y)
{
	return map[X][Y];
}
Player::Player(int X, int Y, MAP& M)
{
	x = X;
	y = Y;
	M.SetMap(X, Y, P);
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
void Player::SetPlayerPosition(int X, int Y, MAP& M)
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
	if (M.GetMap(x, y) != W)
	{
		if (M.GetMap(x, y) == G)
		{
			throw (int)0;
		}
		if (M.GetMap(x, y) == B)
		{
			score++;
		}
		M.SetMap(tempx, tempy, K);
		M.SetMap(x, y, P);
	}
	else
	{
		x = tempx;
		y = tempy;
	}
}
Ghost::Ghost(int X, int Y, MAP& M)
{
	x = X;
	y = Y;
	M.SetMap(X, Y, G);
}
int Ghost::GetPX()
{
	return x;
}
int Ghost::GetPY()
{
	return y;
}
void Ghost::Ghostmove(MAP& M)
{
	int tempx = x, tempy = y, myrand = 0;
	bool mov = 0;
	int orimap;
	while (mov == 0)
	{
		myrand = rand() % 4 +1;
		switch (myrand)
		{
		case 1:
			if (M.GetMap(tempx + 1, tempy) != W && M.GetMap(tempx + 1, tempy) != G)
			{
				x = x + 1;
				orimap = M.GetMap(x, y);
				M.SetMap(tempx, tempy, orimap);
				M.SetMap(x, y, G);
				mov = 1;
			}
			else
			{
				x = tempx;
				y = tempy;
			}
			break;
		case 2:
			if (M.GetMap(tempx - 1, tempy) != W && M.GetMap(tempx - 1, tempy) != G)
			{
				x = x - 1;
				orimap = M.GetMap(x, y);
				M.SetMap(tempx, tempy, orimap);
				M.SetMap(x, y, G);
				mov = 1;
			}
			else
			{
				x = tempx;
				y = tempy;
			}
			break;
		case 3:
			if (M.GetMap(tempx, tempy + 1) != W && M.GetMap(tempx, tempy + 1) != G)
			{
				y = y + 1;
				orimap = M.GetMap(x, y);
				M.SetMap(tempx, tempy, orimap);
				M.SetMap(x, y, G);
				mov = 1;
			}
			else
			{
				x = tempx;
				y = tempy;
			}
			break;
		case 4:
			if (M.GetMap(tempx, tempy - 1) != W && M.GetMap(tempx, tempy - 1) != G)
			{
				y = y - 1;
				orimap = M.GetMap(x, y);
				M.SetMap(tempx, tempy, orimap);
				M.SetMap(x, y, G);
				mov = 1;
			}
			else
			{
				x = tempx;
				y = tempy;
			}
			break;
		}
	}
	mov = 0;
}
void MAP::DrawMap(int score)
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
	cout << "Your score is: " << score << endl;
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
bool dead()
{
	if (MessageBox(NULL, "You are dead. Press enter to retry. ", "You are dead. ", MB_OKCANCEL) == IDOK)
	{
		return 1;
	}
	else
	{
		return 0;
	}
}
int main()
{
	system("color F1");
begin:
	MAP first;
	Player PL(18, 9, first);
	Ghost GH0(17, 1, first);
	Ghost GH1(17, 17, first);
	Ghost GH2(1, 17, first);
	Ghost GH3(1, 1, first);
	first.DrawMap(0);
	int tempx = 0;
	int tempy = 0;
	while (first.GetBeanNumber() != 0)
	{
		char input;
		while (!_kbhit())
		{
			/*初始化位置*/
			try
			{
				PL.SetPlayerPosition(tempx, tempy, first);
				GH0.Ghostmove(first);
				GH1.Ghostmove(first);
				GH2.Ghostmove(first);
				GH3.Ghostmove(first);
			}
			/*死亡判断 四个鬼*/
			catch (int)
			{
				if (dead())
				{
					Sleep(100);
					goto begin;
				}
				else
				{
					return 0;
				}
			}
			first.DrawMap(PL.GetScore());
			Sleep(500);
		}
		
		/*移动控制*/
		input = _getch();
		if (input == 'w')
		{
			tempx = -1;
			tempy = 0;
		}
		else if (input == 'a')
		{
			tempx = 0;
			tempy = -1;
		}
		else if (input == 's')
		{
			tempx = 1;
			tempy = 0;
		}
		else if (input == 'd')
		{
			tempx = 0;
			tempy = 1;
		}
	}
	//胜利判断
	if (MessageBox(NULL, "You  win！ Press enter to restart. ", "You  win！", MB_OKCANCEL) == IDOK)
	{
		goto begin;
	}
	return 0;
}