#include "Engine.h"

#include <iostream>
using std::cout;
using std::endl;

//constructor
Engine::Engine(Player &player1, Player &player2, Board board, Player &playerTurn){
    players[0] = &player1;
    players[1] = &player2;
    this->board = board;
    this->playerTurn = &playerTurn;
}

bool Engine::makeMove(Player &activePlayer, int startX, int startY, int endX, int endY){

    Square *start = board.getSquare(startX, startY);
    Square *end = board.getSquare(endX, endY);
    Move *activeMove = new Move(activePlayer, *start, *end);
    Piece *activePiece = activeMove->getStartSquare()->getPiece();

    //check if it is the player's turn
    if (playerTurn != &activePlayer){
        cout << "Not the player's turn\n";
        return false;
    }
    //check if a piece exists in the start square
    if (activePiece == nullptr){
        cout << "No piece in selected start square\n";
        return false;
    }
    //check if the player and piece color match
    if (activePlayer.getIsWhitePlayer() != activePiece->getIsWhite()){
        cout << "Player and piece color do not match\n";
        return false;
    }
    //perform move
    if (start->getPiece()->move(board, *start, *end)) {
        //Instead of deleting the memory content and performing a deep copy, simply move the pointers to point
        //to the right memory address where the piece is located and set the other one to null

        //make the end pointer, point to where the piece is located in heap memory using the start pointer
        end->setPiece(start->getPiece());
        //set start.piece to nullptr
        start->setPiece(nullptr);

        //switch player turn
        if(playerTurn == players[0]){
            playerTurn = players[1];
        }
        else
            playerTurn = players[0];

        return true;
    }
    else
        return false;

}

