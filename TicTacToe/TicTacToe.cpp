// TicTacToe.cpp : Defines the entry point for the console application.
// Author : Rabeez Riaz
// Tic Tac Toe game playable either by 2 players or by a player against the computer.

#include <iostream>
#include "stdafx.h"
#include "Game.h"
using namespace std;


int _tmain(int argc, _TCHAR* argv[])
{
	Game game = Game();

	game.welcome();						// Display welcome message and ask number of players

	game.drawBoard();					// Display empty game board

	while (game.gameStatus() == 0)		// Game loop while game is not over
	{
		game.drawBoard();				// Draw updated board

		game.makeMove();				/// Get move and validate it

		if (game.gameStatus() != 0) break;				/// Check win/draw status

		game.changeCurrentPlayer();		// Switch the current player
	}

	game.endGame();						// Display ending message

	return 0;
}

