#include <fstream>
#include "File.h"
using namespace std;
void  Write(Map& Map, Player& PL, Ghost Gh[4])
{
	fstream MapData("MapData.dat", ios::out | ios::trunc);  // �˴�ʡ���ļ��Ƿ��ʧ�ܵ��ж�
	MapData.write((char*)&Map, sizeof(Map)); // ������д��ķ�ʽ
	MapData.write((char*)&PL, sizeof(PL)); 
	MapData.write((char*)Gh[4], sizeof(PL));
	MapData.close();
}
void Read(Map& Map, Player& PL)
{
	ifstream MapData("MapData.dat", ios::in );
	if (!MapData)
	{
		return;
	}
	int n = 0;
	int TempMap[19 * 19] = { 0 };
	MapData.read((char*)&Map, sizeof(Map));
	MapData.read((char*)&PL, sizeof(PL));
	MapData.close();
}