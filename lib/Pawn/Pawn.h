#ifndef P_H
#define P_H
#include "ChessSquare.h"
class Pawn
{
    public:
        unsigned int ID = PAWN;
        bool Color;
        bool InPlay;

        enum ChessPieceEnum{
            PAWN,
            KNIGHT,
            BISHOP,
            ROOK,
            QUEEN,
            KING};

        Pawn(bool lcolor, ChessPieceEnum lid);

        int MarkNextLegalMove(ChessSquare* Origin,ChessSquare* currentPiece);
};


#endif