#pragma once
#include "../Square/Square.h"
#include "../Board/Board.h"
#include <string>
using std::string;

//forward declaration
class Board;
class Square;

//abstract Class
class Piece{
private:
    bool isDead;
    bool isWhite;

public:
    //constructor
    Piece(bool white);
    //setter
    void setKilled(bool isDead);
    void setWhite(bool isWhite);
    //getter
    bool getIsDead() const;
    bool getIsWhite() const;
    //methods
    virtual bool move(Board board, Square start, Square end) = 0;
    virtual char getType() const = 0;
};


// -------------------------- PAWN --------------------------------
class Pawn : public Piece{
public:
    //constructor
    Pawn(bool isWhite);
    //methods
    bool move(Board board, Square start, Square end);
    char getType() const;
};













//
class Knight : public Piece{
public:
    //constructor
    Knight(bool isWhite);
    //methods
    bool move(Board board, Square start, Square end);
    char getType() const;
};
















