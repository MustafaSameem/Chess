#pragma once
#include "../Square/Square.h"

//Forward declaration
class Square;



class Board{
private:
    Square* location[8][8];

public:
    //constructor
    Board();
    //getter
    Square* getSquare(int x, int y);
    //methods
    void display();
};



