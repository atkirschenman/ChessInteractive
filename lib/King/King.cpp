#include "King.h"

 void MarkNextLegalMoves(ChessSquare* Origin, ChessSquare* currentCell)
 {

    if (currentCell->RowNumber + 1 <= 7 && currentCell->ColumnNumber + 1 <= 7 &&
        !FindSquare(Origin,currentCell->RowNumber + 1, currentCell->ColumnNumber + 1)->CurrentlyOccupied)
        FindSquare(Origin,currentCell->RowNumber + 1, currentCell->ColumnNumber + 1)->LegalNextMove = true;

    if (currentCell->RowNumber + 1 <= 7 && currentCell->ColumnNumber - 1 >= 0 && !FindSquare(Origin,currentCell->RowNumber + 1, currentCell->ColumnNumber - 1)->CurrentlyOccupied)
        FindSquare(Origin,currentCell->RowNumber + 1, currentCell->ColumnNumber - 1)->LegalNextMove = true;

    if (currentCell->RowNumber - 1 >= 0 && currentCell->ColumnNumber + 1 <= 7 && !FindSquare(Origin,currentCell->RowNumber - 1, currentCell->ColumnNumber + 1)->CurrentlyOccupied)
        FindSquare(Origin,currentCell->RowNumber - 1, currentCell->ColumnNumber + 1)->LegalNextMove = true;

    if (currentCell->RowNumber - 1 >= 0 && currentCell->ColumnNumber - 1 >= 0 && !FindSquare(Origin,currentCell->RowNumber - 1, currentCell->ColumnNumber - 1)->CurrentlyOccupied)
        FindSquare(Origin,currentCell->RowNumber - 1, currentCell->ColumnNumber - 1)->LegalNextMove = true;

    if (currentCell->ColumnNumber + 1 <= 7 && !FindSquare(Origin,currentCell->RowNumber, currentCell->ColumnNumber + 1)->CurrentlyOccupied)
        FindSquare(Origin,currentCell->RowNumber, currentCell->ColumnNumber + 1)->LegalNextMove = true;

    if (currentCell->ColumnNumber - 1 >= 0 && !FindSquare(Origin,currentCell->RowNumber, currentCell->ColumnNumber - 1)->CurrentlyOccupied)
        FindSquare(Origin,currentCell->RowNumber, currentCell->ColumnNumber - 1)->LegalNextMove = true;

    if (currentCell->RowNumber - 1 >= 0 && !FindSquare(Origin,currentCell->RowNumber - 1, currentCell->ColumnNumber)->CurrentlyOccupied)
        FindSquare(Origin,currentCell->RowNumber - 1, currentCell->ColumnNumber)->LegalNextMove = true;

    if (currentCell->RowNumber + 1 <= 7 && !FindSquare(Origin,currentCell->RowNumber + 1, currentCell->ColumnNumber)->CurrentlyOccupied)
        FindSquare(Origin,currentCell->RowNumber + 1, currentCell->ColumnNumber)->LegalNextMove = true;
 }