
#ifndef BISH_H
#define BISH_H
#include "ChessSquare.h"
#include "Traverse.h"
class Bishop
{
    public:
        unsigned int ID=BISHOP;
        bool Color;
        bool InPlay;

        enum ChessPieceEnum{
            PAWN,
            KNIGHT,
            BISHOP,
            ROOK,
            QUEEN,
            KING};

        Bishop(bool lcolor);

        void MarkNextLegalMoves(ChessSquare* currentCell, int size);

};


#endif