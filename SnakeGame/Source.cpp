#include <iostream>
#include <conio.h>
#include <Windows.h>
using namespace std;
//int speed = 30;


bool GameOver;
const int width = 30, height = 20;
const int MaxTailLength = width * height;
int x, y, FruitX, FruitY, score;

int TailX[MaxTailLength];
int TailY[MaxTailLength];
int TailSize;

enum Direction { STOP = 0, UP, DOWN, LEFT, RIGHT };
Direction dir;

void Setup()
{
    GameOver = false;
    dir = STOP;
    x = width / 2;
    y = height / 2;

    FruitX = rand() % width;
    FruitY = rand() % height;
    score = 0;
}
void Draw()
{
    system("cls");
    for (int i = 0; i < width + 2; i++)
        cout << "#";
    cout << endl;

    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            if (j == 0)
            {
                cout << "#";    
            }   
            if (j == x && i == y)
            {
                cout << "O";
            }
            else if (j == FruitX && i == FruitY)
            {
                cout << "F";
            }
            else
            {
                bool print = false;
                for (int k = 0; k < TailSize; k++)
                {
                    if (j == TailX[k] && i == TailY[k])
                    {
                        cout << "o";
                        print = true;
                    }
                }
                if (!print)
                {
                    cout << " ";
                }
            }
            if (j == width - 1)
            {
                cout << "#";
            }
            
        }
        cout << endl;
    }

    for (int i = 0; i < width + 2; i++)
        cout << "#";

    cout << endl;
    cout << endl << "The Score: " << score;
}
void Input()
{
    if (_kbhit())
    {
        switch (_getch())
        {
            case 'a':
                dir = LEFT;
                break;
            case 'd':
                dir = RIGHT;
                break;
            case 's':
                dir = DOWN;
                break;
            case 'w':
                dir = UP;
                break;
            case 'x':
                GameOver = true;
                break;
        }
    }

}
void Logic()
{
    int tmpX = x, tmpY = y;
    int tmpTailX, tmpTailY;
    for (int i = 0; i < TailSize; i++)
    {
        tmpTailX = TailX[i];
        tmpTailY = TailY[i];
        TailX[i] = tmpX;
        TailY[i] = tmpY;
        tmpX = tmpTailX;
        tmpY = tmpTailY;
    }
    switch (dir)
    {
    case UP:
        y--;
        break;
    case DOWN:
        y++;
        break;
    case LEFT:
        x--;
        break;
    case RIGHT:
        x++;
        break;
    default:
        break;
    }
    if (x < 0 || x >= width || y < 0 || y >= height)    //with dead_line
        GameOver = true;
    if (x == FruitX && y == FruitY)
    {
        score += 10;
        FruitX = rand() % width;
        FruitY = rand() % height;
        TailSize++;
        //speed--;
    }
}
int main()
{

    Setup();
    while (!GameOver)
    {
        Draw();
        Input();
        Logic();
        Sleep(20);
    }
    cout << endl << endl << "TheSCORE:" << score;
    _getch();
    //Setup();
    return 1;
}
