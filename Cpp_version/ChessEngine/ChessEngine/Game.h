#pragma once

#include "Board.h"
#include "Colour.h"

class Game
{
private:
	Colour currentTurn;
	int moveNumber;
	Board board;

public:
	Game();
	int getNumberOfMovesMadeByWhite();
	int getNumberOfMovesMadeByBlack();

};