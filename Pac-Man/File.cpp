#include <fstream>
#include "File.h"
using namespace std;
void  Write(Map& map)
{
	fstream binary_file("MapData.dat", ios::out | ios::binary | ios::app);  // �˴�ʡ���ļ��Ƿ��ʧ�ܵ��ж�
	binary_file.write((char*)&map, sizeof(map)); // ������д��ķ�ʽ
	binary_file.close();
}