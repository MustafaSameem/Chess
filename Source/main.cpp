#include <SFML/Graphics.hpp>
#include <vector>
using std::vector;
#include <iostream>
using std::endl;
using std::cout;

#include "Square/Square.h"
#include "Board/Board.h"
#include "Player/Player.h"
#include "Move/Move.h"
#include "Engine/Engine.h"

int main() {

    // BACKEND
    Player* p1 = new Human(true, true);
    Player* p2 = new Human(true, false);
    Board board;
    Engine engine(*p1, *p2, board, *p1);


    // FRONT END
    // Create the window
    sf::RenderWindow window(sf::VideoMode(800, 800), "Chessboard Window");
    // CHESSBOARD
    sf::Texture chessboardTexture;
    if (!chessboardTexture.loadFromFile("../images/chessboard_own_drawing_test.png")) {
        return -1;
    }
    // Create Sprite
    sf::Sprite chessboardSprite(chessboardTexture);
    // Define chessboard square dimensions
    const float squareSize = 800/8;


    // -------------------------- Piece Initilization ----------------------------
    // Vector to hold all pieces
    std::vector<sf::Sprite> pieces;
    // Vector to store the position of all pieces
    std::vector<sf::Vector2f> piecePosition(32);

    //Initialize textures
    sf::Texture rookTexture;
    sf::Texture knightTexture;
    sf::Texture bishopTexture;
    sf::Texture queenTexture;
    sf::Texture kingTexture;
    sf::Texture pawnTexture;

    //LOAD textures
    if (!rookTexture.loadFromFile("../images/white_rook.png")) {
        return -1;
    }
    if (!knightTexture.loadFromFile("../images/white_knight.png")) {
        return -1;
    }
    if (!bishopTexture.loadFromFile("../images/white_bishop.png")) {
        return -1;
    }
    if (!queenTexture.loadFromFile("../images/white_queen.png")) {
        return -1;
    }
    if (!pawnTexture.loadFromFile("../images/white_pawn.png")) {
        return -1;
    }
    //Load in order from bottom left corner
    //white pieces
    pieces.resize(1, sf::Sprite(rookTexture));
    pieces.resize(2, sf::Sprite(knightTexture));
    pieces.resize(3, sf::Sprite(bishopTexture));
    pieces.resize(5, sf::Sprite(queenTexture));
    pieces.resize(6, sf::Sprite(bishopTexture));
    pieces.resize(7, sf::Sprite(knightTexture));
    pieces.resize(8, sf::Sprite(rookTexture));
    pieces.resize(16, sf::Sprite(pawnTexture));
    //black pieces
    pieces.resize(24, sf::Sprite(pawnTexture));
    pieces.resize(25, sf::Sprite(rookTexture));
    pieces.resize(26, sf::Sprite(knightTexture));
    pieces.resize(27, sf::Sprite(bishopTexture));
    pieces.resize(29, sf::Sprite(queenTexture));
    pieces.resize(30, sf::Sprite(bishopTexture));
    pieces.resize(31, sf::Sprite(knightTexture));
    pieces.resize(32, sf::Sprite(rookTexture));


    // Set initial positions for WHITE pieces
    for(int y=0; y < 2; ++y){
        for(int x = 0; x < 8; ++x){
            float xPos = 100 * x + 3.5;
            float yPos = 705 - (100 * y);
            pieces[(y*8) + x].setPosition(xPos, yPos);
            pieces[(y*8) + x].setScale(0.18, 0.18);
            // Store the initial position in the vector
            piecePosition[(y * 8) + x] = sf::Vector2f(xPos, yPos);
        }
    }

    // Set initial positions for BLACK pieces
    for(int y=6; y < 8; ++y){
        for(int x = 0; x < 8; ++x){
            float xPos = 100 * x + 3.5;
            float yPos = 705 - (100 * y);
            //((y*8)-32) is because we are loading the 16 position piece instead of iterating through every square
            pieces[((y*8)-32) + x].setPosition(xPos, yPos);
            pieces[((y*8)-32) + x].setScale(0.18, 0.18);
            // Store the initial position in the vector
            piecePosition[((y * 8) - 32) + x] = sf::Vector2f(xPos, yPos);
            //set color
            sf::Color grey(70,70,70);
            pieces[((y*8)-32) + x].setColor(grey);
        }
    }


    // -------------------------- Dragging Functionality ----------------------------
    int turnCounter =0;
    // Variables for dragging
    bool isDraggingPiece = false;
    int draggedPieceIndex = -1;  // Initialize to an invalid index
    sf::Vector2f pieceOffset; // Offset between mouse click and the top-left corner of the pawn

    // Main loop
    while (window.isOpen()) {
        sf::Event event;
        while (window.pollEvent(event)) {
            switch (event.type) {

                case sf::Event::Closed:
                    window.close();
                    break;

                case sf::Event::MouseButtonPressed:
                    if (event.mouseButton.button == sf::Mouse::Left) {
                        sf::Vector2f mousePosition = window.mapPixelToCoords(sf::Mouse::getPosition(window));

                        // Check if the mouse is pressed on any pawn
                        for (int i=0; i < pieces.size(); ++i) {
                            if (pieces[i].getGlobalBounds().contains(mousePosition)) {
                                isDraggingPiece = true;
                                draggedPieceIndex = i;
                                pieceOffset = pieces[i].getPosition() - mousePosition;
                                break; // No need to check other pawns once one is found
                            }
                        }
                    }
                    break;

                case sf::Event::MouseMoved:
                    if (isDraggingPiece && draggedPieceIndex >= 0 && draggedPieceIndex < pieces.size()) {
                        sf::Vector2f mousePosition = window.mapPixelToCoords(sf::Mouse::getPosition(window));
                        // Update position only for the dragged pawn
                        pieces[draggedPieceIndex].setPosition(mousePosition + pieceOffset);

                        // Draw a highlight on the square where the mouse is
                        sf::Vector2i gridPosition(mousePosition.x / squareSize, mousePosition.y / squareSize);
                        sf::RectangleShape highlight(sf::Vector2f(squareSize, squareSize));
                        highlight.setPosition(gridPosition.x * squareSize, gridPosition.y * squareSize);
                        highlight.setFillColor(sf::Color(255, 255, 255, 100));

                        window.clear();
                        window.draw(chessboardSprite);
                        window.draw(highlight);

                        // Draw all the pawns after the highlight
                        for (const auto& pawn : pieces) {
                            window.draw(pawn);
                        }
                        window.display();
                    }
                    break;

                case sf::Event::MouseButtonReleased:
                    if (event.mouseButton.button == sf::Mouse::Left) {
                        if (isDraggingPiece && draggedPieceIndex >= 0 && draggedPieceIndex < pieces.size()) {
                            // Calculate the center of the highlighted square
                            sf::Vector2i gridPosition(
                                    static_cast<int>((pieces[draggedPieceIndex].getPosition().x + squareSize / 2) / squareSize),
                                    static_cast<int>((pieces[draggedPieceIndex].getPosition().y + squareSize / 2) / squareSize)
                            );
                            //Map pixel coodinate to Board x,y coordinate
                            int startX = (piecePosition[draggedPieceIndex].x - 3.5) / 100;
                            int startY = 7 - (piecePosition[draggedPieceIndex].y - 5) / 100;
                            int endX = gridPosition.x;
                            int endY = 7 - gridPosition.y;

                            // Check if there's a piece at the destination
                            bool isCapture = board.getSquare(endX, endY)->getPiece() != nullptr;

                            //If even: p1 turn, if odd: p2 turn
                            Player& currentPlayer = (turnCounter % 2 == 0) ? *p1 : *p2;
                            //if invalid position return pawn to its intialPawnPosition
                            if(!engine.makeMove(currentPlayer, startX, startY, endX, endY)){
                                pieces[draggedPieceIndex].setPosition(piecePosition[draggedPieceIndex]);
                            }
                            else{
                                // If a capture occurred, find the captured piece and remove it
                                if (isCapture) {
                                    int capturedPieceIndex = -1;
                                    sf::Vector2f capturedPiecePosition((endX * 100) + 3.5, 705 - (endY * 100));

                                    for (int i = 0; i < pieces.size(); i++) {
                                        if (piecePosition[i] == capturedPiecePosition) {
                                            capturedPieceIndex = i;
                                            //vector is resized when .erase() is called so must decrease index by one to match actual dragged piece
                                            if (draggedPieceIndex >= i){
                                                draggedPieceIndex--;
                                            }
                                            break;
                                        }
                                    }
                                    // Remove the captured piece (vector resized)
                                    if (capturedPieceIndex != -1) {
                                        pieces.erase(pieces.begin() + capturedPieceIndex);
                                        piecePosition.erase(piecePosition.begin() + capturedPieceIndex);
                                    }
                                }
                                // Set the pawn's position to the center of the highlighted square
                                pieces[draggedPieceIndex].setPosition((gridPosition.x * squareSize) + 3.5, (gridPosition.y * squareSize) + 5);
                                cout << "[" << endX << "," << endY << "]" << endl;
                                // Update initialPawnPosition of the dragged pawn to its new position
                                piecePosition[draggedPieceIndex] = pieces[draggedPieceIndex].getPosition();
                                // Turn ends, increase counter
                                turnCounter++;
                            }
                        }

                        // Reset dragging state
                        isDraggingPiece = false;
                        draggedPieceIndex = -1;
                    }
                    break;

                default:
                    break;
            }
        }

        // Draw chessboard and pawns when not dragging
        if (!isDraggingPiece) {
            window.clear();
            window.draw(chessboardSprite);

            // Draw all the pawns after the highlight
            for (const auto& pawn : pieces) {
                window.draw(pawn);
            }

            window.display();
        }
    }

    return 0;
}
