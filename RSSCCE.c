/*RSSCCEv1.0: Richard & Sean's Simple C Chess Engine 
A simple C programmed basic chess engine, as an exercise for basic simple learning of C programming
and creating a simple chess engine. This code is heavily based on chess engine LaMoSca 
(LAboratorio di MOtori per SCAcchi)versione 0.01  2001 Pietro Valocchi

Code repository 
GitHub
https://github.com/rpd/RSSCCE*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "rsscce.h"              /* Include the header here, to obtain the function declaration */ 

int intromsg(void);              /* Prototype */
int winboard(void);              /* Prototype */
int uci(void);                   /* Prototype */
void Initialisation();           /* Prototype */
void showboard();
void MoveInput();
void Moves(); 

int main(int argc, char **argv)
{	
 intromsg();		
 char Command[256];	/*Command Line player input	(typed move (coordinate) input or help command)*/	
 Initialisation();	
 showboard();	
 while (TRUE) {		/* Get console input */		printf("RSSCCEv1.0> ");		
               if (scanf("%s", Command) == EOF)			return 0;		
               /* Interpret command line command */		
               if (!strcmp(Command, "help")) 
               {			
                printf("new   - new game\n");			
                printf("quit  - end the program\n");			
                printf("d     - show the chessboard\n");		
                printf("move - enter coordinates;eg: e2e4\n");			continue;		}		
               if (!strcmp(Command, "new")) 
               {			
                Initialisation();			
                showboard();			
                continue;		}		
               if (!strcmp(Command, "d"))
               {			
                showboard();			continue;		
               }		
               if (!strcmp(Command, "quit")) 
               {			
                printf("RSSCCE> BYE!\n");			
                return 0;		
               }	
               /* interprets the input as coordinates of a move	*/		
               MoveInput(Command);		
               /* display result*/		
               showboard();	
              }                               		
               return 0;}

int intromsg(void)	{		
                    printf("RSSCCEv1.0.\n");		
                    printf("\"Help\" RSSCCEv1.0 list of commands.\n");	   
                    printf("\n");						
                    return 0;	
                    }
/* representation of the chessboard:  
vector with two integers for each side  Colour = WHITE, BLACK or EMPTY *
Piece = PAWN, KNIGHT, BISHOP, ROOK, QUEEN, KING or EMPTY*/
Side B[SIDENUM]; // side B[case number]
/* White piece symbol for showboard() */
char WhitePieceSymbol[PIECENUM] = "PNBRQK";
/* Black piece symbol for showboard() */
char BlackPieceSymbol[PIECENUM] = "pnbrqk";
/* Initial chess piece positions */
int ColourInit[SIDENUM] = {	BLACK,   BLACK,   BLACK,   BLACK,   BLACK,   BLACK,   BLACK,   BLACK,	
                           BLACK,   BLACK,   BLACK,   BLACK,   BLACK,   BLACK,   BLACK,   BLACK,	
                           EMPTY,  EMPTY,  EMPTY,  EMPTY,  EMPTY,  EMPTY,  EMPTY,  EMPTY,	EMPTY,  
                           EMPTY,  EMPTY,  EMPTY,  EMPTY,  EMPTY,  EMPTY,  EMPTY,	EMPTY,  EMPTY,  
                           EMPTY,  EMPTY,  EMPTY,  EMPTY,  EMPTY,  EMPTY,	EMPTY,  EMPTY,  EMPTY,  
                           EMPTY,  EMPTY,  EMPTY,  EMPTY,  EMPTY,	
                           WHITE, WHITE, WHITE, WHITE, WHITE, WHITE, WHITE, WHITE,	WHITE, WHITE, 
                           WHITE, WHITE, WHITE, WHITE, WHITE, WHITE};
int PieceInit[SIDENUM] = {	ROOK,  KNIGHT,  BISHOP, QUEEN, KING, BISHOP, KNIGHT, ROOK,	
                          PAWN, PAWN,  PAWN,  PAWN, PAWN, PAWN,  PAWN, PAWN,	
                          EMPTY,  EMPTY,  EMPTY,  EMPTY,  EMPTY,  EMPTY,  EMPTY, 
                          EMPTY,	EMPTY,  EMPTY,  EMPTY,  EMPTY,  EMPTY,  EMPTY,  
                          EMPTY,  EMPTY,	EMPTY,  EMPTY,  EMPTY,  EMPTY,  EMPTY,  
                          EMPTY,  EMPTY,  EMPTY,	EMPTY,  EMPTY,  EMPTY,  EMPTY,  
                          EMPTY,  EMPTY,  EMPTY,  EMPTY,	
                          PAWN, PAWN,  PAWN,  PAWN, PAWN, PAWN,  PAWN, PAWN,	
                          ROOK,  KNIGHT, BISHOP, QUEEN, KING, BISHOP, KNIGHT, ROOK};
/* Initilisation() initialises the chessboard */
void Initialisation() {	
 int i;	for (i = 0; i < SIDENUM; i++) {		
  B[i].Colour = ColourInit[i];		B[i].Piece  = PieceInit[i];	}}
/* showboard() displays the position of the pieces*/
void showboard() {	
 int i;		printf("\n8 ");	for (i = 0; i < SIDENUM; i++) 
 {		switch (B[i].Colour) {			case WHITE:				printf(" %c", WhitePieceSymbol[B[i].Piece]);				break;		
                          case BLACK:				printf(" %c", BlackPieceSymbol[B[i].Piece]);				break;		
                          case EMPTY:				printf(" .");				break;		}		if ((i + 1) % SIDEPLAYER == 0 && i != (SIDENUM - 1))			
  printf("\n%d ", 7 - RANKS(i));	
 }	
 printf("\n\n   a b c d e f g h\n\n");
}
/* Moves() save a move on the board */
void Moves(Move *M) {	
 B[M->to].Colour  = B[M->from].Colour;	
 B[M->to].Piece   = B[M->from].Piece;	B[M->from].Colour = EMPTY;	
 B[M->from].Piece  = EMPTY;
}
/* MoveInput() interprets the coordinates of a move*/	
void MoveInput(char * Input) {	Move M;	
                              /* calculates the index of the starting square from the first two characters */	
                              M.from = (Input[0] - 'a') + SIDEPLAYER * (SIDEPLAYER - (Input[1] - '0'));	
                              /* calculates the index of the destination square from the remaining characters */
                              M.to  = (Input[2] - 'a') + SIDEPLAYER * (SIDEPLAYER - (Input[3] - '0'));	
                              /* moving the piece*/	
                              Moves(&M);}

int winboard(void)	{			
 return 0;	
}

int uci(void)	{
 return 0;	
}
