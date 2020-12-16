#include <iostream>
#include <Windows.h>
#include <conio.h>
#include "File.h"
#include "Ghost.h"
#include "Map.h"
#include "Player.h"
using namespace std;
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
	int Gnum = 4;//鬼数量

	int gx;//集中于gx、gy周围
	int gy;

	int Pause = 0;

begin:
	Map first;
	Player PL;
	Ghost* GH = new Ghost[Gnum];
	cout << "               Pac Man                " << endl
		<< endl
		<< "--------------------------------------" << endl
		<< endl
		<< "        1. Begin a new game." << endl
		<< endl
		<< "        2. Resume." << endl
		<< endl
		<< "        3. Exit." << endl
		<< endl;
	char Select = 0;
	Select = _getch();
	switch (Select)
	{
	case '1':
		gx = 4;
		gy = 4;
		PL = Player(18, 9, first);
		for (int g = 0; g < Gnum; g++)
		{
			GH[g] = Ghost(gx++, gy++, first);
		}
		break;
	case '2':
		Read(first, PL, GH);
		break;
	case '3':
		return 0;
		break;
	}
	first.DrawMap(PL.GetScore());
	int tempx = 0;
	int tempy = 0;
	while (first.GetBeanNumber() != 0)
	{
		char input;
		while (!_kbhit())
		{

			if (Pause == 0)
			{
			try
			{
				PL.SetPlayerPosition(tempx, tempy, first);//player移动 L101-121
				for (int g = 0; g < Gnum; g++)//Ghost移动
				{
					GH[g].Ghostmove(first);
				}
			}
				catch (int)
				{
					first.DrawMap(PL.GetScore());
					if (dead())
					{
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
		}
		input = _getch();
		if (input == 'w')
		{
			tempx = -1;
			tempy = 0;
			Pause = 0;
		}
		else if (input == 'a')
		{
			tempx = 0;
			tempy = -1;
			Pause = 0;
		}
		else if (input == 's')
		{
			tempx = 1;
			tempy = 0;
			Pause = 0;
		}
		else if (input == 'd')
		{
			tempx = 0;
			tempy = 1;
			Pause = 0;
		}
		else if (input == 27)
		{
			Write(first, PL, GH);
			Pause = 1;
			tempx = 0;
			tempy = 0;

			//system("pause");
		}
	}
	if (first.GetBeanNumber() == 0)
	{
		if (MessageBox(NULL, "You  win！ Press enter to restart. ", "You  win！", MB_OKCANCEL) == IDOK)
		{
			goto begin;
		}
	}
	
	return 0;
}