//
// Created by musta on 2023-12-22.
//

#ifndef CHESS_ENGINE_SQUARE_H
#define CHESS_ENGINE_SQUARE_H
#include "Piece.h"

//forward declaration to avoid circular dependency
class Piece;


class Square{
private:
    Piece* piece;
    int x;
    int y;

public:
    //constructors
    Square();
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



class Board{
private:
    Square* location[8][8];

public:
    Board();
    void display();
};






#endif //CHESS_ENGINE_SQUARE_H
