#pragma once
#include <iostream>
#include <string>

class Game
{
private:
	int boardArray[9];		// 0->empty, 1->player1, 2->player2/AI
	int numOfPlayers;		// 1->Human V AI, 2->Human V Human
	int currentPlayer;		// player whose move it currently is (1 or 2)

public:
	// Constructor function
	Game();

	// Display welcome message and choice for number of players
	void welcome();

	// Gets an integer value from the user
	int getInput();

	// Clear all slots on the game board
	void clearBoard();

	// Display entire game interface
	void drawBoard();

	// Execute a single move
	void makeMove();

	// Check if a chosen move is valid
	bool isValidMove(int move);

	// Switch the current player
	void changeCurrentPlayer();

	// Convert board value into player symbols
	char symbolify(int value);

	// 0->Game continues, 1->Current player wins, 2->Game is a draw
	int gameStatus();

	// Display end game message
	void endGame();

	// Utilize AI to make a move
	void AIMove();

};

