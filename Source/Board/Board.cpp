#include "Board.h"
#include <iostream>
using std::cout;
using std::endl;
using std::to_string;

Board::Board() {
    //Initialize white pieces
    location[0][0] = new Square(0,0, new Rook(true));
    location[1][0] = new Square(1,0, new Knight(true));
    location[2][0] = new Square(2,0, new Bishop(true));
    location[3][0] = new Square(3,0, new Queen(true));
    location[4][0] = new Square(4,0, new King(true));
    location[5][0] = new Square(5,0, new Bishop(true));
    location[6][0] = new Square(6,0, new Knight(true));
    location[7][0] = new Square(7,0, new Rook(true));
    //white pawns
    for(int i=0; i<8; i++){
        location[i][1] = new Square(i, 1, new Pawn(true));
    }

    //Initialize black pieces
    location[0][7] = new Square(0,7, new Rook(false));
    location[1][7] = new Square(1,7, new Knight(false));
    location[2][7] = new Square(2,7, new Bishop(false));
    location[3][7] = new Square(3,7, new King(false));
    location[4][7] = new Square(4,7, new Queen(false));
    location[5][7] = new Square(5,7, new Bishop(false));
    location[6][7] = new Square(6,7, new Knight(false));
    location[7][7] = new Square(7,7, new Rook(false));
    //black pawns
    for(int i=0; i<8; i++){
        location[i][6] = new Square(i, 6, new Pawn(false));
    }

    //initialize empty squares
    for(int y=2; y<6; y++){
        for(int x=0; x<8; x++){
            location[x][y] = new Square(x, y, nullptr);
        }
    }
}

Square* Board::getSquare(int x, int y) {
    if (x < 0 || x > 7 || y < 0 || y > 7){
        string out_of_bounds = "Location: (" + to_string(x) + "," + to_string(y) + ") is out of bounds";
        throw std::out_of_range(out_of_bounds);
    }
    return location[x][y];
}



void Board::display() {

    for(int y=7; y>=0; y--){
        for(int x=0; x<8; x++){
            Piece* piece = location[x][y]->getPiece();
            if(piece){
                cout << piece->getType() << " ";
            }
            else
                cout << "* ";
        }
        cout << endl;
    }
    cout << endl;
}