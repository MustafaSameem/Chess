#include "Move.h"

Move::Move(Player& player, Square& start, Square& end) {
    this->player = &player;
    this->start = &start;
    this->end = &end;
    this->currentPiece = start.getPiece();
    this->deadPiece = nullptr;
}

//setter
void Move::setPlayer(Player& player) {
    this->player = &player;
}
void Move::setStartSquare(Square& start) {
    this->start = &start;
}
void Move::setEndSquare(Square& end) {
    this->end = &end;
}
void Move::setCurrentPiece(Piece& currentPiece) {
    this->currentPiece = &currentPiece;
}
void Move::setDeadPiece(Piece& deadPiece) {
    this->deadPiece = &deadPiece;
}

//getter
Player* Move::getPlayer() {
    return player;
}
Square* Move::getStartSquare() {
    return start;
}
Square* Move::getEndSquare() {
    return end;
}
Piece* Move::getCurrentPiece() {
    return currentPiece;
}
Piece* Move::getDeadPiece() {
    return deadPiece;
}


