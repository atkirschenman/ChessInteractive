#include "Bishop.h"

// hello andrew
    

    Bishop::Bishop(bool lcolor)
    {
        ID = PAWN;
        Color = lcolor;
        InPlay = true;
    }


 void MarkNextLegalMoves(ChessSquare* Origin, ChessSquare* currentCell)
 { 
 
    int i2 = 1;
    while (currentCell->RowNumber + i2 <= 7 && currentCell->ColumnNumber + i2 <= 7)
    {
        if (FindSquare(Origin,currentCell->RowNumber + i2, currentCell->ColumnNumber + i2)->CurrentlyOccupied)
        {
            if(FindSquare(Origin,currentCell->RowNumber + i2, currentCell->ColumnNumber + i2)->OccupiedPiece->Color!= FindSquare(Origin,currentCell->RowNumber , currentCell->ColumnNumber )->OccupiedPiece->Color)
            {
                FindSquare(Origin,currentCell->RowNumber + i2, currentCell->ColumnNumber + i2)->LegalNextMove = true;
                break;
            }
            else
                break;
        }
            
        FindSquare(Origin,currentCell->RowNumber + i2, currentCell->ColumnNumber + i2)->LegalNextMove = true;
        i2++;
    }
    i2 = 1;
    while (currentCell->RowNumber + i2 <= 7 && currentCell->ColumnNumber - i2 >= 0)
    {
        if (FindSquare(Origin,currentCell->RowNumber + i2, currentCell->ColumnNumber - i2)->CurrentlyOccupied)
        {
            if (FindSquare(Origin,currentCell->RowNumber + i2, currentCell->ColumnNumber - i2)->OccupiedPiece->Color != FindSquare(Origin,currentCell->RowNumber , currentCell->ColumnNumber )->OccupiedPiece->Color)
            {
                FindSquare(Origin,currentCell->RowNumber + i2, currentCell->ColumnNumber - i2)->LegalNextMove = true;
                break;
            }
            else
                break;
        }
        FindSquare(Origin,currentCell->RowNumber + i2, currentCell->ColumnNumber - i2)->LegalNextMove = true;
        i2++;
    }
    i2 = 1;
    while (currentCell->RowNumber - i2 >= 0 && currentCell->ColumnNumber + i2 <= 7)
    {
        if (FindSquare(Origin,currentCell->RowNumber - i2, currentCell->ColumnNumber + i2)->CurrentlyOccupied)
        {
            if (FindSquare(Origin,currentCell->RowNumber - i2, currentCell->ColumnNumber + i2)->OccupiedPiece->Color != FindSquare(Origin,currentCell->RowNumber, currentCell->ColumnNumber)->OccupiedPiece->Color)
            {
                FindSquare(Origin,currentCell->RowNumber - i2, currentCell->ColumnNumber + i2)->LegalNextMove = true;
                break;
            }
            else
                break;
        }
        FindSquare(Origin,currentCell->RowNumber - i2, currentCell->ColumnNumber + i2)->LegalNextMove = true;
        i2++;
    }
    i2 = 1;
    while (currentCell->RowNumber - i2 >= 0 && currentCell->ColumnNumber - i2 >= 0)
    {
        if (FindSquare(Origin,currentCell->RowNumber - i2, currentCell->ColumnNumber - i2)->CurrentlyOccupied)
        {
            if (FindSquare(Origin,currentCell->RowNumber - i2, currentCell->ColumnNumber - i2)->OccupiedPiece->Color != FindSquare(Origin,currentCell->RowNumber, currentCell->ColumnNumber)->OccupiedPiece->Color)
            {
                FindSquare(Origin,currentCell->RowNumber - i2, currentCell->ColumnNumber - i2)->LegalNextMove = true;
                break;
            }
            else
                break;
        }
        FindSquare(Origin,currentCell->RowNumber - i2, currentCell->ColumnNumber - i2)->LegalNextMove = true;
        i2++;
    }
    }