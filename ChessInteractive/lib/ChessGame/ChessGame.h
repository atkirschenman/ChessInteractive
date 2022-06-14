
#ifndef CG_H
#define CG_H
#include "ChessSquare.h"

class ChessGame
{
    
    public:
    void ClearBoard(ChessSquare* origin, int Size);
    void MarkNextLegalMoves(ChessSquare* origin, ChessSquare* currentCell);
    void SetupBoard(ChessSquare* origin, int Size);
};


#endif