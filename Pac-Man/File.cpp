#include <fstream>
#include "File.h"
using namespace std;
void  Write(Map& Map)
{
	fstream MapData("MapData.dat", ios::out | ios::binary | ios::trunc);  // �˴�ʡ���ļ��Ƿ��ʧ�ܵ��ж�
	MapData.write((char*)&Map, sizeof(Map)); // ������д��ķ�ʽ
	MapData.close();
}
void Read(Map& Map)
{
	ifstream MapData("MapData.dat", ios::in | ios::binary);
	if (!MapData)
	{
		return;
	}
	int n = 0;
	int TempMap[19 * 19] = { 0 };
	MapData.read((char*)&Map, sizeof(Map));
	MapData.close();
}