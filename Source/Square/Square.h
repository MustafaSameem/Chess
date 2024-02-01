#pragma once
#include "../Piece/Piece.h"

//forward declaration to avoid circular dependency
class Piece;


class Square{
private:
    Piece* piece;
    int x;
    int y;

public:
    //constructors
    Square(int x, int y, Piece *piece);

    //setters
    void setX(int newX);
    void setY(int newY);
    void setPiece(Piece *newPiece);

    //getters
    int getX() const;
    int getY() const;
    Piece* getPiece() const;
};



