#include <iostream>
#include <Windows.h>
#include <conio.h>
#include "File.h"
#include "Ghost.h"
#include "Map.h"
#include "Player.h"
constexpr auto GhostNumber = 4;
using namespace std;
class Interface
{
public:
	void BeginANewGame(Map& MAP, Player& PL, Ghost*& GH)
	{
		PL = Player(18, 9, MAP);
		int InitGhPos[GhostNumber * 2] = { 1, 1, 1, 17, 17, 1, 17, 17 };
		for (int g = 0; g < GhostNumber * 2; g += 2)
		{
			GH[g / 2] = Ghost(InitGhPos[g], InitGhPos[g + 1], MAP);
		}
	}
	void Resume(Map& Map, Player& PL, Ghost*& GH)
	{
		Read(Map, PL, GH);
	}
	void StartMenu(Map& MAP, Player& PL, Ghost*& GH)
	{
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
			BeginANewGame(MAP, PL, GH);
			break;
		case '2':
			Resume(MAP, PL, GH);
			break;
		case '3':
			exit(0);
		}
	}
	void PauseMenu(Map& MAP, Player& PL, Ghost*& GH)
	{
		Write(MAP, PL, GH);
	}
	bool Dead()
	{
		return MessageBox(NULL, "You are dead. Press enter to retry. ", "You are dead. ", MB_OKCANCEL)== IDOK;
	}
	bool Win()
	{
		return MessageBox(NULL, "You  win！ Press enter to restart. ", "You  win！", MB_OKCANCEL) == IDOK;
	}
} Menu;
int main()
{
begin:
	system("color F1");
	system("cls");
	int Pause = 0;
	Map MAP;
	Player PL;
	Ghost* GH = new Ghost[GhostNumber];
	Menu.StartMenu(MAP, PL, GH);
	MAP.DrawMap(PL.GetScore());
	system("pause");
	int tempx = 0;
	int tempy = 0;
	while (MAP.GetBeanNumber() != 0)
	{
		char input;
		while (!_kbhit())
		{
			if (!Pause)
			{
				try
				{
					PL.SetPlayerPosition(tempx, tempy, MAP);//player移动 L101-121
					for (int g = 0; g < GhostNumber; g++)//Ghost移动
					{
						GH[g].Ghostmove(MAP);
					}
				}
				catch (int)
				{
					MAP.DrawMap(PL.GetScore());
					delete[]GH;
					if (Menu.Dead())
					{
						goto begin;
					}
					else
					{
						exit(0);
					}
				}
				MAP.DrawMap(PL.GetScore());
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
			Menu.PauseMenu(MAP, PL, GH);
			Pause = 1;
			tempx = 0;
			tempy = 0;
		}
	}
	if (Menu.Win())
	{
		goto begin;
	}
	else
	{
		exit(0);
	}
	return 0;
}