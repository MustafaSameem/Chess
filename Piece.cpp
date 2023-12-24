#include "Piece.h"
#include <iostream>
using std::cout;

Piece::Piece(bool isWhite) {
    this->killed = false;
    this->isWhite = isWhite;
}

bool Piece::getIsWhite() const{
    return isWhite;
}




Knight::Knight(bool isWhite) : Piece(isWhite) {}

char Knight::getType() const {
    return 'K';
}

void Knight::move(Board board, Square start, Square end) {
    if (end.getPiece()->getIsWhite() == this->getIsWhite()){
        return;
    }


}

