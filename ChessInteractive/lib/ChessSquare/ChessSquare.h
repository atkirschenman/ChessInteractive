//#include <Arduino.h>
#include "ChessPiece.h"
#ifndef CS_H
#define CS_H

class ChessSquare
{
    public:
        int RowNumber;
        int ColumnNumber;
        bool CurrentlyOccupied;
        bool LegalNextMove;
        ChessSquare* Up;
        ChessSquare* Down;
        ChessSquare* Left;
        ChessSquare* Right;
        ChessPiece* OccupiedPiece;

        ChessSquare(int x, int y); 
        ChessSquare();

};


#endif