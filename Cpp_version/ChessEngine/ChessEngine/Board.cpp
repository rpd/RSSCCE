#include <stdlib.h>
#include "Board.h"
#include <string.h>
#include <ctype.h>
#include "Types.h"

// stores a representation of the board
Board::Board()
{
	// initialise the board
	// we have options here, you can represent the board as a collection of strutures/classes, each one of 
	//which stores type + colour
	// OR (my recommended way), each space is a byte, the top bit can dictate colour and the bottom 7 bits
	// can dictate the piece type

	// for simplicity lets use bit 7 to indicate that there is a piece in the square or not
	
	// a special piece type can b
	boardState = (byte*) malloc(64);
}

void Board::SetSquareToPiece(const char * coordinate, PieceType piece, Colour colour)
{
	if (strlen(coordinate) < 2) return;
	auto horizonalChar = toupper(coordinate[0]);
	auto verticalChar = coordinate[1];

	auto horizontalIndex = horizonalChar - 65;
	auto verticalIndex = verticalChar - 48;

	auto arrayIndex = verticalIndex * 8 + horizontalIndex;
	if (arrayIndex >= 64) return;
	return SetSquareToPiece(arrayIndex, piece, colour);
}

void Board::SetSquareToPiece(int arrayIndex, PieceType piece, Colour colour)
{
	byte value = colour == Colour::White ? 0x00 : 0x80; // if white, top bit SET
	value |= 0x040 | (byte)piece; // bit 6 set (0x50) as there is a piece on the board. bottom 3 bits used to store piece
	boardState[arrayIndex] = value;
}

Board& Board::GetInitialBoard()
{
	auto baseBoard = new Board();
	baseBoard->SetSquareToPiece("A2", PieceType::Pawn, Colour::White);
	baseBoard->SetSquareToPiece("B2", PieceType::Pawn, Colour::White);
	baseBoard->SetSquareToPiece("C2", PieceType::Pawn, Colour::White);
	baseBoard->SetSquareToPiece("D2", PieceType::Pawn, Colour::White);
	baseBoard->SetSquareToPiece("E2", PieceType::Pawn, Colour::White);
	baseBoard->SetSquareToPiece("F2", PieceType::Pawn, Colour::White);
	baseBoard->SetSquareToPiece("G2", PieceType::Pawn, Colour::White);
	baseBoard->SetSquareToPiece("H2", PieceType::Pawn, Colour::White);
	baseBoard->SetSquareToPiece("A1", PieceType::Rook, Colour::White);
	baseBoard->SetSquareToPiece("B1", PieceType::Knight, Colour::White);
	baseBoard->SetSquareToPiece("C1", PieceType::Bishop, Colour::White);
	baseBoard->SetSquareToPiece("D1", PieceType::Queen, Colour::White);
	baseBoard->SetSquareToPiece("E1", PieceType::King, Colour::White);
	baseBoard->SetSquareToPiece("F1", PieceType::Bishop, Colour::White);
	baseBoard->SetSquareToPiece("G1", PieceType::Knight, Colour::White);
	baseBoard->SetSquareToPiece("H1", PieceType::Rook, Colour::White);

	baseBoard->SetSquareToPiece("A7", PieceType::Pawn, Colour::Black);
	baseBoard->SetSquareToPiece("B7", PieceType::Pawn, Colour::Black);
	baseBoard->SetSquareToPiece("C7", PieceType::Pawn, Colour::Black);
	baseBoard->SetSquareToPiece("D7", PieceType::Pawn, Colour::Black);
	baseBoard->SetSquareToPiece("E7", PieceType::Pawn, Colour::Black);
	baseBoard->SetSquareToPiece("F7", PieceType::Pawn, Colour::Black);
	baseBoard->SetSquareToPiece("G7", PieceType::Pawn, Colour::Black);
	baseBoard->SetSquareToPiece("H7", PieceType::Pawn, Colour::Black);
	baseBoard->SetSquareToPiece("A8", PieceType::Rook, Colour::Black);
	baseBoard->SetSquareToPiece("B8", PieceType::Knight, Colour::Black);
	baseBoard->SetSquareToPiece("C8", PieceType::Bishop, Colour::Black);
	baseBoard->SetSquareToPiece("D8", PieceType::Queen, Colour::Black);
	baseBoard->SetSquareToPiece("E8", PieceType::King, Colour::Black);
	baseBoard->SetSquareToPiece("F8", PieceType::Bishop, Colour::Black);
	baseBoard->SetSquareToPiece("G8", PieceType::Knight, Colour::Black);
	baseBoard->SetSquareToPiece("H8", PieceType::Rook, Colour::Black);
	
	return *baseBoard;
}

