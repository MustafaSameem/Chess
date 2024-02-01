#include "Piece.h"
#include <math.h>
#include <iostream>
using std::cout;
using std::endl;
#include <algorithm>
using std::min;
using std::max;



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

bool Pawn::move(Board board, Square &start, Square &end) {
    //Check if the destination square has the player's own piece
    if (end.getPiece() != nullptr && end.getPiece()->getIsWhite() == start.getPiece()->getIsWhite()){
        cout << "Your own piece is there\n";
        return false;
    }
    int deltaX = end.getX() - start.getX();
    int deltaY = end.getY() - start.getY();
    //White pawn functionality
    if(start.getPiece()->getIsWhite()){
        //Check valididity of position
        if(deltaY < 1 || deltaY > 2){
            cout << "White pawn cannot perform this move" << endl;
            return false;
        }
        //Check if it is first turn
        if(start.getY() != 1 && deltaY == 2){
            cout << "Cannot move 2 squares if not in starting position" << endl;
            return false;
        }
        //Check if a piece blocking the way
        if(deltaX == 0){
            for(int y=start.getY()+1; y<=end.getY(); y++){
                if (board.getSquare(start.getX(),y)->getPiece() != nullptr){
                    cout << "There is a piece in [" << start.getX() << "," << y << "] blocking the way" << endl;
                    return false;
                }
            }
        }
        //Check if pawn can capture
        if(deltaY == 1 && deltaX == -1 || deltaX == 1){
            if(board.getSquare(end.getX(), end.getY())->getPiece() == nullptr){
                cout << "No pieces to capture" << endl;
                return false;
            }
        }
    }
    //Black pawn functionality
    else if(!start.getPiece()->getIsWhite()){
        //Check valididity of position
        if(deltaY < -2 || deltaY > -1){
            cout << "Black pawn cannot perform this move" << endl;
            return false;
        }
    }
    //Check if it is first turn
    if(start.getY() != 6 && deltaY == -2){
        cout << "Cannot move 2 squares if not in starting position" << endl;
        return false;
    }
    //Check if a piece blocking the way
    if(deltaX == 0){
        for(int y=start.getY()-1; y>=end.getY(); y--){
            if (board.getSquare(start.getX(),y)->getPiece() != nullptr){
                cout << "There is a piece in [" << start.getX() << "," << y << "] blocking the way" << endl;
                return false;
            }
        }
    }
    //Check if a pawn can capture
    if(deltaY == -1 && deltaX == -1 || deltaX == 1){
        if(board.getSquare(end.getX(), end.getY())->getPiece() == nullptr){
            cout << "No pieces to capture" << endl;
            return false;
        }
    }
    //All conditions passed
    cout << "VALID PAWN MOVE" << endl;
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

bool Knight::move(Board board, Square &start, Square &end) {
    //Check if the destination square has the player's own piece
    if (end.getPiece() != nullptr && end.getPiece()->getIsWhite() == start.getPiece()->getIsWhite()){
        cout << "Your own piece is there\n";
        return false;
    }
    //Check validity of position
    int deltaX = abs(start.getX() - end.getX());
    int deltaY = abs(start.getY() - end.getY());
    if (deltaX * deltaY == 2){
        cout << "VALID KNIGHT MOVE\n";
        return true;
    }
    else{
        cout << "INVALID KNIGHT MOVE\n";
        return false;
    }
}

// -------------------------- ROOK --------------------------------
//constructor
Rook::Rook(bool isWhite) : Piece(isWhite) {}

char Rook::getType() const {
    if (this->getIsWhite())
        return 'R';
    else
        return 'r';
}

bool Rook::move(Board board, Square &start, Square &end) {
    //Check if the destination square has the player's own piece
    if (end.getPiece() != nullptr && end.getPiece()->getIsWhite() == start.getPiece()->getIsWhite()){
        cout << "Your own piece is there\n";
        return false;
    }
    //Check validity of position
    int deltaX = abs(start.getX() - end.getX());
    int deltaY = abs(start.getY() - end.getY());
    if (deltaX * deltaY != 0){
        cout << "INVALID ROOK MOVE\n";
        return false;
    }
    //Check if there is a piece blocking the way vertically
    if (start.getX() == end.getX()){
        //Assign loop order from smallest to biggest
        int startColumn = min(start.getY(), end.getY());
        int endColumn = max(start.getY(), end.getY());
        for (int y=startColumn+1; y<endColumn; y++){
            if (board.getSquare(start.getX(),y)->getPiece() != nullptr){
                cout << "There is a piece in [" << start.getX() << "," << y << "] blocking the way" << endl;
                return false;
            }
        }
    }
    //Check if there is a piece blocking the way horizontally
    else if (start.getY() == end.getY()){
        //Assign loop order from smallest to biggest
        int startRow = min(start.getX(), end.getX());
        int endRow = max(start.getX(), end.getX());
        for (int x=startRow+1; x<endRow; x++){
            if (board.getSquare(x,start.getY())->getPiece() != nullptr){
                cout << "There is a piece in [" << x <<"," << start.getY() << "] blocking the way" << endl;
                return false;
            }
        }
    }
    else{
        cout << "INVALID ROOK MOVE - must move horizontally or vertically" << endl;
        return false;
    }
    //All conditions passed
    cout << "VALID ROOK MOVE\n";
    return true;
}

// -------------------------- Bishop --------------------------------
//constructor
Bishop::Bishop(bool isWhite) : Piece(isWhite) {}

char Bishop::getType() const {
    if (this->getIsWhite())
        return 'B';
    else
        return 'b';
}

bool Bishop::move(Board board, Square &start, Square &end) {
    //Check if the destination square has the player's own piece
    if (end.getPiece() != nullptr && end.getPiece()->getIsWhite() == start.getPiece()->getIsWhite()){
        cout << "Your own piece is there\n";
        return false;
    }
    //Check validity of position
    int deltaX = end.getX() - start.getX();
    int deltaY = end.getY() - start.getY();
    if (abs(deltaX) != abs(deltaY)){
        cout << "INVALID BISHOP MOVE\n";
        return false;
    }
    //Determine the direction of movement
    int stepX = (deltaX > 0) ? 1 : -1;
    int stepY = (deltaY > 0) ? 1 : -1;
    //Check for pieces blocking the way along the diagonal
    for (int x = start.getX()+stepX, y = start.getY()+stepY; x != end.getX(); x += stepX, y += stepY) {
        if (board.getSquare(x, y)->getPiece() != nullptr) {
            cout << "There is a piece in [" << x << "," << y << "] blocking the way" << endl;
            return false;
        }
    }
    //All conditions passed
    cout << "VALID BISHOP MOVE\n";
    return true;
}

// -------------------------- QUEEN --------------------------------
//constructor
Queen::Queen(bool isWhite) : Piece(isWhite) {}

char Queen::getType() const {
    if (this->getIsWhite())
        return 'Q';
    else
        return 'q';
}

bool Queen::move(Board board, Square& start, Square& end)  {
    //Check if the destination square has the player's own piece
    if (end.getPiece() != nullptr && end.getPiece()->getIsWhite() == start.getPiece()->getIsWhite()) {
        std::cout << "Your own piece is there\n";
        return false;
    }
    //Check the validity of the move (rook + bishop movements)
    int deltaX = abs(start.getX() - end.getX());
    int deltaY = abs(start.getY() - end.getY());
    if ((deltaX * deltaY != 0) && (abs(deltaX) != abs(deltaY))) {
        cout << "INVALID QUEEN MOVE - must move horizontally, vertically, or diagonally" << endl;
        return false;
    }
    //Check if there is a piece blocking the way either vertically, horizontally, or diagonally
    //Rook movement
    if (deltaX * deltaY == 0) {
        if (start.getX() == end.getX()) {
            //Vertical movement
            int startColumn = min(start.getY(), end.getY());
            int endColumn = max(start.getY(), end.getY());
            for (int y = startColumn + 1; y < endColumn; y++) {
                if (board.getSquare(start.getX(), y)->getPiece() != nullptr) {
                    cout << "There is a piece in [" << start.getX() << "," << y << "] blocking the way" << endl;
                    return false;
                }
            }
        } else if (start.getY() == end.getY()) {
            //Horizontal movement
            int startRow = min(start.getX(), end.getX());
            int endRow = max(start.getX(), end.getX());
            for (int x = startRow + 1; x < endRow; x++) {
                if (board.getSquare(x, start.getY())->getPiece() != nullptr) {
                    cout << "There is a piece in [" << x << "," << start.getY() << "] blocking the way" << endl;
                    return false;
                }
            }
        }
    }
    //Bishop movement
    else {
        int deltaXMagnitude = end.getX() - start.getX();
        int deltaYMagnitude = end.getY() - start.getY();
        int stepX = (deltaXMagnitude > 0) ? 1 : -1;
        int stepY = (deltaYMagnitude > 0) ? 1 : -1;
        //Check for pieces blocking the way along the diagonal
        for (int x = start.getX() + stepX, y = start.getY() + stepY; x != end.getX(); x += stepX, y += stepY) {
            if (board.getSquare(x, y)->getPiece() != nullptr) {
                cout << "There is a piece in [" << x << "," << y << "] blocking the way" << endl;
                return false;
            }
        }
    }
    //All conditions passed
    cout << "VALID QUEEN MOVE\n";
    return true;
}

// -------------------------- KING --------------------------------
//constructor
King::King(bool isWhite) : Piece(isWhite) {}

char King::getType() const {
    if(this->getIsWhite())
        return '$';
    else
        return '%';
}

bool King::move(Board board, Square &start, Square &end) {
    //Check if the destination square has the player's own piece
    if (end.getPiece() != nullptr && end.getPiece()->getIsWhite() == start.getPiece()->getIsWhite()){
        cout << "Your own piece is there\n";
        return false;
    }
    //Check validity of position
    int deltaX = abs(start.getX() - end.getX());
    int deltaY = abs(start.getY() - end.getY());
    if (deltaX > 1 || deltaY > 1) {
        cout << "INVALID KING MOVE - can only move one square in any direction" << endl;
        return false;
    }
    //All conditions passed
    cout << "VALID KING MOVE\n";
    return true;
}

