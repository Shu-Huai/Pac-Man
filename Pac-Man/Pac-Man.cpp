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
	Player PL;
	Ghost GH0;
	Ghost GH1;
	Ghost GH2;
	Ghost GH3;
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
		PL = Player(18, 9, first);
		GH0 = Ghost(17, 1, first);
		GH1 = Ghost(17, 17, first);
		GH2 = Ghost(1, 17, first);
		GH3 = Ghost(1, 1, first);
		break;
	case '2':
		Read(first);
		break;
	case '3':
		return 0;
		break;
	}
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