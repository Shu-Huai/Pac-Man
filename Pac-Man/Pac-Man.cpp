#include <iostream>
#include <Windows.h>
#include "conio.h"
#define W 0
#define B 1
#define K 2
#define P 3
#define G 4
using namespace std;
class MAP
{
protected:
    static int map[19][19];

public:
    MAP()
    {
    }
    void drawmap(int score);
    int GetBeanNumber();
};
class Player : public MAP
{
private:
    int x, y;
    int score;

public:
    Player(int X = 18, int Y = 9);
    int GetPX() const;
    int GetPY() const;
    int GetScore() const;
    void SetPlayerPosition(int X, int Y);
};
class Ghost : public MAP
{
private:
    int x, y;

public:
    Ghost(int X = 1, int Y = 1);
    int GetPX();
    int GetPY();
    void SetGhostPosition(int X, int Y);
};
int MAP::map[19][19] = {
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
Player::Player(int X, int Y) : MAP()
{
    x = X;
    y = Y;
    score = 0;
}
int Player::GetPX() const
{
    return x;
}
int Player::GetPY() const
{
    return y;
}
int Player::GetScore() const
{
    return score;
}
void Player::SetPlayerPosition(int X, int Y)
{
    int tempx = x;
    int tempy = y;
    x += X;
    y += Y;
    if (x > 18)
    {
        x -= 19;
    }
    if (y > 18)
    {
        y -= 19;
    }
    if (x < 0)
    {
        x += 19;
    }
    if (y < 0)
    {
        y += 19;
    }
    if (map[x][y] != W)
    {
        if (map[x][y] == G)
        {
            throw (int)0;
        }
        if (map[x][y]==B)
        {
            score++;
        }
        map[tempx][tempy] = K;
        map[x][y] = P;
    }
    else
    {
        x = tempx;
        y = tempy;
    }
}
Ghost::Ghost(int X, int Y) : MAP()
{
    x = X;
    y = Y;
    map[x][y] = G;
}
int Ghost::GetPX()
{
    return x;
}
int Ghost::GetPY()
{
    return y;
}
void Ghost::SetGhostPosition(int X, int Y)
{
    int tempx = x;
    int tempy = y;
    x += X;
    y += Y;
    if (x > 18)
    {
        x -= 19;
    }
    if (y > 18)
    {
        y -= 19;
    }
    if (x < 0)
    {
        x += 19;
    }
    if (y < 0)
    {
        y += 19;
    }
    if (map[x][y] != W)
    {
        map[tempx][tempy] = B;
        map[x][y] = G;
    }
    else
    {
        x = tempx;
        y = tempy;
    }
}
void MAP::drawmap(int score)
{
    system("cls");
    for (int i = 0; i < 19; i++)
    {
        for (int j = 0; j < 19; j++)
        {
            if (map[i][j] == 0)
            {
                cout << "□";
            }
            else if (map[i][j] == 1)
            {
                cout << "·";
            }
            else if (map[i][j] == 2)
            {
                cout << "  ";
            }
            else if (map[i][j] == 3)
            {
                cout << "★";
            }
            else if (map[i][j] == 4)
            {
                cout << "囧";
            }
        }
        cout << endl;
    }
    cout << "Your score is: " << score << endl;
}
int MAP::GetBeanNumber()
{
    int count = 0;
    for (int i = 0; i < 19; i++)
    {
        for (int j = 0; j < 19; j++)
        {
            if (map[i][j] == B)
            {
                count++;
            }
        }
    }
    return count;
}
void dead()
{
    cout << "You are dead. " << endl;
}
int main()
{
    begin:
    MAP first;
    Player PL;
    Ghost GH0(17, 1);
    Ghost GH1(17, 17);
    first.drawmap(0);
    int tempx = -1;
    int tempy = 0;
    while (first.GetBeanNumber() != 0)
    {
        char input;
        while (!_kbhit())
        {
            try 
            {
                PL.SetPlayerPosition(tempx, tempy);
            }
            catch (int)
            {
                dead();
                return 0;
            }
            first.drawmap(PL.GetScore());
            Sleep(200);
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
    }
    return 0;
}