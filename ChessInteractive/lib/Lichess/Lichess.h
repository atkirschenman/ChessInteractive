#ifndef ONLINECHESS_H
#define ONLINECHESS_H
#include "ChessSquare.h"
class LichessGame
{

LichessGame(char* token);
char NumToChar(int column);

char* SendMove(ChessSquare* from, ChessSquare* to);

char* StartGame(char[* OpponentID);



};

#endif