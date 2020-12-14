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
begin:
	Map first;
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
			try
			{
				PL.SetPlayerPosition(tempx, tempy, first);
				GH0.Ghostmove(first);
				GH1.Ghostmove(first);
				GH2.Ghostmove(first);
				GH3.Ghostmove(first);
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
		else if (input == 27)
		{
			Write(first);
			system("pause");
		}
	}
	if (MessageBox(NULL, "You  win！ Press enter to restart. ", "You  win！", MB_OKCANCEL) == IDOK)
	{
		goto begin;
	}
	return 0;
}