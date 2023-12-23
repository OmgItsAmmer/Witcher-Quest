#pragma once
#include <iostream>
#include <windows.h>
#include <conio.h>
#include <time.h>
#include <vector>
#include <algorithm>
#include <string>


const int width = 76; //level 1 & level 2
const int length = 26;
const int s1width = 52;
const int s1length = 20;
int health = 9;
int monsterhealth = 9;
char playerSymbol = 157;

struct Position
{
	int x;
	int y;
};

//gotoxy fnction
void gotoxy(int x, int y)
{ // gotoxy code
	COORD coord;
	coord.X = x;
	coord.Y = y;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}
void SetConsoleFontSize(int fontSize) {
	CONSOLE_FONT_INFOEX cfi;
	cfi.cbSize = sizeof(cfi);
	cfi.nFont = 0;
	cfi.dwFontSize.X = 0;                   // Width of each character in the font
	cfi.dwFontSize.Y = fontSize;            // Height
	cfi.FontFamily = FF_DONTCARE;
	cfi.FontWeight = FW_NORMAL;
	wcscpy_s(cfi.FaceName, L"Consolas"); // Choose your font
	SetCurrentConsoleFontEx(GetStdHandle(STD_OUTPUT_HANDLE), FALSE, &cfi);
}
//movement function
void move(int& preY, int& preX, Position& newPos)
{
	if (_kbhit())
	{

		char key = _getch();

		if (key == 's')
		{
			preY = newPos.y;
			newPos.y++;
		}
		else if (key == 'w')
		{
			preY = newPos.y;
			newPos.y--;
		}

		else if (key == 'd')
		{
			preX = newPos.x;
			newPos.x++;
		}

		else if (key == 'a')
		{
			preX = newPos.x;
			newPos.x--;
		}
	}
}