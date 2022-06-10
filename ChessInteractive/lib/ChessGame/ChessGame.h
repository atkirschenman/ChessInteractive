#include "ChessSquare.h"
#ifndef CG_H
#define CG_H

class ChessGame
{
    
    public:
    ChessSquare theGrid;
    void ClearBoard(ChessSquare lGrid, int Size);
    void MarkNextLegalMoves(ChessSquare currentCell, ChessSquare lGrid, int Size);
    void SetupBoard(ChessSquare* lGrid, int Size);
};


#endif