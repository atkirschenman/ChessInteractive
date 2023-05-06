#include "Rook.h"


 void MarkNextLegalMoves(ChessSquare* Origin, ChessSquare* currentCell)
 {
    for (int i = currentCell->RowNumber + 1; i <= 7; i++)
    {
        if (FindSquare(Origin, i, currentCell->ColumnNumber)->CurrentlyOccupied)
        {
            if(FindSquare(Origin,i, currentCell->ColumnNumber)->OccupiedPiece->Color!= FindSquare(Origin,currentCell->RowNumber, currentCell->ColumnNumber)->OccupiedPiece->Color)
            {
                FindSquare(Origin,i, currentCell->ColumnNumber)->LegalNextMove = true;
                break;
            }
            else
                break;
        }
            
        FindSquare(Origin,i, currentCell->ColumnNumber)->LegalNextMove = true;
    }
    for (int i = currentCell->RowNumber - 1; i >= 0; i--)
    {
        if (FindSquare(Origin,i, currentCell->ColumnNumber)->CurrentlyOccupied)
        {
            if (FindSquare(Origin,i, currentCell->ColumnNumber)->OccupiedPiece->Color != FindSquare(Origin,currentCell->RowNumber, currentCell->ColumnNumber)->OccupiedPiece->Color)
            {
                FindSquare(Origin,i, currentCell->ColumnNumber)->LegalNextMove = true;
                break;
            }
            else
                break;
        }
        FindSquare(Origin,i, currentCell->ColumnNumber)->LegalNextMove = true;
    }
    for (int i = currentCell->ColumnNumber + 1; i <= 7; i++)
    {
        if (FindSquare(Origin,currentCell->RowNumber, i)->CurrentlyOccupied)
        {
            if (FindSquare(Origin,currentCell->RowNumber, i)->OccupiedPiece->Color != FindSquare(Origin,currentCell->RowNumber, currentCell->ColumnNumber)->OccupiedPiece->Color)
            {
                FindSquare(Origin,currentCell->RowNumber, i)->LegalNextMove = true;
                break;
            }
            else
                break;
        }
        FindSquare(Origin,currentCell->RowNumber, i)->LegalNextMove = true;
    }
    for (int i = currentCell->ColumnNumber - 1; i >= 0; i--)
    {
        if (FindSquare(Origin,currentCell->RowNumber, i)->CurrentlyOccupied)
        {
            if (FindSquare(Origin,currentCell->RowNumber, i)->OccupiedPiece->Color != FindSquare(Origin,currentCell->RowNumber, currentCell->ColumnNumber)->OccupiedPiece->Color)
            {
                FindSquare(Origin,currentCell->RowNumber, i)->LegalNextMove = true;
                break;
            }
            else
                break;
        }
            FindSquare(Origin,currentCell->RowNumber, i)->LegalNextMove = true;
    }
 }