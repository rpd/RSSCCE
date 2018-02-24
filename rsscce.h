
/* rsscce.h */
/* Description of a chessboard side(player)*/
typedef struct {    int Colour;    int Piece;} Side;
/* Description of a chess move */
typedef struct {    int from;    int to;} Move;
/* constants */
#define SIDENUM      64
#define SIDEPLAYER    8
#define PIECENUM      6
#define WHITE         0
#define BLACK         1
#define PAWN          0
#define KNIGHT        1
#define BISHOP        2
#define ROOK          3
#define QUEEN         4
#define KING          5
#define EMPTY         6
/* macro */
#define RANKS(x)      (x >> 3)
#define FILES(x)      (x & 7)
/* Miscellaneous */
#define BOOL          int
#define TRUE          1
#define FALSE         0
