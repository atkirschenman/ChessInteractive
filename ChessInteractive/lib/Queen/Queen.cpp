#include "Queen.h"



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