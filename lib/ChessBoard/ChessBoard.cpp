#include "ChessBoard.h"

  	ChessBoard::ChessBoard(int s)
	{
	  //ChessSquare* holder = new ChessSquare;
	  
		for(int i =0;i<s;i++)
		{
			for(int j =0;j<s;j++)
			{
				//Create i'th row
				AddSquare(Origin, j, i);
			}
		}
	}

	ChessSquare* ChessBoard::ReturnOrigin()
	{
		return Origin;
	}

