#ifndef CHESS_ENGINE_PIECE_H
#define CHESS_ENGINE_PIECE_H
#include "Square.h"
#include <string>
using std::string;

//forward declaration
class Board;
class Square;

class Piece{
private:
    bool killed;
    bool isWhite;

public:
    //Constructor
    Piece(bool isWhite);
    //Getter
    bool getIsWhite() const;
    virtual void move(Board board, Square start, Square end) = 0;
    virtual char getType() const = 0;
};



class Knight : public Piece{
public:
    Knight(bool isWhite);
    void move(Board board, Square start, Square end);
    char getType() const;
};
















#endif //CHESS_ENGINE_PIECE_H
