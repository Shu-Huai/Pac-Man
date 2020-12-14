#include <iostream>
#include "Map.h"
using namespace std;
void Map::DrawMap(int score)
{
	system("cls");
	for (int i = 0; i < 19; i++)
	{
		for (int j = 0; j < 19; j++)
		{
			if (map[i][j] == 0)
			{
				cout << "¡ö";
			}
			else if (map[i][j] == 1)
			{
				cout << "¡£";
			}
			else if (map[i][j] == 2)
			{
				cout << "  ";
			}
			else if (map[i][j] == 3)
			{
				cout << "¡ï";
			}
			else if (map[i][j] == 4)
			{
				cout << "‡å";
			}
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
			if (map[i][j] == B)
			{
				count++;
			}
		}
	}
	return count;
}