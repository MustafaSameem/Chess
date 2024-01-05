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
    //Piece that is being manipulated
    Piece* movingPiece = activeMove->getStartSquare()->getPiece();

    //check if it is the player's turn
    if(playerTurn != &activePlayer){
        cout << "Not the player's turn\n";
        return false;
    }
    //check is a piece exists in the start square
    if(movingPiece == nullptr){
        cout << "No piece in selected start square\n";
        return false;
    }
    //check is the player and piece color match
    if (activePlayer.getIsWhitePlayer() != movingPiece->getIsWhite()){
        cout << "Player and piece color do not match\n";
        return false;
    }




    //when all conditions checked, proceed to make move



}

