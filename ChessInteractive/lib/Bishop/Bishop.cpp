#include "Bishop.h"


    

    Bishop::Bishop(bool lcolor)
    {
        ID = PAWN;
        Color = lcolor;
        InPlay = true;
    }

    void  Bishop::MarkNextLegalMoves(ChessSquare* currentCell, int size)
    {   
        ChessSquare theGrid[size][size];
        theGrid[0][0]=currentCell;

        int i2 = 1;
                    while (currentCell.RowNumber + i2 <= 7 && currentCell.ColumnNumber + i2 <= 7)
                    {
                        if (theGrid[currentCell.RowNumber + i2, currentCell.ColumnNumber + i2].CurrentlyOccupied)
                        {
                            if(theGrid[currentCell.RowNumber + i2, currentCell.ColumnNumber + i2].OccupiedPiece.Color!= theGrid[currentCell.RowNumber , currentCell.ColumnNumber ].OccupiedPiece.Color)
                            {
                                theGrid[currentCell.RowNumber + i2, currentCell.ColumnNumber + i2].LegalNextMove = true;
                                break;
                            }
                            else
                                break;
                        }
                          
                        theGrid[currentCell.RowNumber + i2, currentCell.ColumnNumber + i2].LegalNextMove = true;
                        i2++;
                    }
                    i2 = 1;
                    while (currentCell.RowNumber + i2 <= 7 && currentCell.ColumnNumber - i2 >= 0)
                    {
                        if (theGrid[currentCell.RowNumber + i2, currentCell.ColumnNumber - i2].CurrentlyOccupied)
                        {
                            if (theGrid[currentCell.RowNumber + i2, currentCell.ColumnNumber - i2].OccupiedPiece.Color != theGrid[currentCell.RowNumber , currentCell.ColumnNumber ].OccupiedPiece.Color)
                            {
                                theGrid[currentCell.RowNumber + i2, currentCell.ColumnNumber - i2].LegalNextMove = true;
                                break;
                            }
                            else
                                break;
                        }
                        theGrid[currentCell.RowNumber + i2, currentCell.ColumnNumber - i2].LegalNextMove = true;
                        i2++;
                    }
                    i2 = 1;
                    while (currentCell.RowNumber - i2 >= 0 && currentCell.ColumnNumber + i2 <= 7)
                    {
                        if (theGrid[currentCell.RowNumber - i2, currentCell.ColumnNumber + i2].CurrentlyOccupied)
                        {
                            if (theGrid[currentCell.RowNumber - i2, currentCell.ColumnNumber + i2].OccupiedPiece.Color != theGrid[currentCell.RowNumber, currentCell.ColumnNumber].OccupiedPiece.Color)
                            {
                                theGrid[currentCell.RowNumber - i2, currentCell.ColumnNumber + i2].LegalNextMove = true;
                                break;
                            }
                            else
                                break;
                        }
                        theGrid[currentCell.RowNumber - i2, currentCell.ColumnNumber + i2].LegalNextMove = true;
                        i2++;
                    }
                    i2 = 1;
                    while (currentCell.RowNumber - i2 >= 0 && currentCell.ColumnNumber - i2 >= 0)
                    {
                        if (theGrid[currentCell.RowNumber - i2, currentCell.ColumnNumber - i2].CurrentlyOccupied)
                        {
                            if (theGrid[currentCell.RowNumber - i2, currentCell.ColumnNumber - i2].OccupiedPiece.Color != theGrid[currentCell.RowNumber, currentCell.ColumnNumber].OccupiedPiece.Color)
                            {
                                theGrid[currentCell.RowNumber - i2, currentCell.ColumnNumber - i2].LegalNextMove = true;
                                break;
                            }
                            else
                                break;
                        }
                        theGrid[currentCell.RowNumber - i2, currentCell.ColumnNumber - i2].LegalNextMove = true;
                        i2++;
                    }
    }