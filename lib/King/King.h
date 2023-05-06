#ifndef KING_H
#define KING_H
#include "ChessSquare.h"
#include "Traverse.h"
class King
{
    public:
        unsigned int ID = KING;
        bool Color;
        bool InPlay;

        enum ChessPieceEnum{
            PAWN,
            KNIGHT,
            BISHOP,
            ROOK,
            QUEEN,
            KING};

        King(bool lcolor, ChessPieceEnum lid);

         void MarkNextLegalMoves(ChessSquare* Origin,ChessSquare* currentCell);
};


#endif