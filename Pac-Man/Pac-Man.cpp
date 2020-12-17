#include <iostream>
#include <Windows.h>
#include <conio.h>
#include "File.h"
#include "Ghost.h"
#include "Map.h"
#include "Player.h"
constexpr auto GhostNumber = 4;
using namespace std;
int main();
class Interface
{
public:
	void SetConSoleCoordinate(int x, int y)
	{
		COORD POS;
		POS.X = x;
		POS.Y = y;
		SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), POS);
	}
	void BeginANewGame(Map& MAP, Player& PL, Ghost*& GH)
	{
		PL = Player(18, 9, MAP);
		int InitGhPos[GhostNumber * 2] = { 1, 1, 1, 17, 17, 1, 17, 17 };
		for (int i = 0; i < GhostNumber * 2; i += 2)
		{
			GH[i / 2] = Ghost(InitGhPos[i], InitGhPos[i + 1], MAP);
		}
	}
	void LoadGame(Map& MAP, Player& PL, Ghost*& GH)
	{
		Read(MAP, PL, GH);
	}
	void StartMenu(Map& MAP, Player& PL, Ghost*& GH)
	{
		system("cls");
		cout << "               Pac Man                " << endl
			<< endl
			<< "--------------------------------------" << endl
			<< endl
			<< "        1. Begin a new game." << endl
			<< endl
			<< "        2. Load game." << endl
			<< endl
			<< "        3. Exit." << endl
			<< endl;
		char Select = _getch();
		switch (Select)
		{
		case '1':
			BeginANewGame(MAP, PL, GH);
			break;
		case '2':
			LoadGame(MAP, PL, GH);
			break;
		case '3':
			exit(0);
		}
	}
	void PauseMenu(Map& MAP, Player& PL, Ghost*& GH)
	{
		SetConSoleCoordinate(0, 4);
		cout << "--------------------------------------" << endl
			<< "|              Pac Man               |" << endl
			<< "|                                    |" << endl
			<< "|------------------------------------|" << endl
			<< "|                                    |" << endl
			<< "|          1. Resume.                |" << endl
			<< "|                                    |" << endl
			<< "|          2. Load game.             |" << endl
			<< "|                                    |" << endl
			<< "|          3. Save and Exit.         |" << endl
			<< "--------------------------------------" << endl;
		char Select = _getch();
		switch (Select)
		{
		case '1':
			return;
			break;
		case '2':
			LoadGame(MAP, PL, GH);
			system("cls");
			break;
		case '3':
			Write(MAP, PL, GH);
			StartMenu(MAP, PL, GH);
		}
	}
	void Dead()
	{
		if (MessageBox(NULL, "You are dead. Press enter to retry. ", "You are dead. ", MB_OKCANCEL) == IDOK)
		{
			main();
		}
		else
		{
			exit(0);
		}
	}
	void Win()
	{
		if (MessageBox(NULL, "You  win！ Press enter to restart. ", "You  win！", MB_OKCANCEL) == IDOK)
		{
			main();
		}
		else
		{
			exit(0);
		}
	}
} Menu;
int main()
{
	system("color F1");
	int Pause = 0;
	Map MAP;
	Player PL;
	Ghost* GH = new Ghost[GhostNumber];
	Menu.StartMenu(MAP, PL, GH);
	MAP.DrawMap(PL.GetScore());
	system("pause");
	system("cls");
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
					for (int i = 0; i < GhostNumber; i++)//Ghost移动
					{
						GH[i].Ghostmove(MAP);
					}
				}
				catch (int)
				{
					MAP.DrawMap(PL.GetScore());
					delete[]GH;
					Menu.Dead();
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
			Pause = 0;
			tempx = 0;
			tempy = 0;
		}
	}
	Menu.Win();
	return 0;
}