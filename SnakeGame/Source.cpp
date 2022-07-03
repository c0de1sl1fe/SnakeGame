#include <iostream>
#include <conio.h>
#include <Windows.h>
using namespace std;
//int speed = 30;



enum Direction { STOP = 0, UP, DOWN, LEFT, RIGHT };


class SnakeGame
{
private: 
    static bool GameOver;
    static int width, height;
    static int MaxTailLength;
    static int x, y, FruitX, FruitY, score;

    static int* TailX;
    static int* TailY;
    static int TailSize;
    static Direction dir;

public:
    static void Setup()
    {
        GameOver = false;
        dir = STOP;
        //width = input_width;
        //height = input_height;

        width = 30;
        height = 20;


        MaxTailLength = (width - 1) * (height - 1);

        TailX = new int[MaxTailLength];
        TailY = new int[MaxTailLength];

        x = width / 2;
        y = height / 2;

        FruitX = rand() % width;
        FruitY = rand() % height;
        score = 0;
    }
    static void Draw()
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
    static void Input()
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
    static void Logic()
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

    static bool IsGameOver() { return GameOver; }
    static int GetScore() { return score; }
};
bool SnakeGame::GameOver = false;
int SnakeGame::width = 30;
int SnakeGame::height = 20;
int SnakeGame::MaxTailLength;
int SnakeGame::x, SnakeGame::y, SnakeGame::FruitX, SnakeGame::FruitY, SnakeGame::score;

int* SnakeGame::TailX;
int* SnakeGame::TailY;
int SnakeGame::TailSize;
Direction SnakeGame::dir;


int main()
{
    srand(time(NULL));
    SnakeGame::Setup();
    while (!SnakeGame::IsGameOver())
    {
        SnakeGame::Draw();
        SnakeGame::Input();
        SnakeGame::Logic();
        Sleep(20);
    }
    cout << endl << endl << "TheSCORE:" << SnakeGame::GetScore();
    _getch();
    //Setup();
    return 1;
}
