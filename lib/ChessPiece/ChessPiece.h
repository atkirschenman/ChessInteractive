#ifndef CP_H
#define CP_H

class ChessPiece
{
    public:
        unsigned int ID;
        bool Color;
        bool InPlay;

        enum ChessPieceEnum{
            PAWN,
            KNIGHT,
            BISHOP,
            ROOK,
            QUEEN,
            KING};

        ChessPiece(bool lcolor, ChessPieceEnum lid);
};


#endif