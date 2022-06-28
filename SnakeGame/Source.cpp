#include <iostream>
#include <conio.h>
using namespace std;

bool GameOver;
const int width = 20, height = 20;

int x, y, FruitX, FruitY, score;

int TailX[width * height];
int TailY[width * height];
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
    for (int i = 0; i < width + 1; i++)
        cout << "#";
    cout << endl;

    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            if (j == 0 || j == width - 1)
            {
                cout << "#";    
            }   
            cout << " ";
        }
        cout << endl;
    }

    for (int i = 0; i < width + 1; i++)
        cout << "#";

    cout << endl;

}
void Input()
{

}
void Logic()
{

}
int main()
{
    Setup();
    while (!GameOver)
    {
        Draw();
        Input();
        Logic();
    }
    Setup();
    return 1;
}