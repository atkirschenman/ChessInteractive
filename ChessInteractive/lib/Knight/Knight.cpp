#include "Knight.h"

 void MarkNextLegalMoves(ChessSquare* Origin, ChessSquare* currentCell)
 {//right right up
    if (currentCell->RowNumber + 2 <= 7 && currentCell->ColumnNumber + 1 <= 7 &&
        (!currentCell->Right->Right->Up->CurrentlyOccupied
        || FindSquare(Origin,currentCell->RowNumber + 2, currentCell->ColumnNumber + 1)->OccupiedPiece->Color!=
        FindSquare(Origin,currentCell->RowNumber, currentCell->ColumnNumber)->OccupiedPiece->Color))
        FindSquare(Origin,currentCell->RowNumber + 2, currentCell->ColumnNumber + 1)->LegalNextMove = true;
    //right right down
    if (currentCell->RowNumber + 2 <= 7 && currentCell->ColumnNumber - 1 >= 0 &&( !FindSquare(Origin,currentCell->RowNumber + 2, currentCell->ColumnNumber - 1)->CurrentlyOccupied
        || FindSquare(Origin,currentCell->RowNumber + 2, currentCell->ColumnNumber - 1)->OccupiedPiece->Color !=
        FindSquare(Origin,currentCell->RowNumber, currentCell->ColumnNumber)->OccupiedPiece->Color))
        FindSquare(Origin,currentCell->RowNumber + 2, currentCell->ColumnNumber - 1)->LegalNextMove = true;
    //left left up
    if (currentCell->RowNumber - 2 >= 0 && currentCell->ColumnNumber + 1 <= 7 && (!FindSquare(Origin,currentCell->RowNumber - 2, currentCell->ColumnNumber + 1)->CurrentlyOccupied
        || FindSquare(Origin,currentCell->RowNumber - 2, currentCell->ColumnNumber + 1)->OccupiedPiece->Color !=
        FindSquare(Origin,currentCell->RowNumber, currentCell->ColumnNumber)->OccupiedPiece->Color))
        FindSquare(Origin,currentCell->RowNumber - 2, currentCell->ColumnNumber + 1)->LegalNextMove = true;
    //left left down
    if (currentCell->RowNumber - 2 >= 0 && currentCell->ColumnNumber - 1 >= 0 &&( !FindSquare(Origin,currentCell->RowNumber - 2, currentCell->ColumnNumber - 1)->CurrentlyOccupied
        || FindSquare(Origin,currentCell->RowNumber - 2, currentCell->ColumnNumber - 1)->OccupiedPiece->Color !=
        FindSquare(Origin,currentCell->RowNumber, currentCell->ColumnNumber)->OccupiedPiece->Color))
        FindSquare(Origin,currentCell->RowNumber - 2, currentCell->ColumnNumber - 1)->LegalNextMove = true;
    //right up up
    if (currentCell->RowNumber + 1 <= 7 && currentCell->ColumnNumber + 2 <= 7 &&( !FindSquare(Origin,currentCell->RowNumber + 1, currentCell->ColumnNumber + 2)->CurrentlyOccupied
        || FindSquare(Origin,currentCell->RowNumber + 1, currentCell->ColumnNumber +2)->OccupiedPiece->Color !=
        FindSquare(Origin,currentCell->RowNumber, currentCell->ColumnNumber)->OccupiedPiece->Color))
        FindSquare(Origin,currentCell->RowNumber + 1, currentCell->ColumnNumber + 2)->LegalNextMove = true;
    //right down down
    if (currentCell->RowNumber + 1 <= 7 && currentCell->ColumnNumber - 2 >= 0 && (!FindSquare(Origin,currentCell->RowNumber + 1, currentCell->ColumnNumber - 2)->CurrentlyOccupied
        || FindSquare(Origin,currentCell->RowNumber + 1, currentCell->ColumnNumber -2)->OccupiedPiece->Color !=
        FindSquare(Origin,currentCell->RowNumber, currentCell->ColumnNumber)->OccupiedPiece->Color))
        FindSquare(Origin,currentCell->RowNumber + 1, currentCell->ColumnNumber - 2)->LegalNextMove = true;
    //left up up
    if (currentCell->RowNumber - 1 >= 0 && currentCell->ColumnNumber + 2 <= 7 &&( !FindSquare(Origin,currentCell->RowNumber - 1, currentCell->ColumnNumber + 2)->CurrentlyOccupied
        || FindSquare(Origin,currentCell->RowNumber -1, currentCell->ColumnNumber + 2)->OccupiedPiece->Color !=
        FindSquare(Origin,currentCell->RowNumber, currentCell->ColumnNumber)->OccupiedPiece->Color))
        FindSquare(Origin,currentCell->RowNumber - 1, currentCell->ColumnNumber + 2)->LegalNextMove = true;
    //left down down
    if (currentCell->RowNumber - 1 >= 0 && currentCell->ColumnNumber - 2 >= 0 && (!FindSquare(Origin,currentCell->RowNumber - 1, currentCell->ColumnNumber - 2)->CurrentlyOccupied
        || FindSquare(Origin,currentCell->RowNumber -1, currentCell->ColumnNumber -2)->OccupiedPiece->Color !=
        FindSquare(Origin,currentCell->RowNumber, currentCell->ColumnNumber)->OccupiedPiece->Color))
        FindSquare(Origin,currentCell->RowNumber - 1, currentCell->ColumnNumber - 2)->LegalNextMove = true;

 }