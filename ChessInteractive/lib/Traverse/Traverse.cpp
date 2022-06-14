#include "Traverse.h"

//Must Create 0th column first before adding rows
int AddSquare(ChessSquare* Head, int x, int y)
{
    ChessSquare* walker = Head;
    if (walker->ColumnNumber==x &&walker->RowNumber==y)
    {
        //Serial.println("alreadyCreated");
        return -1;
    }
       
    ChessSquare* newSquare = new ChessSquare;
    newSquare->ColumnNumber=x;
    newSquare->RowNumber=y;
    //Right
    newSquare->Right = FindSquare(walker, x+1, y);
    if(newSquare->Right!=nullptr)
        newSquare->Right->Left=newSquare;
    //Left
    newSquare->Left = FindSquare(walker, x-1, y);
    if(newSquare->Left!=nullptr)
        newSquare->Left->Right = newSquare;
    //Up
    newSquare->Up = FindSquare(walker, x, y+1);
    if(newSquare->Up!=nullptr)
        newSquare->Up->Down=newSquare;
    //Down
    newSquare->Down = FindSquare(walker, x, y-1);
    if(newSquare->Down!=nullptr)
        newSquare->Down->Up=newSquare;
}

ChessSquare* FindSquare(ChessSquare* Head, int x, int y)
{
    ChessSquare* walker=Head;

       while(walker->RowNumber!=y)
    {
        if (walker->Down==nullptr)
            return nullptr;
        walker = walker->Down;
    }
    while(walker->ColumnNumber!=x) 
    {
        if (walker->Right==nullptr)
            return nullptr;
        walker = walker->Right;
    }


    if (walker->RowNumber==y && walker->ColumnNumber==x)
        return walker;
    else
        return nullptr;
     
}