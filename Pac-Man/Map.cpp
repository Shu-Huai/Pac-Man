#include <iostream>
#include "Map.h"
using namespace std;
void Map::DrawMap(int score)
{
	system("cls");
	string MapElems[5] = { "¡ö", "¡£" ,"  " ,"¡ï" ,"‡å" };
	for (int i = 0; i < 19; i++)
	{
		for (int j = 0; j < 19; j++)
		{
			cout << MapElems[_map[i][j]];
		}
		cout << endl;
	}
	cout << "Your score is: " << score << endl;
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