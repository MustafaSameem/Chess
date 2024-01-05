#include "Piece.h"
#include <iostream>
#include <math.h>
using std::cout;
using std::endl;



// -------------------------- Piece (Abstract Class) --------------------------------
//constructor
Piece::Piece(bool isWhite) {
    this->isDead = false;
    this->isWhite = isWhite;
}
//setter
void Piece::setKilled(bool isDead) {
    this->isDead = isDead;
}
void Piece::setWhite(bool isWhite) {
    this->isWhite = isWhite;
}
//getter
bool Piece::getIsDead() const {
    return isDead;
}
bool Piece::getIsWhite() const {
    return isWhite;
}


// -------------------------- PAWN --------------------------------
//constructor
Pawn::Pawn(bool isWhite) : Piece(isWhite) {}

//methods
char Pawn::getType() const {
    if(this->getIsWhite())
        return 'P';
    else
        return 'p';
}

bool Pawn::move(Square &start, Square &end) {
    if (end.getPiece()->getIsWhite() == this->getIsWhite()){
        cout << "white piece already there\n";
        return false;
    }
    return true;
}


// -------------------------- KNIGHT --------------------------------
//constructor
Knight::Knight(bool isWhite) : Piece(isWhite) {}

char Knight::getType() const {
    if(this->getIsWhite())
        return 'K';
    else
        return 'k';
}

bool Knight::move(Square &start, Square &end) {
    if (end.getPiece() != nullptr
        && end.getPiece()->getIsWhite() == start.getPiece()->getIsWhite()){
        cout << "Your own piece is there\n";
        return false;
    }
    int x = abs(start.getX() - end.getX());
    int y = abs(start.getY() - end.getY());
    if (x * y == 2){
        cout << "VALID KNIGHT MOVE\n";
        return true;
    }
    else{
        cout << x << endl;
        cout << y << endl;
        cout << x * y << endl;
        cout << "INVALID KNIGHT MOVE\n";
        return false;
    }
}

