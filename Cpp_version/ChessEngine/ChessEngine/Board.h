#pragma once

#include "Types.h"
#include "PieceType.h"
#include "Colour.h"

class Board
{
public:
	Board();
	void SetSquareToPiece(const char *coordinate, PieceType piece, Colour colour);
	void SetSquareToPiece(int arrayIndex, PieceType piece, Colour colour);
	static Board& GetInitialBoard();

private:
	byte * boardState;

};