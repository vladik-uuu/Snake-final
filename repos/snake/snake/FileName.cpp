#include <conio.h>
#include <stdio.h> 
#include <ctime>
#include <vector>
#include <windows.h>

#define PLANEHEIGHT 20
#define PLANEWIDTH 50
#define INITIALSNAKELENGTH 3
#define FPS 30

struct SnakeSegment
{
    SnakeSegment() {};
    SnakeSegment(unsigned short x1, unsigned short y1)
    {
        x = x1;
        y = y1;
    }
    unsigned short x;
    unsigned short y;
};

unsigned short snakeLength = INITIALSNAKELENGTH;
char lastDirection = 'd';
std::vector< SnakeSegment > m_Snake;

unsigned short foodX;
unsigned short foodY;

char plane[PLANEHEIGHT * PLANEWIDTH];

void DisplayPlane();
void NormalisePlane();
void SnakeInit();
void FoodInit();
void Move();
void DeleteLastSnakeSegment();
bool HasEatenFood();

void WipeConsole();

bool Won();
bool Lost();


int main()
{
    srand((unsigned int)time(NULL));

    NormalisePlane();
    SnakeInit();
    FoodInit();

    for (;; )
    {
        clock_t start;
        double time = 0.0;
        start = clock();

        while (time < 1.0 / FPS)
        {
            time = (clock() - start) / (double)CLOCKS_PER_SEC;
        }

        if (_kbhit()) //can get keyboard input without pressing Enter key
        {
            lastDirection = _getch();
        }

        if (HasEatenFood())
        {
            snakeLength++;
            SnakeSegment segment(foodX, foodY);
            m_Snake.push_back(segment); //we add eaten food position as a     new snake segment
            FoodInit(); //and spawn new food
        }

        WipeConsole();
        DisplayPlane();
        Move();

        if (Won())
        {
            printf("Congratulation, you have won!\n");
            break;
        }
        if (Lost())
        {
            printf("You have lost!\n");
            break;
        }
    }
    system("PAUSE");
}
void DisplayPlane()
{
    for (unsigned short i = 0; i < PLANEWIDTH + 2; i++) printf("%c", '/');     printf("\n"); //upper bound 

    for (unsigned short y = 0; y < PLANEHEIGHT; y++)
    {
        printf("%c", '/'); //left bound
        for (unsigned short x = 0; x < PLANEWIDTH; x++)
        {
            printf("%c", plane[y * PLANEWIDTH + x]); //stuff: X = food, O     = snake segment, ' ' = blank space
        }
        printf("%c\n", '/'); //right bound
    }

    for (unsigned short i = 0; i < PLANEWIDTH + 2; i++) printf("%c", '/');     printf("\n"); //lower bound
    printf("Snake length: %d\n", snakeLength);
}
void NormalisePlane()
{
    for (unsigned short x = 0; x < PLANEWIDTH; x++)
    {
        for (unsigned short y = 0; y < PLANEHEIGHT; y++)
        {
            plane[y * PLANEWIDTH + x] = ' '; //sets all plane cells to ' ' 
        }
    }
}
void SnakeInit() //spawns snake in a line of set length in first row of plane
{
    for (unsigned short i = 0; i < snakeLength; i++)
    {
        SnakeSegment segment;
        segment.x = i;
        segment.y = 0;
        m_Snake.push_back(segment);
        plane[i] = 'O';
    }
}
void FoodInit()
{
    foodX = rand() % PLANEWIDTH;
    foodY = rand() % PLANEHEIGHT;

    while (plane[foodY * PLANEWIDTH + foodX] != ' ') //new food has to be spawned at empty cell
    {
        foodX = rand() % PLANEWIDTH;
        foodY = rand() % PLANEHEIGHT;
    }

    plane[foodY * PLANEWIDTH + foodX] = 'X';
}
void Move()
{
    if (lastDirection == 'd')
    {
        SnakeSegment segment = m_Snake.at(m_Snake.size() - 1);
        segment.x++;
        m_Snake.push_back(segment);
        plane[segment.y * PLANEWIDTH + segment.x] = 'O';

        DeleteLastSnakeSegment();
    }
    else if (lastDirection == 's')
    {
        SnakeSegment segment = m_Snake.at(m_Snake.size() - 1);
        segment.y++;
        m_Snake.push_back(segment);
        plane[segment.y * PLANEWIDTH + segment.x] = 'O';

        DeleteLastSnakeSegment();
    }
    else if (lastDirection == 'a')
    {
        SnakeSegment segment = m_Snake.at(m_Snake.size() - 1);
        segment.x--;
        m_Snake.push_back(segment);
        plane[segment.y * PLANEWIDTH + segment.x] = 'O';

        DeleteLastSnakeSegment();
    }
    else if (lastDirection == 'w')
    {
        SnakeSegment segment = m_Snake.at(m_Snake.size() - 1);
        segment.y--;
        m_Snake.push_back(segment);
        plane[segment.y * PLANEWIDTH + segment.x] = 'O';

        DeleteLastSnakeSegment();
    }
}
void DeleteLastSnakeSegment()
{
    SnakeSegment temp = m_Snake[0];
    plane[temp.y * PLANEWIDTH + temp.x] = ' ';
    m_Snake.erase(m_Snake.begin()); //first is last
}
bool HasEatenFood()
{
    SnakeSegment segment = m_Snake.at(m_Snake.size() - 1); //first element of snake
    SnakeSegment food;
    food.x = foodX;
    food.y = foodY;
    return segment.x == food.x && segment.y == food.y; //if his "head" collides with food cell
}
void WipeConsole()
{
    HANDLE hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);
    COORD coord = { 0,0 };
    DWORD count;
    CONSOLE_SCREEN_BUFFER_INFO csbi;

    if (GetConsoleScreenBufferInfo(hStdOut, &csbi))
    {
        FillConsoleOutputCharacter(hStdOut, (TCHAR)32, csbi.dwSize.X * csbi.dwSize.Y, coord, &count);
        FillConsoleOutputAttribute(hStdOut, csbi.wAttributes, csbi.dwSize.X - 1 * csbi.dwSize.Y - 1, coord, &count);
        SetConsoleCursorPosition(hStdOut, coord);
    }
    return;
}
bool Won()
{
    bool space = false;
    for (unsigned short x = 0; x < PLANEWIDTH; x++)
    {
        for (unsigned short y = 0; y < PLANEHEIGHT; y++)
        {
            if (plane[y * PLANEWIDTH + x] == ' ') //if none of cells is empty we won
            {
                space = true;
                break;
            }
        }
    }
    return !space;
}
bool Lost()
{
    SnakeSegment segment = m_Snake.at(m_Snake.size() - 1); //first element of snake

    if (segment.x < 0 || segment.x > PLANEWIDTH - 1 ||
        segment.y < 0 || segment.y > PLANEHEIGHT - 1) return true; //if colides with boundries

    for (unsigned short i = 0; i < m_Snake.size() - 1; i++) //or with itself we return true
    {
        SnakeSegment temp = m_Snake[i];
        if (temp.x == segment.x && temp.y == segment.y) return true;
    }

    return false;
}