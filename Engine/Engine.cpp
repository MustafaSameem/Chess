#include "Engine.h"

#include <iostream>
using std::cout;

//constructor
Engine::Engine(Player &player1, Player &player2, Board board, Player &playerTurn) {
    players[0] = &player1;
    players[1] = &player2;
    this->board = board;
    this->playerTurn = &playerTurn;
}

bool Engine::makeMove(Player &activePlayer, int startX, int startY, int endX, int endY) {
    Square* start = board.getSquare(startX, startY);
    Square* end = board.getSquare(endX, endY);
    Move* activeMove = new Move(activePlayer, *start, *end);

    if(playerTurn != &activePlayer){
        cout << "Not the player's turn\n";
        return false;
    }

    if(activeMove->getStartSquare()->getPiece() == nullptr){
        cout << "No piece in selected start square\n";
        return false;
    }



}

