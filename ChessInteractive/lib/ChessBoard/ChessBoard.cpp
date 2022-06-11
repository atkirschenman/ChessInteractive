#include "ChessBoard.h"



    ChessBoard::ChessBoard(int s)
	{
	 static ChessSquare* origin = new ChessSquare;
		
		for(int i =0;i<s;i++)
		{

			//Create 0th Column
			AddSquare(origin, 0,i);

			for(int j =0;i<s;i++)
			{
				//Create ith row
				AddSquare(origin, i, j);
			}
		}

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