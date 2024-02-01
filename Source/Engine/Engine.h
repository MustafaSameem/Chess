#pragma once

#include "../Player/Player.h"
#include "../Board/Board.h"
#include "../Square/Square.h"
#include "../Move/Move.h"

#include <vector>
using std::vector;





class Engine {
private:
    Player* players[2];
    Board board;
    Player* playerTurn;
    vector<Move> recordedMoves;

public:
    //constructor
    Engine(Player& player1, Player& player2, Board board, Player& playerTurn);

    //methods
    bool makeMove(Player &activePLayer, int startX, int startY, int endX, int endY);
};



