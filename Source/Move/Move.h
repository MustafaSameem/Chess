#pragma once
#include "../Player/Player.h"
#include "../Square/Square.h"
#include "../Piece/Piece.h"


class Move {
private:
    Player* player;
    Square* start;
    Square* end;
    Piece* currentPiece;
    Piece* deadPiece;

public:
    //constructor
    Move(Player &player, Square &start, Square &end);

    //setter
    void setPlayer(Player &player);
    void setStartSquare(Square &start);
    void setEndSquare(Square &end);
    void setCurrentPiece(Piece &currentPiece);
    void setDeadPiece(Piece &deadPiece);

    //getter
    Player* getPlayer();
    Square* getStartSquare();
    Square* getEndSquare();
    Piece* getCurrentPiece();
    Piece* getDeadPiece();
};



