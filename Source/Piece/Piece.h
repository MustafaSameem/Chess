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
    virtual bool move(Board board, Square &start, Square &end) = 0;
    virtual char getType() const = 0;
};


// -------------------------- PAWN --------------------------------
class Pawn : public Piece{
public:
    //constructor
    Pawn(bool isWhite);
    //methods
    bool move(Board board, Square &start, Square &end) override;
    char getType() const override;
};

// -------------------------- KNIGHT --------------------------------
class Knight : public Piece{
public:
    //constructor
    Knight(bool isWhite);
    //methods
    bool move(Board board, Square &start, Square &end) override;
    char getType() const override;
};

// -------------------------- ROOK --------------------------------
class Rook : public Piece{
public:
    //constructor
    Rook(bool isWhite);
    //methods
    bool move(Board board, Square &start, Square &end);
    char getType() const override;
};

// -------------------------- BISHOP --------------------------------
class Bishop : public Piece{
public:
    //constructor
    Bishop(bool isWhite);
    //methods
    bool move(Board board, Square &start, Square &end) override;
    char getType() const override;
};

// -------------------------- QUEEN --------------------------------
class Queen : public Piece{
public:
    //constructor
    Queen(bool isWhite);
    //methods
    bool move(Board board, Square &start, Square &end) override;
    char getType() const override;
};

// -------------------------- KING --------------------------------
class King : public Piece{
public:
    //constructor
    King(bool isWhite);
    //methods
    bool move(Board board, Square &start, Square &end) override;
    char getType() const override;
};
















