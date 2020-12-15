#include <fstream>
#include "File.h"
using namespace std;
void  Write(Map& MAP, Player& PL, Ghost*& GH)
{
	fstream MapData("MapData.dat", ios::out | ios::binary | ios::trunc);
	if (!MapData)
	{
		return;
	}
	MapData.write((char*)&MAP, sizeof(Map));
	MapData.write((char*)&PL, sizeof(Player));
	for (int i = 0; i < 4; i++)
	{
		Ghost temp = GH[i];
		MapData.write((char*)&temp, sizeof(Ghost));
	}
	MapData.close();
}
void Read(Map& MAP, Player& PL, Ghost*& GH)
{
	ifstream MapData("MapData.dat", ios::in | ios::binary);
	if (!MapData)
	{
		return;
	}
	MapData.read((char*)&MAP, sizeof(Map));
	MapData.read((char*)&PL, sizeof(Player));
	for (int i = 0; i < 4; i++)
	{
		Ghost temp;
		MapData.read((char*)&temp, sizeof(Ghost));
		GH[i] = temp;
	}
	MapData.close();
}