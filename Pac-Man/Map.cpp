#include <iostream>
#include<windows.h>
#include "Map.h"
using namespace std;
void SetConSoleCoordinate(int x, int y)
{
	COORD pos;
	pos.X = x;
	pos.Y = y;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), pos);
}
void Map::DrawMap(int score)
{
	string MapElems[5] = { "¡ö", "¡£" ,"  " ,"¡ï" ,"‡å" };
	for (int i = 0; i < 19; i++)
	{
		for (int j = 0; j < 19; j++)
		{
			SetConSoleCoordinate(j * 2, i);
			cout << MapElems[_map[i][j]];
		}
	}
	cout << endl
		<< "Your score is: " << score << endl;
}
int Map::GetBeanNumber()
{
	int count = 0;
	for (int i = 0; i < 19; i++)
	{
		for (int j = 0; j < 19; j++)
		{
			if (_map[i][j] == B)
			{
				count++;
			}
		}
	}
	return count;
}
void Map::SetMap(int X, int Y, int condition)
{
	_map[X][Y] = condition;
}