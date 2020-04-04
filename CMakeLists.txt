cmake_minimum_required(VERSION 3.13)
project(tictactoe)

set(CMAKE_CXX_STANDARD 14)

add_executable(tictactoe main.cpp
        board.cpp board.h
        player.cpp player.h
        game.cpp game.h
        )