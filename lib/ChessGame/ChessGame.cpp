#include "ChessGame.h"

    ChessGame::ChessGame()
    {
       Origin = ClassicBoard->ReturnOrigin();

    }
    void ChessGame::ClearLegalMoves(int Size)
    {
        for(int i =0; i<Size;i++)
        {
            for(int j = 0; j<Size;j++)
            {
               ChessSquare* temp = FindSquare(Origin, i,j);
               if (temp!=nullptr)
                temp->LegalNextMove=0;
            }
        }
    }
    void MarkNextLegalMoves(ChessSquare* currentSquare)
    {
        currentSquare->OccupiedPiece->
    }
    void SetupBoard(ChessSquare * origin, int Size)
    {

    }