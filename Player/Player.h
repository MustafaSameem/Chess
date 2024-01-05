#pragma once

class Player {
private:
    bool isHuman;
    bool isWhitePlayer;

public:
    //constructor
    Player(bool isHuman, bool isWhitePlayer);
    //getter
    bool getIsWhitePlayer();
    //methods
    virtual void playerType() = 0;
};

class Human : public Player{
public:
    Human(bool isHuman, bool isWhitePlayer);
    void playerType() override;
};

class Computer : public Player{
public:
    Computer(bool isHuman, bool isWhitePlayer);
    void playerType() override;
};