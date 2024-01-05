#include "Player.h"
#include <iostream>
using std::endl;
using std::cout;

//Player
Player::Player(bool isHuman, bool isWhitePlayer) {
    this->isHuman = isHuman;
    this->isWhitePlayer = isWhitePlayer;
}

bool Player::getIsWhitePlayer() {
    return isWhitePlayer;
}

// Human
Human::Human(bool isHuman, bool isWhitePlayer) : Player(isHuman, isWhitePlayer) {}

void Human::playerType() {
    cout << "I am a human player" << endl;
}

// Computer
Computer::Computer(bool isHuman, bool isWhitePlayer) : Player(isHuman, isWhitePlayer) {}

void Computer::playerType() {
    cout << "I am a computer player" << endl;
}