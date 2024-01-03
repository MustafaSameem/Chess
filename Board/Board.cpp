#include "Board.h"
#include <iostream>
using std::cout;
using std::endl;
using std::to_string;

Board::Board() {
    //Initialize white pieces
    location[0][0] = new Square(0,0, new Knight(true));
    location[0][1] = new Square(0,1, new Knight(true));
    location[0][2] = new Square(0,2, new Knight(true));
    location[0][3] = new Square(0,3, new Knight(true));
    location[0][4] = new Square(0,4, new Knight(true));
    location[0][5] = new Square(0,5, new Knight(true));
    location[0][6] = new Square(0,6, new Knight(true));
    location[0][7] = new Square(0,7, new Knight(true));
    //white pawns
    for(int i=0; i<8; i++){
        location[1][i] = new Square(1, i, new Pawn(true));
    }

    //Initialize black pieces
    location[7][0] = new Square(7,0, new Knight(false));
    location[7][1] = new Square(7,1, new Knight(false));
    location[7][2] = new Square(7,2, new Knight(false));
    location[7][3] = new Square(7,3, new Knight(false));
    location[7][4] = new Square(7,4, new Knight(false));
    location[7][5] = new Square(7,5, new Knight(false));
    location[7][6] = new Square(7,6, new Knight(false));
    location[7][7] = new Square(7,7, new Knight(false));
    //black pawns
    for(int i=0; i<8; i++){
        location[6][i] = new Square(1, i, new Pawn(false));
    }

    //initialize empty squares
    for(int i=2; i<6; i++){
        for(int j=0; j<8; j++){
            location[i][j] = new Square;
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
    for(int i=7; i>=0; i--){
        for(int j=0; j<8; j++){
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