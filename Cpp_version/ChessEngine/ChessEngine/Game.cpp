#include "Game.h"

Game::Game()
{
	board = Board::GetInitialBoard(); // get starting setup for the game

	currentTurn = Colour::White;
	moveNumber = 1;
}

int Game::getNumberOfMovesMadeByWhite()
{
	return moveNumber / 2;
}

int Game::getNumberOfMovesMadeByBlack()
{
	return (moveNumber - 1) / 2;
}
