#ifndef CP_H
#define CP_H

#include "ChessSquare.h"
#include "Traverse.h"
class Rook
{
    public:
        unsigned int ID = ROOK;
        bool Color;
        bool InPlay;

        enum ChessPieceEnum{
            PAWN,
            KNIGHT,
            BISHOP,
            ROOK,
            QUEEN,
            KING};

        Rook(bool lcolor, ChessPieceEnum lid);

         void MarkNextLegalMoves(ChessSquare* Origin,ChessSquare* currentCell);
};

#endif