#pragma once

#include "fundamentals.h"




void instructionbox(string line1, string line2, string line3)
{
	system("cls");
	
	SetConsoleFontSize(50);
	gotoxy(75, 7);
	cout << "Instructions";
	char xtylishborder = 206;
	char xtylishborder2 = 219;
	//horizontal
	for (int i = 0; i < 80; i++)
	{	
		gotoxy(i + 40, 4); //upper wall
		cout << xtylishborder;
		gotoxy(i + 40, 25); // lower wall
		cout << xtylishborder2;
	}
	//vertical
	for (int i = 0; i < 20; i++)
	{		
		gotoxy(39, 5 + i); //left wall
		cout << xtylishborder2;
		gotoxy(120, 5 + i); //right wall
		cout << xtylishborder2;
	}

	gotoxy(42, 9);
	cout << line1;
	gotoxy(42, 10);
	cout << line2;
	gotoxy(42, 11);
	cout << line3;
	gotoxy(70, 20);
	cout << "press Enter to continue";
	cin.get();
	
	system("cls");
}
