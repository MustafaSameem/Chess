#include "Square.h"
#include "../Piece/Piece.h"
#include <iostream>
using std::cout;
using std::endl;

//constructor
Square::Square(int x, int y, Piece* piece) {
    this->x = x;
    this->y = y;
    this->piece = piece;
}
//destructor

//setter
void Square::setX(int newX) {
    this->x = newX;
}
void Square::setY(int newY){
    this->y = newY;
}
void Square::setPiece(Piece *newPiece){
    this->piece = newPiece;
}

//getter
int Square::getX() const{
    return x;
}
int Square::getY() const{
    return y;
}
Piece* Square::getPiece() const{
    return piece;
}




