#include "ChessSquare.h"
#include "Traverse.h"
class Queen
{
    public:
        unsigned int ID = QUEEN;
        bool Color;
        bool InPlay;

        enum ChessPieceEnum{
            PAWN,
            KNIGHT,
            BISHOP,
            ROOK,
            QUEEN,
            KING};

        Queen(bool lcolor, ChessPieceEnum lid);

         void MarkNextLegalMoves(ChessSquare* Origin,ChessSquare* currentCell);
};