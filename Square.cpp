//
// Created by musta on 2023-12-22.
//

#include "Square.h"
#include "Piece.h"
#include <iostream>
using namespace std;

Square::Square() {
    this->x = 99;
    this->y = 99;
    this-> piece = nullptr;
}

Square::Square(int x, int y, Piece* piece) {
        this->x = x;
        this->y = y;
        this->piece = piece;
    }

void Square::setX(int newX) {
        this->x = newX;
    }


void Square::setY(int newY){
        this->y = newY;
    }
void Square::setPiece(Piece *newPiece){
        this->piece = newPiece;
    }

int Square::getX() const{
        return x;
    }
int Square::getY() const{
        return y;
    }
Piece* Square::getPiece() const{
        return piece;
    }



Board::Board() {

    for (int i = 0; i < 8; ++i) {
        for (int j = 0; j < 8; ++j) {
            location[i][j] = new Square();
        }
    }

    location[0][0] = new Square(0,0, new Knight(true));
    location[0][1] = new Square(0,1, new Knight(true));
    location[0][2] = new Square(0,2, new Knight(true));
    location[0][3] = new Square(0,3, new Knight(true));
    location[0][4] = new Square(0,4, new Knight(true));
    location[0][5] = new Square(0,5, new Knight(true));
    location[0][6] = new Square(0,6, new Knight(true));
    location[0][7] = new Square(0,7, new Knight(true));
}

void Board::display() {
    for(int i=7; i >= 0; i--){
        for(int j=7; j >= 0; j--){
            Piece *piece = location[i][j]->getPiece();
            if(piece){
                cout << piece->getType() << " ";
            }
            else
                cout << "e ";
        }
        cout << endl;
    }
}
