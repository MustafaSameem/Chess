cmake_minimum_required(VERSION 3.17)
project(chess_testing2)

set(CMAKE_CXX_STANDARD 14)

# Set SFML_DIR to the path where you extracted SFML
set(SFML_DIR "C:/Dev_Mus/SFML/lib/cmake/SFML")

find_package(SFML 2.5 COMPONENTS system window graphics network audio REQUIRED)

add_executable(chess_testing2
        Source/main.cpp
        source/Square/Square.cpp
        source/Square/Square.h
        source/Piece/Piece.cpp
        source/Piece/Piece.h
        source/Board/Board.cpp
        source/Board/Board.h
        source/Player/Player.cpp
        source/Player/Player.h
        source/Engine/Engine.cpp
        source/Engine/Engine.h
        source/Move/Move.cpp
        source/Move/Move.h)

target_link_libraries(chess_testing2
        sfml-system
        sfml-window
        sfml-graphics
        sfml-network
        sfml-audio)
