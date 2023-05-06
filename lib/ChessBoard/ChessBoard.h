
#ifndef CB_H
#define CB_H
#include "ChessSquare.h"
#include "ChessGame.h"
#include "Traverse.h"
class ChessBoard {

	public:	
    int Size;
    
    ChessSquare* Origin = new ChessSquare();
    //Constructors//
    ChessBoard(int s);

    ChessSquare* ReturnOrigin();


 

    
};
#endif