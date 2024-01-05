#include <iostream>
using namespace std;
#include "Square/Square.h"
#include "Board/Board.h"
#include "Player/Player.h"
#include "Move/Move.h"



int main() {

    Player* p1 = new Human(true, true);
    Player* p2 = new Human(true, false);
    Board board;
    board.display();

    int startX = 0;
    int startY = 0;
    int endX = 2;
    int endY = 1;


    Square* start = board.getSquare(startX, startY);
    Square* end = board.getSquare(endX, endY);

    start->getPiece()->move(*start, *end);







    return 0;
}
