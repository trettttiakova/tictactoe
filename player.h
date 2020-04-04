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
    bool bot = false;
public:
    player(char character);
    void move(board * brd);
    char get_character();
    void set_bot();
};


#endif //TICTACTOE_PLAYER_H