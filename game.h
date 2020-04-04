//
// Created by Zoe Tretiakova on 2020-04-04.
//

#ifndef TICTACTOE_GAME_H
#define TICTACTOE_GAME_H

#include <fstream>
#include "board.h"
#include "player.h"

class game {
private:
    player player1, player2;
    void round(int size);
    std::ofstream out;
public:
    game() : player1('x'), player2('o') {};
    void start();
};


#endif //TICTACTOE_GAME_H