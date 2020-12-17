#pragma once
#define W 0
#define B 1
#define K 2
#define P 3
#define G 4
class Map
{
	friend class Player;
	friend class Ghost;
protected:
	int _map[19][19] = {
		W, W, W, W, W, W, W, W, W, B, W, W, W, W, W, W, W, W, W,
		W, B, B, B, B, B, B, B, B, B, B, B, B, B, B, B, B, B, W,
		W, B, B, W, B, B, W, W, W, B, W, W, W, B, B, W, B, B, W,
		W, B, W, W, B, B, B, B, B, B, B, B, B, B, B, W, W, B, W,
		W, B, W, B, B, B, W, W, W, B, W, W, W, B, B, B, W, B, W,
		W, B, W, B, B, B, B, B, B, B, B, B, B, B, B, B, W, B, W,
		W, B, B, B, B, B, W, W, B, B, B, W, W, B, B, B, B, B, W,
		W, B, W, B, B, B, B, B, B, B, B, B, B, B, B, B, W, B, W,
		W, B, W, B, B, B, B, B, W, B, W, B, B, B, B, B, W, B, W,
		B, B, B, B, B, B, B, B, W, W, W, B, B, B, B, B, B, B, B,
		W, B, W, B, B, B, B, B, B, B, B, B, B, B, B, B, W, B, W,
		W, B, W, B, B, W, B, B, B, B, B, B, B, W, B, B, W, B, W,
		W, B, W, B, W, W, W, B, B, B, B, B, W, W, W, B, W, B, W,
		W, B, B, B, B, W, B, B, B, B, B, B, B, W, B, B, B, B, W,
		W, B, W, W, B, B, B, B, B, B, B, B, B, B, B, W, W, B, W,
		W, B, B, B, B, B, B, B, B, B, B, B, B, B, B, B, B, B, W,
		W, B, B, B, B, W, W, W, B, W, B, W, W, W, B, B, B, B, W,
		W, B, B, B, B, W, B, B, B, B, B, B, B, W, B, B, B, B, W,
		W, W, W, W, W, W, W, W, W, P, W, W, W, W, W, W, W, W, W,
	};

public:
	Map()
	{
	}
	void DrawMap(int score);
	int GetBeanNumber();
	void SetMap(int X, int Y, int condition);
};