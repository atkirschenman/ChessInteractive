#include "ChessSquare.h"
#ifndef BISH_H
#define BISH_H

class Bishop
{
    public:
        unsigned int ID;
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