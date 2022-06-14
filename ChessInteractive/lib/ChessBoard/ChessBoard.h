
#ifndef CB_H
#define CB_H
#include "ChessSquare.h"
#include "ChessGame.h"
#include "Traverse.h"
class ChessBoard {

	public:	
    int Size;
    ChessGame myChessGame;
    ChessSquare* Origin;
    //Constructors//
    ChessBoard(int s);


    void SetupBoard();

    void MarkNextLegalMoves(ChessSquare* Origin, ChessSquare* currentCell);

    void CleartheBoard();

    
};
#endif