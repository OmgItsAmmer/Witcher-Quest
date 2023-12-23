#pragma once
#include "fundamentals.h"
using namespace std;
void displayBoard(const vector<char>& board) {
    for (int i = 0; i < board.size(); i++) {
        if (i % 4 == 0) cout << "\n";
        cout << board[i] << " ";
    }
    cout << "\n";
}

void memoryGame() {
    cout << endl;
    cout << endl;
    cout << endl;
    cout << endl;
    cout << endl;
    const vector<char> items = { 'A', 'B', 'C', 'D', 'E', 'A', 'B', 'C', 'D', 'E','F','F' };
    vector<char> board(items.size(), '*');

    vector<char> shuffledItems = items;
    random_shuffle(shuffledItems.begin(), shuffledItems.end());

    string firstChoice, secondChoice;
    int matches = 0, counter = 0;
    string decision;
    while (matches < items.size() / 2) {
        displayBoard(board);
        cout << "Choose two cards to flip (0-11): " << endl;
        cout << "First choice: ";
        cin >> firstChoice;
        if (firstChoice == "exit")
        {   
            break;
        }
        cout << "Second choice: ";
        cin >> secondChoice;
        cout << endl;
		//TODO: ammer and 2 giving error fix it

        if (stoi(firstChoice) > 11 || stoi(secondChoice) > 11)
        {   
            cout << "Enter valid number" << endl;
            Sleep(1000);
        }
        else
        {
            board[stoi(firstChoice)] = shuffledItems[stoi(firstChoice)];
            board[stoi(secondChoice)] = shuffledItems[stoi(secondChoice)];
            displayBoard(board);

            if (shuffledItems[stoi(firstChoice)] == shuffledItems[stoi(secondChoice)]) {
                cout << "Match found!\n";
                matches++;
            }
            else {
                cout << "No match, try again.\n";
                board[stoi(firstChoice)] = '*';
                board[stoi(secondChoice)] = '*';
				Sleep(1000);
                
            }
        }
    }
    cout << "You've matched all pairs!\n";
}



//////////////////////////
////// sequence game ////
/////////////////////////

void sequenceGame(){
    srand(time(0)); // Seed the random number generator
    vector<int> sequence;
    int level = 1;
    bool correct = true;
    int guesslimit = 0;

    cout << endl;
    cout << endl;
    cout << endl;
    cout << endl;
    cout << endl;

    while (correct && guesslimit < 10 ) {
        cout << "Level " << level << endl;
        sequence.push_back(rand() % 10); // Add a new number to the sequence
        guesslimit++;
        // Display the sequence
        for (int num : sequence) {
            cout << num << " ";
            Sleep(1000); // Pause for a second
        }
        cout << "\r" << string(20, ' ') << "\r"; // Clear the sequence from the screen

        // Player inputs the sequence
        for (int i = 0; i < sequence.size(); i++) {
            int playerInput;
            cout << "Enter number " << i + 1 << ": ";
            cin >> playerInput;

            if (playerInput != sequence[i]) {
                correct = false;
                break;
            }
        }

        if (correct) {
            cout << "Correct! Moving to next level." << endl;
            level++;
        }
        else {
            cout << "Incorrect sequence. Game over!" << endl;
        }
    }

    
}

////////////////////////////////
/////// TICTACTOE /////////////
///////////////////////////////






const int TICSIZE = 3; //range of 2D array

char board[TICSIZE][TICSIZE] = { {'1','2','3'},{'4','5','6'},{'7','8','9'} };
int choice;
int row, column;
char turn = 'X';
bool draw = false;

void displayBoard() {
    for (int i = 0; i < TICSIZE; i++) {
        for (int j = 0; j < TICSIZE; j++) {
            cout << board[i][j] << " ";
        }
        cout << endl;
    }
}

void playerTurn() {
    if (turn == 'X') {
        cout << "Player [X] turn : ";
        cin >> choice;
    }
    else {
        std::cout << "Computer [O] turn...\n";
        do {
            srand(time(0));
            choice = rand() % 9 + 1; // Random choice between 1 and 9
        } while (board[(choice - 1) / TICSIZE][(choice - 1) % TICSIZE] == 'X' || board[(choice - 1) / TICSIZE][(choice - 1) % TICSIZE] == 'O');
    }

    switch (choice) {
    case 1: row = 0; column = 0; break;
    case 2: row = 0; column = 1; break;
    case 3: row = 0; column = 2; break;
    case 4: row = 1; column = 0; break;
    case 5: row = 1; column = 1; break;
    case 6: row = 1; column = 2; break;
    case 7: row = 2; column = 0; break;
    case 8: row = 2; column = 1; break;
    case 9: row = 2; column = 2; break;
    default: std::cout << "Invalid Move" << std::endl;
    }

    if (turn == 'X' && board[row][column] != 'X' && board[row][column] != 'O') {
        board[row][column] = 'X';
        turn = 'O';
    }
    else if (turn == 'O' && board[row][column] != 'X' && board[row][column] != 'O') {
        board[row][column] = 'O';
        turn = 'X';
    }
    else if (turn == 'X') {
        std::cout << "Box already filled!\n Please choose another!\n\n";
        playerTurn();
    }
}

void playTicTacToe() {
    system("cls");
    gotoxy(75,3);
    cout << "The TIC TAC TOE";
    cout << "\r";
;    while (true) {
        displayBoard();
        playerTurn();
        // Game logic for win or draw
    }
}


////////////////////////////////////////////////////////////////
//////////////////RIDDLE GAME LOOP ////////////////////////////
////////////////////////////////////////////////////////////////



void playRiddleGame() {
    string riddle = "What has keys but can't open locks?";
    string answer = "piano";
    string guess;
    int attempts = 3;

    cout << "You ask The Witcher: \"" << riddle << "\"\n";

    while (attempts > 0) {
        cout << "The Witcher guesses: ";
        getline(cin, guess);

        // Convert the guess to lowercase for case-insensitive comparison
        for (auto& c : guess) c = tolower(c);

        if (guess == answer) {
            cout << "Correct! The Witcher has solved the riddle.\n";
            return;
        }
        else {
            attempts--;
            cout << "Incorrect. " << attempts << " attempts remaining.\n";
        }
    }

    cout << "The Witcher couldn't solve the riddle. The correct answer was: " << answer << ".\n";
}





