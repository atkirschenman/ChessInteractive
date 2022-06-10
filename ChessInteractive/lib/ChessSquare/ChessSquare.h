//#include <Arduino.h>
#include "ChessPiece.h"
#ifndef CS_H
#define CS_H

class ChessSquare
{
    public:
        int RowNumber;
        int ColumnNumber;
        bool CurrentOccupied;
        bool LegalNextMove;

        ChessPiece OccupiedPiece();

        ChessSquare(int x, int y); 
        ChessSquare();

};


#endif