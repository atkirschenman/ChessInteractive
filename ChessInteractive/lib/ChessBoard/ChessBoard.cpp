#include "ChessBoard.h"



    ChessBoard::ChessBoard(int s)
	{
		Size = s;
    	theGrid = new ChessSquare[s * s];
	}
    
    void ChessBoard::SetupBoard()
	{
		myChessGame.SetupBoard(theGrid, Size);
	}
    void ChessBoard::MarkNextLegalMoves(ChessSquare currentCell, int id)
	{
		myChessGame.MarkNextLegalMoves(currentCell, lGrid, Size);
	}

    void ChessBoard::CleartheBoard()
	{
		myChessGame.ClearBoard(theGrid,Size);
	}