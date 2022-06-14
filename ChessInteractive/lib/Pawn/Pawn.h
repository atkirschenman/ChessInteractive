#ifndef CP_H
#define CP_H

class Pawn
{
    public:
        unsigned int ID = PAWN;
        bool Color;
        bool InPlay;

        enum ChessPieceEnum{
            PAWN,
            KNIGHT,
            BISHOP,
            ROOK,
            QUEEN,
            KING};

        Pawn(bool lcolor, ChessPieceEnum lid);
};


#endif