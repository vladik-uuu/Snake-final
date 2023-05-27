#include <iostream>

#include <time.h>

#include <stdio.h>

#include <windows.h>

#include <conio.h>

#include <math.h>

#include <io.h>

#include <fcntl.h>

#include <string.h>

using namespace std;

HANDLE hConsole;

//HANDLE hStdout, hStdin;

HANDLE hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);

GotoXY(int X, int Y)

{

	COORD coord = { X, Y };

	SetConsoleCursorPosition(hStdOut, coord);

}

enum ConsoleColor

{

	Pink = 0,

	Blue = 1,
	Green = 2,

	Cyan = 3,

	Red = 4,

	Magenta = 5,

	Brown = 6,

	LightGray = 7,

	DarkGray = 8,

	LightBlue = 9,

	LightGreen = 10,

	LightCyan = 11,

	LightRed = 12,

	LightMagenta = 13,

	Yellow = 14,

	White = 15

};

void SetColor(ConsoleColor text, ConsoleColor background)

{

	SetConsoleTextAttribute(hStdOut, (WORD)((background << 4) | text));

}

struct Zmeja

{

	COORD* t;

	int PCount;

};

enum uprawlenie { LEFT, UP, RIGHT, DOWN };

struct Game

{

	Zmeja gaduka;

	COORD jabloko;

	int dx, dy,

		pause;

	int nap;

};

void PlusJabloko(Game& g)

{

	int i, x, y;

	int n = g.gaduka.PCount;

	do

	{

		x = rand() % 56 + 3;

		y = rand() % 19 + 3;

		for (i = 0; i < n; i++)

		{

			if (x == g.gaduka.t[i].X && y == g.gaduka.t[i].Y)

				break;

		}

	}

	while (i < n);

	g.jabloko.X = x;

	g.jabloko.Y = y;

	SetConsoleCursorPosition(hConsole, g.jabloko);

	SetConsoleTextAttribute(hConsole, 0x0c);

	printf("@", 6);

}

void skorostGame(Game& g)

{

	system("cls");

	g.gaduka.PCount = 3;

	g.gaduka.t = new COORD[3];

	for (int i = 0; i < 3; i++)

	{

		g.gaduka.t[i].X = 20 + i;

		g.gaduka.t[i].Y = 20;

	}

	g.dx = 1;

	g.dy = 0;

	g.pause = 100;

	PlusJabloko(g);

}

void ZmejaStart()

{

	GotoXY(10, 15); cout << "Собирай больше фруктов " << endl;

}

void STENA_2()

{

	SetColor(LightGreen, Pink); GotoXY(20, 0); cout << "Игра Змейка!!" << endl;

	GotoXY(64, 2); cout << "Данные:" << endl;

	GotoXY(64, 3); cout << "Фруктов собрано:0" << endl;

	GotoXY(64, 4); cout << "Длина змейки:3" << endl;

	GotoXY(64, 5); cout << "Скорость:0" << endl;

	GotoXY(64, 7); cout << "Управление:" << endl;

	GotoXY(64, 8); cout << "Esc:Выход" << endl;

	GotoXY(64, 9); cout << "P:Пауза" << endl;

	GotoXY(64, 10); cout << "K:Старт" << endl;

	GotoXY(64, 13); printf("%c", 24); cout << ":Вверх" << endl;

	GotoXY(64, 14); printf("%c", 25); cout << ":Вниз" << endl;

	GotoXY(64, 15); printf("%c", 27); cout << ":Влево" << endl;

	GotoXY(64, 16); printf("%c", 26); cout << ":Вправо" << endl;

	{

		SetColor(LightCyan, Pink);

		GotoXY(2, 2);

		int m = 0;

		for (m = 0; m < 60; m++)

		{

			printf("#");

		}

	}

	{

		GotoXY(2, 24);

		int m = 0;

		for (m = 0; m < 60; m++)

		{

			printf("#");

		}

	}

	{

		GotoXY(2, 3); cout << "#" << endl;

		GotoXY(2, 4); cout << "#" << endl;

		GotoXY(2, 5); cout << "#" << endl;

		GotoXY(2, 6); cout << "#" << endl;

		GotoXY(2, 7); cout << "#" << endl;

		GotoXY(2, 8); cout << "#" << endl;

		GotoXY(2, 9); cout << "#" << endl;

		GotoXY(2, 10); cout << "#" << endl;

		GotoXY(2, 11); cout << "#" << endl;

		GotoXY(2, 12); cout << "#" << endl;

		GotoXY(2, 13); cout << "#" << endl;

		GotoXY(2, 14); cout << "#" << endl;

		GotoXY(2, 15); cout << "#" << endl;

		GotoXY(2, 16); cout << "#" << endl;

		GotoXY(2, 17); cout << "#" << endl;

		GotoXY(2, 18); cout << "#" << endl;

		GotoXY(2, 19); cout << "#" << endl;

		GotoXY(2, 20); cout << "#" << endl;

		GotoXY(2, 21); cout << "#" << endl;

		GotoXY(2, 22); cout << "#" << endl;

		GotoXY(2, 23); cout << "#" << endl;

	}

	{

		GotoXY(61, 3); cout << "#" << endl;

		GotoXY(61, 4); cout << "#" << endl;

		GotoXY(61, 5); cout << "#" << endl;

		GotoXY(61, 6); cout << "#" << endl;

		GotoXY(61, 7); cout << "#" << endl;

		GotoXY(61, 8); cout << "#" << endl;

		GotoXY(61, 9); cout << "#" << endl;

		GotoXY(61, 10); cout << "#" << endl;

		GotoXY(61, 11); cout << "#" << endl;

		GotoXY(61, 12); cout << "#" << endl;

		GotoXY(61, 13); cout << "#" << endl;

		GotoXY(61, 14); cout << "#" << endl;

		GotoXY(61, 15); cout << "#" << endl;

		GotoXY(61, 16); cout << "#" << endl;

		GotoXY(61, 17); cout << "#" << endl;

		GotoXY(61, 18); cout << "#" << endl;

		GotoXY(61, 19); cout << "#" << endl;

		GotoXY(61, 20); cout << "#" << endl;

		GotoXY(61, 21); cout << "#" << endl;

		GotoXY(61, 22); cout << "#" << endl;

		GotoXY(61, 23); cout << "#" << endl;

	}

}

enum { KONEC, STENA, PLUS, MOVE };

int Move(Game& g)

{

	int& n = g.gaduka.PCount;

	COORD head = g.gaduka.t[n - 1];

	COORD tail = g.gaduka.t[0];

	COORD next;

	next.X = head.X + g.dx;

	next.Y = head.Y + g.dy;

	if (next.X < 3 || next.Y < 3 || next.X > 60 || next.Y > 23)

		return STENA;

	if (n > 4)

	{

		for (int i = 0; i < n; i++)

			if (next.X == g.gaduka.t[i].X && next.Y == g.gaduka.t[i].Y)

				return KONEC;

	}

	if (next.X == g.jabloko.X && next.Y == g.jabloko.Y)

	{

		COORD* temp = new COORD[++n];

		for (int i = 0; i < n; i++)

			temp[i] = g.gaduka.t[i];

		temp[n - 1] = next;

		delete[] g.gaduka.t;

		g.gaduka.t = temp;

		SetConsoleCursorPosition(hConsole, head);

		SetConsoleTextAttribute(hConsole, 0x0a);

		printf(" ");

		SetConsoleCursorPosition(hConsole, next);

		SetConsoleTextAttribute(hConsole, 0x0a);

		printf("@", 1);

		PlusJabloko(g);

		return PLUS;

	}

	for (int i = 0; i < n - 1; i++)

		g.gaduka.t[i] = g.gaduka.t[i + 1];

	g.gaduka.t[n - 1] = next;

	SetConsoleCursorPosition(hConsole, tail);

	printf(" ");

	SetConsoleCursorPosition(hConsole, head);

	SetConsoleTextAttribute(hConsole, 0x0a);

	printf("o");

	SetConsoleCursorPosition(hConsole, next);

	SetConsoleTextAttribute(hConsole, 0x0f);

	printf("O", 2);

	return MOVE;

}

void main()

{

	hConsole = GetStdHandle(STD_OUTPUT_HANDLE);

	int key = 0, count = 0;

	bool Pause = false;

	Game g;

	skorostGame(g);

	STENA_2();

	srand(time(0));

	bool pause = false;

	while (key != 27)

	{

		while (!_kbhit())

		{

			if (Pause == true)

			{

				Sleep(1);

				continue;

			}

			switch (Move(g))

			{

			case PLUS:

				++count;

				g.pause -= 1;

				GotoXY(64, 2); cout << "Данные:" << endl;

				GotoXY(64, 3); cout << "Количество фруктов:" << count << endl;

				GotoXY(64, 4); cout << "Длинна змейки:" << g.gaduka.PCount << endl;

				GotoXY(64, 5); cout << "Скорость:" << g.pause << endl;

				GotoXY(64, 7); cout << "Управление:" << endl;

				GotoXY(64, 8); cout << "Esc:Выход" << endl;

				GotoXY(64, 9); cout << "P:Пауза" << endl;

				GotoXY(64, 10); cout << "S:Старт" << endl;

				GotoXY(64, 13); printf("%c", 24); cout << ":Вверх" << endl;

				GotoXY(64, 14); printf("%c", 25); cout << ":Вниз" << endl;

				GotoXY(64, 15); printf("%c", 27); cout << ":Влево" << endl;

				GotoXY(64, 16); printf("%c", 26); cout << ":Вправо" << endl;

				if (count == 75)

				{

					GotoXY(15, 1); cout << "Вы победили" << endl;

					GotoXY(15, 6); printf("\n\t\t\t");

					GotoXY(15, 7); printf("\n\t\t\t");

					_getch();

					_getch();

					_getch();

					_getch();

					_getch();

					return;

				}

				break;

			case STENA:

			case KONEC:

				GotoXY(23, 1); printf("GAME OVER");

				_getch();

				return;

				break;

			}

			Sleep(g.pause);

		}

		key = _getch();

		if (key == 'P' || key == 'p')

			Pause = !Pause;

		else if (key == 'S' || key == 's')

			ZmejaStart();

		else if (key == 0 || key == 224)

		{

			key = _getch();

			if (key == 72 && g.nap != DOWN)

			{

				g.nap = UP;

				g.dx = 0;

				g.dy = -1;

			}

			else if (key == 80 && g.nap != UP)

			{

				g.nap = DOWN;

				g.dx = 0;

				g.dy = 1;

			}

			else if (key == 75 && g.nap != RIGHT)

			{

				g.nap = LEFT;

				g.dx = -1;

				g.dy = 0;

			}

			else if (key == 77 && g.nap != LEFT)

			{

				g.nap = RIGHT;

				g.dx = 1;

				g.dy = 0;

			}

		}

	}

}