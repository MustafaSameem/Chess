#include "Square.h"
#include "../Piece/Piece.h"

//constructor
Square::Square() {
    this->x = 99;
    this->y = 99;
    this->piece = nullptr;
}

Square::Square(int x, int y, Piece* piece) {
    this->x = x;
    this->y = y;
    this->piece = piece;
}

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




