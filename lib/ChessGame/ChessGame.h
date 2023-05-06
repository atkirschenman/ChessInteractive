
#ifndef CG_H
#define CG_H
#include "ChessBoard.h"

class ChessGame
{
    
    public:
    ChessGame();
    void ClearLegalMoves(int Size);
    void MarkNextLegalMoves(ChessSquare* origin, ChessSquare* currentCell);
    void SetupBoard(ChessSquare* origin, int Size);
    private:
    ChessBoard* ClassicBoard = new ChessBoard(8);
    ChessSquare* Origin;
};

#endif