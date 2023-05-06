#ifndef KNIGHT_H
#define KNIGHT_H
#include "ChessSquare.h"
#include "Traverse.h"
class Knight
{
    public:
        unsigned int ID = KNIGHT;
        bool Color;
        bool InPlay;

        enum ChessPieceEnum{
            PAWN,
            KNIGHT,
            BISHOP,
            ROOK,
            QUEEN,
            KING};

        Knight(bool lcolor, ChessPieceEnum lid);

         void MarkNextLegalMoves(ChessSquare* Origin);
};

#endif