//we are using only one preX and preY for all things yet.
//line 397
#include "fundamentals.h"
#include "minigames.h"
#include "instructions.h"


using namespace std;

//const int width = 76; //level 1 & level 2
//const int length = 26;
//const int s1width = 52;
//const int s1length = 20;
//int health = 9; //idk why here
//int monsterhealth = 9;


//struct Position
//{
//	int x;
//	int y;
//};
struct Riddle
{
	string question;
	string answer;

	Riddle(string q, string a) : question(q), answer(a) {};
};

vector<Position> enemypositions;
vector<Position> healthpotionspos;
vector<Position> weaponspos;
Position enemyposiitonsarray[10];
Position healthpotionsposarray[10]; ///

//gotoxy fnction
//void gotoxy(int x, int y)
//{ // gotoxy code
//	COORD coord;
//	coord.X = x;
//	coord.Y = y;
//	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
//}
//get random numbers function
int getRandomNumber(int min, int max) {
	return rand() % (max - min + 1) + min;
}
//displayMessage function
void displayMessage(string message, int x, int y, int duration)
{
	gotoxy(x, y);
	cout << message << endl;
	Sleep(duration);
	for (int i = 0; i < message.length(); i++)
	{
		gotoxy(x + i, y);
		cout << " " << endl;
	}
}


//Dialogue box function
void dialogueBox()
{
	gotoxy(width + 16, 3);
	cout << "<<<<DIALOGUE BOX>>>>";
	for (int i = 0; i < length - 2; i++)
	{
		//Sleep(25);
		gotoxy(width + 7, 2 + i);
		cout << "<";
		gotoxy(width + 43, 2 + i);
		cout << ">";
	}
	for (int i = 0; i < length + 11; i++) //iteration range depends on size you want
	{
		//Sleep(25);
		gotoxy(width + 7 + i, 2);
		cout << "*";
		gotoxy(width + 7 + i, length - 1); //To match with game border
		cout << "*";
	}
}
//bool healthchecker()
void healthbar(int& healthd, string player)
{
	if (player == "player")
	{
		gotoxy(5, 26);
		cout << "Witcher:";

		for (int i = 0; i < health; i++)
		{
			gotoxy(14 + i, 26);
			cout << "+";
		}
	}
	else if (player == "enemy")
	{
		gotoxy(60, 26);
		cout << "Monster:";

		for (int i = 0; i < monsterhealth; i++)
		{
			gotoxy(69 + i, 26);
			cout << "+";
		}
	}

}
//batterange border
void battlerange()
{

	//gotoxy(44, 10);
	//cout << "<<< WElcoME To BaTTle RangE >>>";
	////Sleep(2000);
	system("cls");
	gotoxy(34, 3);
	cout << "<<-BATTLE RANGE->>";
	//horizontal
	for (int i = 0; i < 65; i++) //iteration range depends on size you want
	{
		//Sleep(10);
		gotoxy(10 + i, 5);
		cout << "_";
		gotoxy(10 + i, 25); //To match with game border
		cout << "_";
	}
	//vertical
	for (int i = 0; i < 20; i++)
	{
		//Sleep(10);
		gotoxy(9, 6 + i);
		cout << "|";
		gotoxy(75, 6 + i);
		cout << "|";
	}
	//inner wall first&secind horziontal
	for (int i = 0; i < 25; i++) // 65/3 is approx 18
	{
		//Sleep(10);
		gotoxy(10 + i, 12);
		cout << "_";

		gotoxy(50 + i, 18); //To match with game border
		cout << "_";
	}
	//inner wall first & second vertical
	for (int i = 0; i < 7; i++)
	{
		//Sleep(10);
		gotoxy(34, 6 + i);
		cout << "|";
		gotoxy(50, 19 + i);
		cout << "|";
	}

}
int  witcherattack()
{
	srand(time(0));
	int result = (rand() % 5) + 1;
	return result;
}
void battle()
{
	srand(time(0));

	int enemyinput;
	//int witcherattack;
	char input;

	for (int k = 0; k < 10; k++)
	{
		battlerange();
		dialogueBox();
		healthbar(monsterhealth, "enemy");
		healthbar(health, "player");
		if (health == 0)
		{
			cout << "You died";
		}
		else if (monsterhealth == 0)
		{
			cout << "Monster died";
		}
		for (int i = 0; i < 1; i++)
		{
			gotoxy(90, 6);
			cin >> input;
			if (input == '1')
			{
				gotoxy(90, 8);
				cout << "you Attacked the monster";
				int random = witcherattack();
				monsterhealth = monsterhealth - random;
				//Sleep(10);
				/*break;*/
			}
			else if (input == '2')
			{
				gotoxy(90, 8);
				cout << "You defend ";
				health = health + 1;
				//Sleep(10);
				/*break;*/
			}
		}
		for (int j = 0; j < 1; j++)
		{
			enemyinput = (rand() % 2) + 1;
			if (enemyinput == 1)
			{
				gotoxy(90, 10);
				cout << "Monster attacked you";
				health = health - 2;

				//Sleep(10);
				/*	break;*/
			}
			else if (enemyinput == 2)
			{
				gotoxy(90, 10);
				cout << "Monster regained health";
				monsterhealth++;

				// TODO: run sleep for first time only
				//Sleep(10);
				/*	break;*/
			}
		}

		/*else if (monsterhealth != 0 && health != 0)
		{

		}*/
		Sleep(1000);
		system("cls");
	}// k loop


}


//Main menu
void mainmenu()
{

	char key;
	int input;

	for (int i = 1; i <= 100; i++)
	{
		gotoxy(50, 5);
		cout << "Witcher's Quest";
		gotoxy(43, 10);
		cout << "Press \"1\" to Continue";
		gotoxy(43, 12);
		cout << "Press \"2\" to User Manual";
		gotoxy(43, 14);
		cout << "Press \"3\" to About";
		gotoxy(43, 16);
		cin >> key;

		if (_kbhit())
		{

			//if I press an key char will take it ASCII value and compare it with the  number it its correct it will proceed

			if (key == ' ')
			{
				system("cls");
				break;
			}
			else if (key == 50 || key == 85)
			{
				int input2;

				system("cls");
				gotoxy(43, 10);
				cout << "@: Player";
				gotoxy(43, 12);
				cout << "AI is a bot";
				gotoxy(43, 14);
				cout << "() is the door to next level";
				gotoxy(43, 16);
				cout << "8 is the shop door";
				gotoxy(43, 18);
				cout << "press \" 1\" to continue";
				gotoxy(43, 20);
				cin >> input2;
				for (int i = 0; i < 100; i++)

				{
					if (input2 == 1)
					{
						system("cls");
						break;
					}
					else
					{
						cout << "Enter valid command";

					}
				}


			}

			else if (key == 77)
			{

			}

			else if (key == 75)
			{

			}
		}

	}
}
// Function to get the character at a specific position
char getCharacterAtPosition(int x, int y) {
	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	if (hConsole == INVALID_HANDLE_VALUE) {
		// Handle error
		return '\0';
	}

	CONSOLE_SCREEN_BUFFER_INFO csbi;
	if (!GetConsoleScreenBufferInfo(hConsole, &csbi)) {
		// Handle error
		return '\0';
	}

	COORD coord;
	coord.X = x;
	coord.Y = y;

	DWORD dwRead;
	CHAR_INFO chi;
	if (!ReadConsoleOutputCharacter(hConsole, &chi.Char.UnicodeChar, 1, coord, &dwRead)) {
		// Handle error
		return '\0';
	}
	//cout << chi.Char.UnicodeChar;
	return chi.Char.UnicodeChar;
}
//hiding cursor
void cursorhide() {

}   //not working 
//levelblocker
void doorblocker()
{
	for (int i = 0; i < 5; i++) //4
	{
		Sleep(100);
		gotoxy((width / 2) - 2 + i, 4);
		cout << "*";
	}
	//vertical walls
	for (int j = 0; j < 2; j++)
	{
		Sleep(100);
		gotoxy((width / 2) - 2, 4 - j);
		cout << "*";
		gotoxy((width / 2) + 3, 4 - j);
		cout << "*";
	}

}
//map border
void border()
{
	for (int i = 2; i < length; i++) //starting from 2 to  escape starting line (C:/ammer etc)
	{
		gotoxy(0, i);
		cout << "#";
		gotoxy(width, i);
		cout << "#";
	}

	for (int i = 0; i < width; i++)
	{
		gotoxy(i, 2);
		cout << "#";
		gotoxy(i, length - 1);
		cout << "#";
	}
} // border
//shop inner border(shop walls)
void shopinnerborder() {
	//horizontal
	for (int i = 0; i < s1width - 4; i++)
	{
		gotoxy(i + 4, 4); //upper wall
		cout << "*";
		gotoxy(i + 4, length - 8); // lower wall
		cout << "*";
	}
	//vertical
	for (int i = 0; i < s1length - 6; i++)
	{
		gotoxy(4, 5 + i); //left wall
		cout << "*";
		gotoxy(s1width - 1, 5 + i); //right wall
		cout << "*";
	}
}
/// shop outerborder
void shopexterior(int vx1, int vy1, int vx2, int vy2, int hx1, int hy1, int hx2, int hy2, int dx, int dy)
{

	// vertical walls
	gotoxy(vx1, vy1);
	cout << "*";
	gotoxy(vx2, vy2);
	cout << "*";
	// horizontal walls
	gotoxy(hx1, hy1);
	cout << "**";
	gotoxy(hx2, hy2);
	cout << "**";
	gotoxy(dx, dy);
	cout << "8";



	//gotoxy(width - 2, (length / 2) - 2);
	//cout << "*";
	//gotoxy(width - 2, (length / 2));
	//cout << "*";
	//// horizontal walls
	//gotoxy(width - 2, (length / 2) - 3);
	//cout << "**";
	//gotoxy(width - 2, (length / 2) + 1);
	//cout << "**";
	//gotoxy(width - 2, (length / 2) - 1);
	//cout << "8";
	// 
	// 
	//for (int i = 1; i < 3; i++) //2 times
	//{
	//	gotoxy(width - 8, (length / 2) - 3 + i);
	//	cout << "*";
	//	gotoxy(width - 8, (length / 2) + 1 + i);
	//	cout << "*";
	//}
	//for (int i = 1; i < (9); i++)
	//{
	//	gotoxy(width - 9 + i, (length / 2) - 3);
	//	cout << "*";
	//}
	//for (int i = 1; i < (9); i++)
	//{
	//	gotoxy(width - 9 + i, (length / 2) + 5);
	//	cout << "*";
	//}
	// door


} // shopexterior1
/////Player and destination position////
void drawposition(Position& playerpos, Position& destpos)
{
	
	gotoxy(playerpos.x, playerpos.y);
	cout << playerSymbol;

	gotoxy(destpos.x, destpos.y);
	cout << "()";
} // drawposition
/////drawshopposition
void drawshopthings(Position& playerpos, Position& destpos, Position& doorpos)
{
	gotoxy(playerpos.x, playerpos.y);
	cout << playerSymbol;


	gotoxy(destpos.x, destpos.y);
	cout << "0^0";

	gotoxy(doorpos.x, doorpos.y);
	cout << "8";

}


/// collison&movement///
bool checkcollision(Position& newpos)
{
	if (newpos.x < 1 || newpos.x >= 75 || newpos.y < 3 || newpos.y >= 25)
	{
		return true;
	}
	else
		return false;
} // collsiom
//shop1doorcollision function
bool checkshopcollision(Position& newpos)
{
	if (newpos.x <= 4 || newpos.x >= s1width - 1 || newpos.y <= 4 || newpos.y >= length - 8) //s1width-1 is adjusting border in square in upper function so we need -1 in this too 
	{
		return true;
	}
	else
		return false;
} // collsiom
//check door collision function
bool checkdoorcollision(Position& newpos, Position& doorpos)
{
	if (newpos.x == doorpos.x && newpos.y == doorpos.y) //  width - 2 , (length / 2) - 1
	{
		return false;
	}
	else
		return true;

} // checkdoorcollision
///next level(will fix name)
bool portal(Position& playerpos, Position& destpos)
{
	if (playerpos.x == destpos.x && playerpos.y == destpos.y)
	{
		return true;
	}
	else
		return false;
}

bool door1(Position& playerpos, Position& doorpos)
{
	if (playerpos.x == doorpos.x && playerpos.y == doorpos.y)
	{
		return true;
	}
	else
		return false;
}
//Hintman collision function
bool hintman(Position& playerpos, Position& destpos)
{
	if (playerpos.x == destpos.x && playerpos.y == destpos.y)
	{
		return true;
	}
	else
		return false;
}
//enemy random spawm
void randomspawm(vector<Position>& vectorname, int quantity) //quanitity = 10
{
	srand(time(0));
	for (int i = 1; i < quantity; i++)
	{
		Position thingpos = { rand() % width - 1,rand() % length - 1 };
		gotoxy(thingpos.x, thingpos.y);
		cout << "%";
		vectorname.push_back(thingpos);

	}


}
bool playerinteractingpos(Position& playerpos, Position thingpos)
{
	if (abs(playerpos.x - thingpos.x) <= 1 && abs(playerpos.y - thingpos.y) <= 1)
	{
		return true;
	}
	else
		return false;

}


void playerinteraction(Position& playerpos, Position thingpos, bool& rangechecker, vector<Position>& vectorname)
{
	for (const auto& thingpos : vectorname)
	{
		if (playerinteractingpos(playerpos, thingpos))
		{
			rangechecker = true;
			return;
		}
		else
		{
			// If no interaction is found, set rangechecker to false
			rangechecker = false;
		}
	}

	//void playerinteraction(Position& playerpos, Position thingpos, bool& rangechecker, Position arrayname[],int size)
	//{
	//	
	//	for (int i = 0; i <size; i++)
	//	{
	//		if (playerinteractingposwitharray( playerpos, arrayname))
	//		{
	//			rangechecker = true;
	//			
	//			return;
	//		}
	//	}

		// If no interaction is found, set rangechecker to false
	//	rangechecker = false;
}


//hiddenthings
void randomweapons(int quantity)
{
	srand(time(0));
	//for (int i = 0; i < 50; i++)
	///*{
	//	Position healthpotion = { rand() % width - 1, rand() % length - 1 };
	//	gotoxy(healthpotion.x, healthpotion.y);
	//	cout << "||";
	//	healthpotionspos.push_back(healthpotion);
	//}*/
	for (int i = 0; i < quantity; i++)
	{
		Position weapons = { rand() % width - 1, rand() % length - 1 };
		cout << "&";
		weaponspos.push_back(weapons);
	}
}
bool playerinteractingposwitharray(Position& playerpos, Position arrayname[])
{
	for (int i = 0; i < 10; i++)
	{
		if (abs(playerpos.x - arrayname[i].x) <= 1 && abs(playerpos.y - arrayname[i].y) <= 1)
		{
			return true;
			break;
		}

	}

	return false;
}









int main()
{
	bool level2checker = false;
	// Hide the cursor
	HANDLE consoleHandle = GetStdHandle(STD_OUTPUT_HANDLE);
	CONSOLE_CURSOR_INFO cursorInfo;
	GetConsoleCursorInfo(consoleHandle, &cursorInfo);
	cursorInfo.bVisible = false;
	SetConsoleCursorInfo(consoleHandle, &cursorInfo);
	//////////////
	int blocker = 0;
	Position playerpos = { width / 2, length - 2 }; // x and y
mainmap: //line 380
	system("cls");
	/*GUI();*/
	system("color E0");
	Position destpos = { width / 2, 3 };
	Position doorpos = { width - 2, (length / 2) - 1 };
	Position doorpos2 = { width - 2, (length / 2) + 9 };
	Position doorpos3 = { 2, (length / 2) + 9 };
	Position doorpos4 = { 2, (length / 2) - 1 };

	Position newPos = playerpos;
	int preY = 0, preX = 0;
	cursorhide();
	border();
	shopexterior(width - 2, (length / 2) - 2, width - 2, (length / 2), width - 2, (length / 2) - 3, width - 2, (length / 2) + 1, width - 2, (length / 2) - 1);
	shopexterior(width - 2, (length / 2) + 8, width - 2, (length / 2) + 10, width - 2, (length / 2) + 7, width - 2, (length / 2) + 11, width - 2, (length / 2) + 9);
	shopexterior(2, (length / 2) + 8, 2, (length / 2) + 10, 1, (length / 2) + 7, 1, (length / 2) + 11, 2, (length / 2) + 9);
	shopexterior(2, (length / 2) - 2, 2, (length / 2), 1, (length / 2) - 3, 1, (length / 2) + 1, 2, (length / 2) - 1);

	drawposition(playerpos, destpos);
	dialogueBox();
	if (blocker == 4)
	{
		doorblocker();
	}

	while (true)
	{
		move(preY, preX, newPos);
		if (getCharacterAtPosition(newPos.x, newPos.y) == '*') //position matters
		{
			newPos.x = preX;
			newPos.y = preY;
		}
		if (getCharacterAtPosition(newPos.x, newPos.y) == '#') //position matters
		{
			newPos.x = preX;
			newPos.y = preY;
		}
		if (!checkcollision(newPos)) // colliosn function is working oposite bcz its easy to code area of map
		{
			gotoxy(playerpos.x, playerpos.y);
			cout << " ";                      // it will empty the previous position
			playerpos = newPos;               // default playerpos is the when u give in start but its also kep updating
			drawposition(playerpos, destpos); // we didnt require destpos bcz we need final desiton once
		}
		if (portal(newPos, destpos))
		{

			level2checker = true;
			break;
		}
		if (!checkdoorcollision(newPos, doorpos))
		{
			system("cls");
			break;
		}
		if (!checkdoorcollision(newPos, doorpos2))
		{
			system("cls");
			break;
		}
		if (!checkdoorcollision(newPos, doorpos3))
		{
			system("cls");
			break;
		}
		if (!checkdoorcollision(newPos, doorpos4))
		{
			system("cls");
			break;
		}
	} // while1
		//////////////////////////////////////////////
		//////////////////shop1//////////////////////
		//////////////////////////////////////////////
	if (checkdoorcollision(newPos, doorpos) == false) //  width - 2 , (length / 2) - 1

	{

		/// inside shop
		Position playerpos2 = { 7, (s1length / 2) + 1 };
	shopnearAI:
		Position hintmanstandingpos = { 26,6 }; // write in width form later
		Position doorpos = { 5 , (s1length / 2) + 1 };
		shopinnerborder();
		drawshopthings(playerpos2, hintmanstandingpos, doorpos);
		gotoxy(width + 10, 3);
		dialogueBox();
		Position newPos2 = playerpos2;

		while (true)
		{
			move(preY, preX, newPos2);
			if (getCharacterAtPosition(newPos.x, newPos.y) == '*') //position matters
			{
				newPos.x = preX;
				newPos.y = preY;
			}
			if (!checkshopcollision(newPos2)) // colliosn function is working oposite bcz its easy to code area of map
			{
				gotoxy(playerpos2.x, playerpos2.y);
				cout << " ";										     // it will empty the previous position
				playerpos2 = newPos2;									 // default playerpos is the when u give in start but its also kep updating
				drawshopthings(playerpos2, hintmanstandingpos, doorpos); // we didnt require destpos bcz we need final desiton once
			}
			if (playerinteractingpos(newPos2, hintmanstandingpos) == true)
			{
				string answer, answer2, answer3;
				gotoxy(width + 10, 6);
				cout << "AI: You need help witcher?(yes/no)" << endl;
				gotoxy(width + 10, 7);
				cout << "Witcher: ";
				gotoxy(width + 10, 8);
				cin >> answer;

				if (answer == "yes" || answer == "YES" || answer == "Yes")
				{
					gotoxy(width + 10, 9);
					cout << "Yes,I am looking for the portal";
					gotoxy(width + 10, 10);
					cout << "AI: Oh portal, its to the north" << endl;
					gotoxy(width + 10, 11);
					cout << "ok Thanks,AI";

					//tryagain:
					gotoxy(width + 10, 12);
					cout << "Say \"bye\" to continue joruney";
					gotoxy(width + 10, 13);
					cin >> answer2;
					if (answer2 == "bye")
					{

						gotoxy(width + 10, 9);
						system("cls");
						playerpos2 = { 26,8 };
						blocker = false;
						goto shopnearAI; //line 294  
					}
					else
					{
						cout << "AI: Sorry what you said?";
						// goto tryagain; can use as handler
					}
				}
				else if (answer == "no" || answer == "NO" || answer == "No")
				{
					gotoxy(width + 10, 9);
					cout << "As you say witcher";
					Sleep(2000);
					blocker = false;
					system("cls");
					playerpos2 = { 26,8 };
					goto shopnearAI; //line 294 
				}
				else
				{
					gotoxy(width + 10, 9);
					cout << "enter valid option, thanks";
				}

			}
			if (door1(newPos2, doorpos))
			{
				playerpos = { (width - 4) , (length / 2) -1 };
				goto mainmap; // 221
			}
		}//while2
	}//if for shop1 entry

	//////////////////////////////////////////////
	//////////////////shop2//////////////////////
	//////////////////////////////////////////////
	if (checkdoorcollision(newPos, doorpos2) == false) //  width - 2 , (length / 2) - 1

	{

		/// inside shop2
		Position playerpos2 = { 7, (s1length / 2) + 1 };
	shopnearAI2:
		Position hintmanstandingpos = { 26,6 }; // write in width form later
		Position doorpos = { 5 , (s1length / 2) + 1 };
		shopinnerborder();
		drawshopthings(playerpos2, hintmanstandingpos, doorpos);
		gotoxy(width + 10, 3);
		dialogueBox();
		Position newPos2 = playerpos2;

		while (true)
		{
			move(preY, preX, newPos2);
			if (getCharacterAtPosition(newPos.x, newPos.y) == '*') //position matters
			{
				newPos.x = preX;
				newPos.y = preY;
			}
			if (!checkshopcollision(newPos2)) // colliosn function is working oposite bcz its easy to code area of map
			{
				gotoxy(playerpos2.x, playerpos2.y);
				cout << " ";										     // it will empty the previous position
				playerpos2 = newPos2;									 // default playerpos is the when u give in start but its also kep updating
				drawshopthings(playerpos2, hintmanstandingpos, doorpos); // we didnt require destpos bcz we need final desiton once
			}
			if (playerinteractingpos(newPos2, hintmanstandingpos) == true)
			{
				instructionbox("In this puzzle you have to match the pairs", "range is from 0-11", "you can also exit the game by writing 'Exit'");
				memoryGame();
				system("cls");
				playerpos2 = { 26,8 };
				goto shopnearAI2; //line 294 

			}
			if (door1(newPos2, doorpos))
			{
				playerpos = { width - 4, (length / 2) + 9 };
				goto mainmap; // 221
			}
		}//while2
	}//if for shop2 entry

	//////////////////////////////////////////////
	//////////////////Shop3//////////////////////
	//////////////////////////////////////////////
	if (checkdoorcollision(newPos, doorpos3) == false) //  width - 2 , (length / 2) - 1

	{

		/// inside shop3
		Position playerpos2 = { 7, (s1length / 2) + 1 };
	shopnearAI3:
		Position hintmanstandingpos = { 26,6 }; // write in width form later
		Position doorpos = { 5 , (s1length / 2) + 1 };
		shopinnerborder();
		drawshopthings(playerpos2, hintmanstandingpos, doorpos);
		gotoxy(width + 10, 3);
		dialogueBox();
		Position newPos2 = playerpos2;

		while (true)
		{
			move(preY, preX, newPos2);
			if (getCharacterAtPosition(newPos.x, newPos.y) == '*') //position matters
			{
				newPos.x = preX;
				newPos.y = preY;
			}
			if (!checkshopcollision(newPos2)) // colliosn function is working oposite bcz its easy to code area of map
			{
				gotoxy(playerpos2.x, playerpos2.y);
				cout << " ";										     // it will empty the previous position
				playerpos2 = newPos2;									 // default playerpos is the when u give in start but its also kep updating
				drawshopthings(playerpos2, hintmanstandingpos, doorpos); // we didnt require destpos bcz we need final desiton once
			}
			if (playerinteractingpos(newPos2, hintmanstandingpos) == true)
			{	
				instructionbox("In this puzzle, you hve to win WIC WAC WOO against the monster", "", "");
				playTicTacToe(); 
			}
			if (door1(newPos2, doorpos))
			{
				playerpos = { 4, (length / 2) + 9 };
				goto mainmap; // 221
			}
		}//
	}//if for shop3 entry


	//////////////////////////////////////////////
	//////////////////shop 4//////////////////////
	//////////////////////////////////////////////
	if (checkdoorcollision(newPos, doorpos4) == false) //  width - 2 , (length / 2) - 1

	{

		/// inside shop4
		Position playerpos2 = { 7, (s1length / 2) + 1 };
	shopnearAI4:
		Position hintmanstandingpos = { 26,6 }; // write in width form later
		Position doorpos = { 5 , (s1length / 2) + 1 };
		shopinnerborder();
		drawshopthings(playerpos2, hintmanstandingpos, doorpos);
		gotoxy(width + 10, 3);
		dialogueBox();
		Position newPos2 = playerpos2;

		while (true)
		{
			move(preY, preX, newPos2);
			if (getCharacterAtPosition(newPos.x, newPos.y) == '*') //position matters
			{
				newPos.x = preX;
				newPos.y = preY;
			}
			if (!checkshopcollision(newPos2)) // colliosn function is working oposite bcz its easy to code area of map
			{
				gotoxy(playerpos2.x, playerpos2.y);
				cout << " ";										     // it will empty the previous position
				playerpos2 = newPos2;									 // default playerpos is the when u give in start but its also kep updating
				drawshopthings(playerpos2, hintmanstandingpos, doorpos); // we didnt require destpos bcz we need final desiton once
			}
			if (playerinteractingpos(newPos2, hintmanstandingpos) == true)
			{
				system("cls");
				instructionbox("In this puzzle you have to follow the correct sequence", "", "");

				system("cls");
				sequenceGame();
				system("cls");
				playerpos2 = { 26,8 };
				goto shopnearAI4;//line 294  
			}
			if (door1(newPos2, doorpos))
			{
				playerpos = { 4, (length / 2) - 1 };
				goto mainmap; // 221
			}
		}//while2
	}//if for shop1 entry

	//////////////////////////////////////////////
	//////////////////level2//////////////////////
	//////////////////////////////////////////////
	if (level2checker == true)
	{
		Position enemypos = { 0,0 };
		Position healthpotionpos = { 0,0 };
		Position weaponpos = { 0,0 };
		Position playerpos3 = { width / 2, length - 2 };
		Position destpos3 = { width / 2, 3 };
		Position newPos3 = playerpos3;
		bool battlerangechecker = false;
		bool healthpotionchecker = false;
		bool weaponchecker = false;
		system("cls");
		srand(time(0));
		border();
		dialogueBox();
		drawposition(playerpos3, destpos3);
		randomspawm(enemypositions, 50);
		//randomspawm(healthpotionspos, 30);
		/*randomweapons(30);*/
		while (true)
		{
			move(preY, preX, newPos3);
			//move

			//healthbar(health, "player");
			if (getCharacterAtPosition(newPos3.x, newPos3.y) == '#') //position matters
			{
				newPos3.x = preX;
				newPos3.y = preY;
			}
			if (!checkcollision(newPos3)) // colliosn function is working oposite bcz its easy to code area of map
			{
				gotoxy(playerpos3.x, playerpos3.y);
				cout << " ";                      // it will empty the previous position
				playerpos3 = newPos3;               // default playerpos is the when u give in start but its also kep updating
				drawposition(playerpos3, destpos3); // we didnt require destpos bcz we need final desiton once
			}
			//detecting enemy 
			playerinteraction(newPos3, enemypos, battlerangechecker, enemypositions);
			// it will change battlerange checker to true 
			if (battlerangechecker == true)
			{
				break;
			}

			/*detecting health potion*/
			//playerinteraction(newPos3, healthpotionpos, healthpotionchecker, ); // 10 = loop counter

			//if (healthpotionchecker == true)
			//{
			//	displayMessage("You got health Potion from this place", width + 7, 8, 20);
			//	health++;
			//}

		}//while
		if (battlerangechecker == true)
		{

			system("cls");
			/*battlerange();*/
			battle();
		}

	}//if level2


	return 0;
} // main

