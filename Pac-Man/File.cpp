#include <fstream>
#include "File.h"
using namespace std;
void  Write(Map& Map)
{
	fstream MapData("MapData.dat", ios::out | ios::binary | ios::trunc);  // 此处省略文件是否打开失败的判断
	MapData.write((char*)&Map, sizeof(Map)); // 二进制写入的方式
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