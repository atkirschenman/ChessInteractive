#include "ChessBoard.h"



    ChessBoard(s)
	{
	  //ChessSquare* holder = new ChessSquare;
	  
		for(int i =0;i<s;i++)
		{
			for(int j =0;j<s;j++)
			{
				//Create i'th row
				AddSquare(origin, j, i);
			}
		}

	}
    
    void SetupBoard()
	{
		myChessGame.SetupBoard(theGrid, Size);
	}
    void MarkNextLegalMoves(ChessSquare* Origin, ChessSquare* currentCell)
	{
		myChessGame.MarkNextLegalMoves(Origin,currentCell, Size);
	}

    void CleartheBoard()
	{
		myChessGame.ClearBoard(theGrid,Size);
	}