#include <fstream>
#include "File.h"
using namespace std;
void  Write(Map& map)
{
	fstream binary_file("MapData.dat", ios::out | ios::binary | ios::app);  // 此处省略文件是否打开失败的判断
	binary_file.write((char*)&map, sizeof(map)); // 二进制写入的方式
	binary_file.close();
}