#include <iostream>
#include <conio.h>
#include <Windows.h>
using namespace std;
//int speed = 30;


bool GameOver;
const int width = 30, height = 20;
const int MaxTailLength = (width - 1) * (height - 1);
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
            case 'j':
                dir = LEFT;
                break;
            case 'l':
                dir = RIGHT;
                break;
            case 'k':
                dir = DOWN;
                break;
            case 'i':
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
    //if (x < 0 || x >= width || y < 0 || y >= height)    //with dead_line
    //    GameOver = true;
    if (x < 0) x = width - 1;                       // without dead line
    else if (x >= width) x = 0;
    if (y < 0) y = height - 1;
    else if (y >= height) y = 0;
    for (int i = 0; i < TailSize; i++)
    {
        if (x == TailX[i] && y == TailY[i])
        {
            GameOver = true;
        }
    }
    if (TailSize - 1 == MaxTailLength)
    {
        GameOver = true;
        cout << endl << "Congrads! You win!";
    }
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
