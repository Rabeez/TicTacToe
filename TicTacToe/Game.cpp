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
	if (this->boardArray[0] == this->currentPlayer && this->boardArray[1] == this->currentPlayer && this->boardArray[2] == this->currentPlayer) return 1;
	else if (this->boardArray[3] == this->currentPlayer && this->boardArray[4] == this->currentPlayer && this->boardArray[5] == this->currentPlayer) return 1;
	else if (this->boardArray[6] == this->currentPlayer && this->boardArray[7] == this->currentPlayer && this->boardArray[8] == this->currentPlayer) return 1;
	//else return 2;

	return 0;
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