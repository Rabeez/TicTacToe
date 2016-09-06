#include <iostream>
#include <string>
#include <ctime>
#include "Game.h"

using namespace std;

// Constructor function
Game::Game()
{
	srand(time(0));							// Seed the random number generator
	this->numOfPlayers = 0;					// Set initail number of players to 0 (dummy value)
	this->clearBoard();						// Ensure that a new game starts with a clean board
	this->currentPlayer = rand() % 2 + 1;	// Pick random player to start game
}

// Display welcome message and get user's choice for number of players
void Game::welcome()
{
	bool firstTime = true;
	do
	{
		system("cls");
		cout << "\tWelcome to Tic Tac Toe" << endl << endl
			<< "Enter 1 to play versus the computer." << endl
			<< "Enter 2 to play versus a friend." << endl;
		if (!firstTime) cout << "You entered an invalid number of players. Try again." << endl;
		cout << "Your choice: ";
		int choice = this->getInput();
		firstTime = false;
		if (choice == 1 || choice == 2) 
		{ 
			this->numOfPlayers = choice;
		}
	} while (this->numOfPlayers == 0);
}

// Gets an integer value from the user
int Game::getInput()
{
	int output;
	cin >> output;
	return output;
}

// Clear all slots on the game board
void Game::clearBoard()
{
	for (int i = 0; i < 9; i++)
	{
		this->boardArray[i] = 0;
	}
}

// Display entire game interface
void Game::drawBoard()
{
	system("cls");
	cout << "\tTic Tac Toe" << endl;

	string message = "Empty Message";
	if (this->numOfPlayers == 1)	// human versus computer
	{
		message = (this->currentPlayer == 1) ? ("*Player 1 (X)\tComputer (O)") : ("Player 1 (X)\t*Computer (O)");
	}
	else							// human versus human
	{
		message = (this->currentPlayer == 1) ? ("*Player 1 (X)\tPlayer 2 (O)") : ("Player 1 (X)\t*Player 2 (O)");
	}
	cout << message << endl;

	cout << "     |     |     " << endl;
	cout << "  " << symbolify(this->boardArray[0]) << "  |  " << symbolify(this->boardArray[1]) << "  |  " << symbolify(this->boardArray[2]) << endl;

	cout << "_____|_____|_____" << endl;
	cout << "     |     |     " << endl;

	cout << "  " << symbolify(this->boardArray[3]) << "  |  " << symbolify(this->boardArray[4]) << "  |  " << symbolify(this->boardArray[5]) << endl;

	cout << "_____|_____|_____" << endl;
	cout << "     |     |     " << endl;

	cout << "  " << symbolify(this->boardArray[6]) << "  |  " << symbolify(this->boardArray[7]) << "  |  " << symbolify(this->boardArray[8]) << endl;

	cout << "     |     |     " << endl << endl;

	// Display prompt to make a move
	if (this->numOfPlayers == 2)	// human versus human
		cout << "Player " << this->currentPlayer << " choose a cell: ";
	else							// human versus computer
	{
		if (this->currentPlayer == 1)
			cout << "Player 1 choose a cell: ";
		else if (this->currentPlayer == 2)
			cout << "The computer is making a move.";
	}
}

// Execute a single move
void Game::makeMove()
{
	if (this->numOfPlayers == 1 && this->currentPlayer == 2)
		this->AIMove();
	else
	{
		int move;
		bool firstTime = true;
		do
		{
			if (!firstTime) cout << "(Invalid cell, try again) ";
			move = this->getInput();
			firstTime = false;
		} while (!this->isValidMove(move));

		this->boardArray[move - 1] = this->currentPlayer;
	}
}

// Check if a chosen move is valid
bool Game::isValidMove(int move)
{
	if (move >= 1 && move <= 9)
	{
		if (this->boardArray[move-1] == 0) return true;
	}
	return false;
}

// Switch the current player
void Game::changeCurrentPlayer()
{
	if (this->currentPlayer == 1) this->currentPlayer = 2;
	else if (this->currentPlayer == 2) this->currentPlayer = 1;
}

// Convert board value into player symbols
char Game::symbolify(int value)
{
	if (value == 1) return 'X';
	else if (value == 2) return 'O';
	else return ' ';
}

// Check if someone has won or if the game is a draw
int Game::gameStatus()
{
	int sumR1, sumR2, sumR3, sumC1, sumC2, sumC3, sumD1, sumD2;
	sumR1 = sumR2 = sumR3 = sumC1 = sumC2 = sumC3 = sumD1 = sumD2 = 0;

#pragma region "First row sum"
	sumR1 += (this->boardArray[0] != 0) ? this->boardArray[0] : 0;
	sumR1 += (this->boardArray[1] != 0) ? this->boardArray[1] : 0;
	sumR1 += (this->boardArray[2] != 0) ? this->boardArray[2] : 0;
#pragma endregion

#pragma region "Second row sum"
	sumR2 += (this->boardArray[3] != 0) ? this->boardArray[3] : 0;
	sumR2 += (this->boardArray[4] != 0) ? this->boardArray[4] : 0;
	sumR2 += (this->boardArray[5] != 0) ? this->boardArray[5] : 0;
#pragma endregion

#pragma region "Third row sum"
	sumR3 += (this->boardArray[6] != 0) ? this->boardArray[6] : 0;
	sumR3 += (this->boardArray[7] != 0) ? this->boardArray[7] : 0;
	sumR3 += (this->boardArray[8] != 0) ? this->boardArray[8] : 0;
#pragma endregion

#pragma region "First column sum"
	sumC1 += (this->boardArray[0] != 0) ? this->boardArray[0] : 0;
	sumC1 += (this->boardArray[3] != 0) ? this->boardArray[3] : 0;
	sumC1 += (this->boardArray[6] != 0) ? this->boardArray[6] : 0;
#pragma endregion

#pragma region "Second column sum"
	sumC2 += (this->boardArray[1] != 0) ? this->boardArray[1] : 0;
	sumC2 += (this->boardArray[4] != 0) ? this->boardArray[4] : 0;
	sumC2 += (this->boardArray[7] != 0) ? this->boardArray[7] : 0;
#pragma endregion

#pragma region "Third column sum"
	sumC3 += (this->boardArray[2] != 0) ? this->boardArray[2] : 0;
	sumC3 += (this->boardArray[5] != 0) ? this->boardArray[5] : 0;
	sumC3 += (this->boardArray[8] != 0) ? this->boardArray[8] : 0;
#pragma endregion

#pragma region "First diagonal sum"
	sumD1 += (this->boardArray[0] != 0) ? this->boardArray[0] : 0;
	sumD1 += (this->boardArray[4] != 0) ? this->boardArray[4] : 0;
	sumD1 += (this->boardArray[8] != 0) ? this->boardArray[8] : 0;
#pragma endregion

#pragma region "Second diagonal sum"
	sumD2 += (this->boardArray[2] != 0) ? this->boardArray[2] : 0;
	sumD2 += (this->boardArray[4] != 0) ? this->boardArray[4] : 0;
	sumD2 += (this->boardArray[6] != 0) ? this->boardArray[6] : 0;
#pragma endregion

	if (sumR1 != 0 && sumR2 != 0 && sumR3 != 0 && 
		sumC1 != 0 && sumC2 != 0 && sumC3 != 0 && 
		sumD1 != 0 && sumD2 != 0)
		if (sumR1 % 3 == 0 || sumR2 % 3 == 0 || sumR3 % 3 == 0 || 
			sumC1 % 3 == 0 || sumC2 % 3 == 0 || sumC3 % 3 == 0 || 
			sumD1 % 3 == 0 || sumD2 % 3 == 0) return 1;		// Current player won


	int boardSum = 0;
	for (int i = 0; i < 9; i++)
	{
		boardSum += this->boardArray[i];
	}
	if (boardSum > 9) return 2;		// Draw

	return 0;		// Game not over
}

// Display end game message
void Game::endGame()
{
	system("cls");
	cout << "\tTic Tac Toe" << endl;

	if (this->gameStatus() == 1)			// Someone won
	{
		if (this->numOfPlayers == 2)		// Human versus human
			cout << "Player " << this->currentPlayer << " Wins." << endl;
		else if (this->numOfPlayers == 1)	// Human versus computer
		{
			if (this->currentPlayer == 1) cout << "Player 1 Wins." << endl;
			else if (this->currentPlayer == 2) cout << "The Computer Wins." << endl;
		}
	}
	else if (this->gameStatus() == 2)		// Draw
		cout << "The game is a draw." << endl;

	cout << "\tThank you for playing\n" << endl;
}

// Utilize AI to make a move
void Game::AIMove()
{
	//cout << "Method not implemented." << endl;
	int move;
	do move = rand() % 9 + 1;
	while (this->boardArray[move - 1] != 0);

	this->boardArray[move - 1] = this->currentPlayer;
}