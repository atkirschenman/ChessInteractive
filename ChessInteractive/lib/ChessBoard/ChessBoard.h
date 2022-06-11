
#ifndef CB_H
#define CB_H

#include "ChessSquare.h"
#include "ChessGame.h"
#include "Traverse.h"
class ChessBoard {

	public:	
    int Size;
    ChessGame myChessGame;
    ChessSquare* theGrid;
    

    //Constructors//
    ChessBoard(int s);
    
    void SetupBoard();

    void MarkNextLegalMoves(ChessSquare currentCell, int Id);

    void CleartheBoard();

    





	
};
#endif