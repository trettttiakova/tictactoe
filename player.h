//
// Created by Zoe Tretiakova on 2020-04-04.
//

#ifndef TICTACTOE_PLAYER_H
#define TICTACTOE_PLAYER_H

#include <iostream>
#include "board.h"

class player {
private:
    char character;
public:
    player(char character);
    void move(board * brd);
    char get_character();
};


#endif //TICTACTOE_PLAYER_H
